//
// Created by Kirill Zhukov on 06.06.2023.
//

#ifndef CLASSTEST_STRUTILS_H
#define CLASSTEST_STRUTILS_

#include "string"
#include "vector"
#include "sstream"
#include "errutils.h"

std::string trim(const std::string &str);

// Function for splitting a string into tokens
std::vector<std::string> tokenize(const std::string &input, char delimiter);

// takes name from function line
std::string getFnName(const std::string &input);

#endif //CLASSTEST_STRUTILS_H
