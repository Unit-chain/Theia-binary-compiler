//
// Created by Kirill Zhukov on 06.06.2023.
//

#ifndef CLASSTEST_IRFUNCTIONPARSER_H
#define CLASSTEST_IRFUNCTIONPARSER_H

#include "unordered_map"
#include "iostream"
#include "sstream"
#include "strutils.h"
#include "IRCommandParser.h"

///@struct IRFunction
///@brief Structure for IR function representation
///@param name - function name
///@param commands contains parsed commands with their arguments and flags
///@param attributes contains function arguments
struct IRFunction {
    uint64_t offset;
    std::string name;
    std::vector<Command> commands;
    std::vector<std::string> attributes;
};

///@brief parse raw IR data into functions and instructions inside
///@param fileData it's raw IR data
std::unordered_map<std::string, IRFunction> getFnLines(std::string &fileData);

#endif //CLASSTEST_IRFUNCTIONPARSER_H
