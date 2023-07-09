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
    auto begin();
    ///@brief returns iterator from the end.
    ///Used in range-based for loop
    auto end();
private:
    std::unordered_map<std::string, IRFunction> program;
};

IRParsedProgram::IRParsedProgram(char *path) {
    FILE *fp = fopen(path, "r");
    fseek(fp, SEEK_SET, SEEK_END);
    size_t fs = ftell(fp);
    fseek(fp, SEEK_SET, 0);
    char buff[fs];
    fread(buff, fs, 1, fp);
    std::string str(buff);
    this->program = getFnLines(str);
}

IRParsedProgram::IRParsedProgram(std::string &program) {
    this->program = getFnLines(program);
}

void IRParsedProgram::printProgram() {
    for (auto& [funcName, func] : program) {
        std::cout << "function name: " << func.name << ", offset: " << func.offset << "\ninstructions: " << '\n';
        for (Command &command : func.commands) {
            std::cout << "Command: " << command.name << ", flag: " << command.flag << std::endl;
            std::cout << "Arguments: \n";
            for (int i = 0; i < command.args.size(); i++) {
                printf("\targ%d: %s\n", i, command.args[i].c_str());
            }
            std::cout << std::endl;
        }
    }
}

IRFunction IRParsedProgram::at(std::string &name) {
    return this->program.at(name);
}

size_t IRParsedProgram::size() {
    return this->program.size();
}

auto IRParsedProgram::begin() {
    return this->program.begin();
}

auto IRParsedProgram::end() {
    return this->program.end();
}

#endif //CLASSTEST_IRPARSEDPROGRAM_H
