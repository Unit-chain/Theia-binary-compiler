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
std::unordered_map<std::string, IRFunction> getFnLines(std::string &fileData) {
    std::unordered_map<std::string, IRFunction> tokens;
    std::stringstream ss(fileData);
    std::string token;
    uint64_t offsetCounter = 0;
    for (uint64_t offset = 0; std::getline(ss, token, '\n'); ++offset) {
        if (token[0] == ';') {
            continue;
        }

        token = trim(token);
        if (token[0] != 'f' || token[1] != 'n') {
            continue;
        }

        // Ignore comments begin with ;
        size_t commentPos = token.find(';');
        if (commentPos != std::string::npos) {
            token = token.substr(0, commentPos);
            // Remove unnecessary spaces
            token = trim(token);
        }

        if (!token.empty()) {
            std::vector<std::string> fnParams = tokenize(token, ' ');
            std::vector<Command> commands = parseStream(fileData, ss.tellg());
            std::string fnName = getFnName(fnParams.at(fnParams.size() - 1));
            if (fnParams.size() < 3) [[likely]] {
                tokens[fnName] = {
                    offset,
                    fnName,
                    std::move(commands),
                    std::move(fnParams)
                }; // thanks to LLVM and perfectly working "emplace_back" and allocate_at_least.h
                }
            else {
                for (int i = 1; i < fnParams.size(); ++i) {
                    if (fnParams.at(i)[0] == '_') {
                        break;
                    }
                    fnParams.push_back(fnParams.at(i));
                }
                tokens[fnName] = {
                    offset,
                    fnName,
                    std::move(commands),
                    std::move(fnParams)
                };
            }
        }
    }
    return tokens;
}

#endif //CLASSTEST_IRFUNCTIONPARSER_H
