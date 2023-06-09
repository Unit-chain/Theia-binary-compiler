//
// Created by Kirill Zhukov on 07.06.2023.
//

#ifndef CLASSTEST_ERRUTILS_H
#define CLASSTEST_ERRUTILS_H
#include "iostream"

///@brief
void closeCompiler(const char *mess) {
    fprintf(stderr, "Error: %s\n", mess);
    exit(EXIT_FAILURE);
}

#endif //CLASSTEST_ERRUTILS_H
