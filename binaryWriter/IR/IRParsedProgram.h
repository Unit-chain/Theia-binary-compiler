//
// Created by Kirill Zhukov on 07.06.2023.
//

#ifndef CLASSTEST_IRPARSEDPROGRAM_H
#define CLASSTEST_IRPARSEDPROGRAM_H
#include "iostream"
#include "IRFunctionParser.h"

///@class IRParsedProgram
///@brief IR parsed program
///@param program it's parsed program
class IRParsedProgram {
public:
    ///@brief constructor which opens and reads data from file and after parse it
    ///@param path path to file
    explicit IRParsedProgram(char *path);
    ///@brief constructor which takes data from file and after parse it
    ///@param program raw program data took from file
    explicit IRParsedProgram(std::string &program);
public:
    ///@brief returns IRFunction by index
    ///@param i - index
    IRFunction at(std::string &name);
    ///@brief returns quantity of functions
    size_t size();
    ///@brief prints program in readable format
    void printProgram();
    ///@brief returns iterator from the beginning.
    ///Used in range-based for loop
    std::unordered_map<std::string, IRFunction>::iterator begin();
    ///@brief returns iterator from the end.
    ///Used in range-based for loop
    std::unordered_map<std::string, IRFunction>::iterator end();
private:
    std::unordered_map<std::string, IRFunction> program;
};



#endif //CLASSTEST_IRPARSEDPROGRAM_H
