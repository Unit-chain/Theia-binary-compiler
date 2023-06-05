//
// Created by Kirill Zhukov on 04.06.2023.
//

#ifndef BINARYWRITER_IRPARSER_H
#define BINARYWRITER_IRPARSER_H
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Structure for command representation
struct Command {
    std::string name;
    std::vector<std::string> args;
    char flag = '\0';
};

std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");
    if (start == std::string::npos || end == std::string::npos) {
        return "";
    }
    return str.substr(start, end - start + 1);
}

// Function for splitting a string into tokens
std::vector<std::string> tokenize(const std::string& input, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        // Ignore comments begin with ;
        size_t commentPos = token.find(';');
        if (commentPos != std::string::npos) {
            token = token.substr(0, commentPos);
        }
        // Remove unnecessary spaces
        token = trim(token);
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }
    return tokens;
}

// Function for parsing a command
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

// Function for parsing code
std::vector<Command> parseCode(const std::string& code) {
    std::vector<Command> commands;
    std::vector<std::string> lines = tokenize(code, '\n');

    for (const std::string& line : lines) {
        if (line.empty() || line[0] != '#') {
            if (line[0] == '@') [[unlikely]] {
                goto pushBranch;
            }
            continue;
        }
        pushBranch:
        commands.push_back(parseCommand(line));
    }

    return commands;
}

#endif //BINARYWRITER_IRPARSER_H
