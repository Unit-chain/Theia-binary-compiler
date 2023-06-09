//
// Created by Kirill Zhukov on 06.06.2023.
//

#ifndef CLASSTEST_IRCOMMANDPARSER_H
#define CLASSTEST_IRCOMMANDPARSER_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "strutils.h"
#include "errutils.h"

///@struct Command
///@brief Structure for IR command representation
///@param name - command name
///@param args contains function arguments
///@param flag command's condition flag
struct Command {
    std::string name;
    std::vector<std::string> args;
    char flag = '\0';
};

///@brief Function for parsing a command by line
///@param line is a single line of the code
Command parseCommand(const std::string& line) {
    Command command;
    std::vector<std::string> tokens = tokenize(line, '\t');
    if ((tokens.size() < 2) && tokens[0].c_str()[0] != '@') {
        std::cout << "tab should be placed before command: " << line << std::endl;
        exit(1);
    }

    std::vector<std::string> commandTokens;
    if (tokens[0].c_str()[0] != '@') [[likely]] {
        commandTokens = tokenize(tokens[1], ' ');
    } else [[unlikely]] {
        commandTokens = tokenize(tokens[0], ':');
    }

    if (!commandTokens.empty()) {
        command.name = commandTokens[0];
        for (size_t i = 1; i < commandTokens.size(); i++) {
            std::string argument = trim(commandTokens[i]);
            if (argument[0] == '@') {
                // Handling labels for branching
                command.args.push_back(argument.substr(1));
            } else {
                // checking arguments correctness
                try {
                    argument.erase(std::remove(argument.begin(), argument.end(), ','), argument.end());
                    command.args.push_back(argument);
                } catch (const std::invalid_argument&) {
                    std::cout << "Invalid argument: " << argument << std::endl;
                }
            }
        }

        std::size_t dotPos = commandTokens[0].find('.');
        if (dotPos != std::string::npos && dotPos < commandTokens[0].length() - 1) [[unlikely]] {
            std::string result = commandTokens[0].substr(dotPos + 1);  // Extract the substring after the dot
            command.flag = (char) commandTokens[0].substr(dotPos + 1)[0];
        }
    }
    return command;
}

///@brief Function for parsing code
///@param code it's source code written in IR
std::vector<Command> parseCode(const std::string& code) {
    std::vector<Command> commands;
    std::vector<std::string> lines = tokenize(code, '\n');

    for (const std::string& line : lines) {
        if (line.empty() || line[0] != '#') {
            if (line[0] == '@') [[unlikely]] {
                commands.push_back(parseCommand(line));
            }
            continue;
        }
        commands.push_back(parseCommand(line));
        size_t rpos = line.find("return");
        size_t spos = line.find("stop");
        if (rpos != std::string::npos || spos != std::string::npos) {
            return commands;
        }
    }

    return commands;
}

///@brief Function for parsing code
///@param code it's source code written in IR
///@param pos it's position in file or string from the beginning
std::vector<Command> parseStream(const std::string &code, std::streampos pos) {
    std::stringstream ss(code);
    ss.seekg(pos);
    std::vector<Command> commands;
    std::string line;
    while (std::getline(ss, line, '\n')) {
        if (line.empty() || line[0] != '#') {
            if (line[0] == '@') [[unlikely]] {
                commands.push_back(parseCommand(line));
                continue;
            }
            closeCompiler("function finished incorrectly(stop or ret missed)");
        }
        commands.push_back(parseCommand(line));
        size_t rpos = line.find("ret");
        size_t spos = line.find("stop");
        if (rpos != std::string::npos || spos != std::string::npos) [[unlikely]] {
            return commands;
        }
    }
    return commands;
}



#endif //CLASSTEST_IRCOMMANDPARSER_H
