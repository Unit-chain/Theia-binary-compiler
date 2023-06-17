//
// Created by Kirill Zhukov on 21.05.2023.
//

#ifndef BINARYWRITER_OPCODES_H
#define BINARYWRITER_OPCODES_H
#include "unordered_map"
#include "IR/IRCommandParser.h"

struct ReferenceOpcode {
    u1 args;
    u1 index;
    char allowedFlags = '\0';
};

///@brief represents class which contains reference opcodes
///@param op unordered map which contains ReferenceOpcode by it's name as a key
class Opcodes {
public:
    explicit Opcodes();
    ///@brief checks if opcode is allowed
    ///@param cmd parsed command
    bool containsOpcode(Command &cmd);
    ///@brief return index by parsed command
    ///@param cmd parsed command
    u1 getIndexByCommand(Command &cmd);
    ///@brief returns reference opcode by name
    ///@param cmdName command name
    ReferenceOpcode getReferenceCommand(std::string &cmdName);
    ///@brief checks if command is valid
    ///@param cmd parsed command
    bool validateCommand(Command &cmd);
private:
    std::unordered_map<std::string, ReferenceOpcode> op;
};

Opcodes::Opcodes() {
    this->op["stop"]        = {.args = 0, .index = 0};
    this->op["bl"]          = {.args = 1, .index = 1};
    this->op["swap"]        = {.args = 2, .index = 2};
    this->op["add"]         = {.args = 2, .index = 3, .allowedFlags = 'v'};
    this->op["sub"]         = {.args = 2, .index = 4, .allowedFlags = 'v'};
    this->op["div"]         = {.args = 2, .index = 5, .allowedFlags = 'v'};
    this->op["mul"]         = {.args = 2, .index = 6, .allowedFlags = 'v'};
    this->op["mod"]         = {.args = 2, .index = 7, .allowedFlags = 'v'};
    this->op["or"]          = {.args = 2, .index = 8, .allowedFlags = 'v'};
    this->op["and"]         = {.args = 2, .index = 9, .allowedFlags = 'v'};
    this->op["xor"]         = {.args = 2, .index = 10, .allowedFlags = 'v'};
    this->op["lshift"]      = {.args = 2, .index = 11, .allowedFlags = 'v'};
    this->op["rshift"]      = {.args = 2, .index = 12, .allowedFlags = 'v'};
    this->op["pop"]         = {.args = 1, .index = 13};
    this->op["pop2"]        = {.args = 2, .index = 14};
    this->op["dup"]         = {.args = 1, .index = 15};
    this->op["vmcall"]      = {.args = 1, .index = 16};
    this->op["cnst_0"]      = {.args = 1, .index = 17};
    this->op["cnst_1"]      = {.args = 1, .index = 18};
    this->op["cnst_2"]      = {.args = 1, .index = 19};
    this->op["cnst_3"]      = {.args = 1, .index = 20};
    this->op["cnst_4"]      = {.args = 1, .index = 21};
    this->op["astorea"]     = {.args = 1, .index = 22};
    this->op["aloada"]      = {.args = 1, .index = 23};
    this->op["str"]         = {.args = 1, .index = 24};
    this->op["ldr"]         = {.args = 1, .index = 25};
    this->op["strp"]        = {.args = 2, .index = 26};
    this->op["cmp_eq"]      = {.args = 3, .index = 27, .allowedFlags = 'v'};
    this->op["cmp_ne"]      = {.args = 3, .index = 28, .allowedFlags = 'v'};
    this->op["cmp_ge"]      = {.args = 3, .index = 29, .allowedFlags = 'v'};
    this->op["cmp_le"]      = {.args = 3, .index = 30, .allowedFlags = 'v'};
    this->op["cmp_gt"]      = {.args = 3, .index = 31, .allowedFlags = 'v'};
    this->op["cmp_lt"]      = {.args = 3, .index = 32, .allowedFlags = 'v'};
    this->op["nop"]         = {.args = 0, .index = 33};
    this->op["call"]        = {.args = 2, .index = 34};
    this->op["ret"]         = {.args = 1, .index = 35};
    this->op["virtualcall"] = {.args = 1, .index = 36};
    this->op["align"]       = {.args = 1, .index = 37};
}

bool Opcodes::containsOpcode(Command &cmd) {
    if (validateCommand(cmd)) {
        return this->op.contains(cmd.name);
    }
    closeCompiler("Invalid command found");
}

u1 Opcodes::getIndexByCommand(Command &cmd) {
    if (validateCommand(cmd)) {
        return this->op.at(cmd.name).index;
    }
    closeCompiler("Invalid command found");
}

ReferenceOpcode Opcodes::getReferenceCommand(std::string &cmdName) {
    return this->op.at(cmdName);
}

bool Opcodes::validateCommand(Command &cmd) {
    ReferenceOpcode opcode = this->op.at(cmd.name);
    if ((cmd.args.size() == opcode.args) && (cmd.flag == opcode.allowedFlags)) [[likely]] {
        return true;
    } else [[unlikely]] {
        return false;
    }
}

#endif //BINARYWRITER_OPCODES_H
