#include "strutils.h"

std::string trim(const std::string &str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");
    if (start == std::string::npos || end == std::string::npos) {
        return "";
    }
    return str.substr(start, end - start + 1);
}

// Function for splitting a string into tokens
std::vector<std::string> tokenize(const std::string &input, char delimiter) {
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

// takes name from function line
std::string getFnName(const std::string &input) {
    std::istringstream iss(input);
    std::string token;
    if (std::getline(iss, token, '(')) {
        return token;
    } else {
        closeCompiler("wrong function name");
    }
}
