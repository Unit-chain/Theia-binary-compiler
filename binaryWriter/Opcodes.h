//
// Created by Kirill Zhukov on 21.05.2023.
//

#ifndef BINARYWRITER_OPCODES_H
#define BINARYWRITER_OPCODES_H

///@brief opcodes
enum : unsigned char {
    STOP,
    BL,
    SWAP_REF,
    SWAP,
    ADD,
    SUB,
    DIV,
    MUL,
    MOD,
    OR,
    AND,
    XOR,
    LSHIFT,
    RSHIFT,
    POP,
    POP2,
    DUP,
    VMCALL,
    CNST_0,
    CNST_1,
    CNST_2,
    CNST_3,
    CNST_4,
    ASTOREA,
    ALOADA,
    STR,
    LDR,
    STRP,
    CMP_EQ,
    CMP_NE,
    CMP_GE,
    CMP_LE,
    CMP_GT,
    CMP_LT,
    NOP,
    CALL,
    RET,
    VIRTUALCALL,
    ALIGN,
};

#endif //BINARYWRITER_OPCODES_H
