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

typedef unsigned char u1;

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
Command parseCommand(const std::string &line);

///@brief Function for parsing code
///@param code it's source code written in IR
std::vector<Command> parseCode(const std::string &code);

///@brief Function for parsing code
///@param code it's source code written in IR
///@param pos it's position in file or string from the beginning
std::vector<Command> parseStream(const std::string &code, std::streampos pos);



#endif //CLASSTEST_IRCOMMANDPARSER_H
