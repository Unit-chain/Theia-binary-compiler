//
// Created by Kirill Zhukov on 06.06.2023.
//

#ifndef CLASSTEST_CFG_H
#define CLASSTEST_CFG_H
#include "IRCommandParser.h"
#include "IRFunctionParser.h"


///@brief not implemented yet
class CFG {
public:
    CFG(std::vector<Command> &program);
private:
    void buildFromProgram();
private:
    std::unordered_map<uint64_t, IRFunction> graph;
};
#endif //CLASSTEST_CFG_H
