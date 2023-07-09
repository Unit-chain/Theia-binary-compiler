//
// Created by Kirill Zhukov on 21.05.2023.
//

#ifndef BINARYWRITER_OPCODES_H
#define BINARYWRITER_OPCODES_H
#include "unordered_map"
#include "IR/IRCommandParser.h"

namespace theiaIR {

    struct ReferenceOpcode {
        u1 args;
        u1 index;
        char allowedFlags = '\0';
    };

    ///@brief represents class which contains reference opcodes
    ///@param op unordered map which contains ReferenceOpcode by it's name as a key
    class Opcodes {
    public:
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
        const std::unordered_map<std::string, ReferenceOpcode> op = {
                {"stop",        {.args = 0, .index = 0}},
                {"bl",          {.args = 1, .index = 1}},
                {"swap",        {.args = 2, .index = 2}},
                {"add",         {.args = 2, .index = 3, .allowedFlags = 'v'}},
                {"sub",         {.args = 2, .index = 4, .allowedFlags = 'v'}},
                {"div",         {.args = 2, .index = 5, .allowedFlags = 'v'}},
                {"mul",         {.args = 2, .index = 6, .allowedFlags = 'v'}},
                {"mod",         {.args = 2, .index = 7, .allowedFlags = 'v'}},
                {"or",          {.args = 2, .index = 8, .allowedFlags = 'v'}},
                {"and",         {.args = 2, .index = 9, .allowedFlags = 'v'}},
                {"xor",         {.args = 2, .index = 10, .allowedFlags = 'v'}},
                {"lshift",      {.args = 2, .index = 11, .allowedFlags = 'v'}},
                {"rshift",      {.args = 2, .index = 12, .allowedFlags = 'v'}},
                {"pop",         {.args = 1, .index = 13}},
                {"pop2",        {.args = 2, .index = 14}},
                {"dup",         {.args = 1, .index = 15}},
                {"vmcall",      {.args = 1, .index = 16}},
                {"cnst_0",      {.args = 1, .index = 17}},
                {"cnst_1",      {.args = 1, .index = 18}},
                {"cnst_2",      {.args = 1, .index = 19}},
                {"cnst_3",      {.args = 1, .index = 20}},
                {"cnst_4",      {.args = 1, .index = 21}},
                {"astorea",     {.args = 1, .index = 22}},
                {"aloada",      {.args = 1, .index = 23}},
                {"str",         {.args = 1, .index = 24}},
                {"ldr",         {.args = 1, .index = 25}},
                {"strp",        {.args = 2, .index = 26}},
                {"cmp_eq",      {.args = 3, .index = 27, .allowedFlags = 'v'}},
                {"cmp_ne",      {.args = 3, .index = 28, .allowedFlags = 'v'}},
                {"cmp_ge",      {.args = 3, .index = 29, .allowedFlags = 'v'}},
                {"cmp_le",      {.args = 3, .index = 30, .allowedFlags = 'v'}},
                {"cmp_gt",      {.args = 3, .index = 31, .allowedFlags = 'v'}},
                {"cmp_lt",      {.args = 3, .index = 32, .allowedFlags = 'v'}},
                {"nop",         {.args = 0, .index = 33}},
                {"call",        {.args = 2, .index = 34}},
                {"ret",         {.args = 1, .index = 35}},
                {"virtualcall", {.args = 1, .index = 36}},
                {"align",       {.args = 1, .index = 37}}
        };
    };
}
#endif //BINARYWRITER_OPCODES_H
