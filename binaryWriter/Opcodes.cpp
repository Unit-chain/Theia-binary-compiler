#include "Opcodes.h"

bool theiaIR::Opcodes::containsOpcode(Command &cmd) {
    if (validateCommand(cmd)) {
        return this->op.contains(cmd.name);
    }
    closeCompiler("Invalid command found");
}

u1 theiaIR::Opcodes::getIndexByCommand(Command &cmd) {
    if (cmd.name.at(0) == '@') {
        return (~(u1) 0);
    }
    if (validateCommand(cmd)) {
        return this->op.at(cmd.name).index;
    }
    closeCompiler("Invalid command found");
}

theiaIR::ReferenceOpcode theiaIR::Opcodes::getReferenceCommand(std::string &cmdName) {
    return this->op.at(cmdName);
}

bool theiaIR::Opcodes::validateCommand(Command &cmd) {
    theiaIR::ReferenceOpcode opcode = this->op.at(cmd.name);
    if ((cmd.args.size() == opcode.args) && ((cmd.flag == opcode.allowedFlags) || (cmd.flag == '\0'))) [[likely]] {
        return true;
        }
    else [[unlikely]] {
        return false;
        }
}
