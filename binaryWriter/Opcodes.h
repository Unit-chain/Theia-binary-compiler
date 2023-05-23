//
// Created by Kirill Zhukov on 21.05.2023.
//

#ifndef BINARYWRITER_OPCODES_H
#define BINARYWRITER_OPCODES_H

///@brief opcodes
enum : unsigned char {
    STOP = 0x00,
    GO_TO,
    SWAPREF,
    IADD,
    ISUB,
    IDIVIDE,
    IMUL,
    IMOD,
    IXOR,
    RESERVED9,
    ILSHIFT,
    IRSHIFT,
    POP,
    POP2,
    DUP,
    IOR,
    IAND,
    PSHNULL,
    SHA3,
    BALANCE,
    TIMESTAMP,
    BLOCKHASH,
    CHAINID,
    CREATE,
    DESTRUCT,
    ADDRESS,
    INVALID,
    ICNST_0,
    ICNST_1,
    ICNST_2,
    ICNST_3,
    ICNST_4,
    U64CNST_0,
    U64CNST_1,
    CHECKTYPE,
    U32CNST_0,
    U32CNST_1,
    U32STR_0,
    U32STR_1,
    U32STR_2,
    U32STR_3,
    U64STR_0,
    U64STR_1,
    U64STR_2,
    U64STR_3,
    ASTOREC,
    ALOADC,
    U128STR_0,
    U128STR_1,
    U128STR_2,
    U128STR_3,
    LDC,
    ILD_0,
    ILD_1,
    ILD_2,
    ILD_3,
    SWAP,
    IF_ACMPEQ,
    IF_ACMPNE,
    IF_ICMPEQ,
    IF_ICMPGE,
    IF_ICMPGT,
    IF_ICMPLE,
    IF_ICMPLT,
    IF_ICMPNE,
    IFEQ,
    IFGE,
    IFGT,
    IFLE,
    IFLT,
    IFNE,
    IFNONNULL,
    IFNULL,
    NOP,
    RESERVED74,
    DCNST_0,
    DCNST_1,
    LCNST_0,
    LCNST_1,
    RESERVED79,
    DADD,
    U128CNST_0,
    U128CNST_1,
    U256CNST_0,
    U256CNST_1,
    DSUB,
    LSUB,
    LMUL,
    LDIV,
    U256STR_0,
    U256STR_1,
    U256STR_2,
    U256STR_3,
    RTCALL,
    STCALL,
    ITFCALL,
    SPCALL,
    LLD_0,
    LLD_1,
    LLD_2,
    LLD_3,
    ALOADI,
    ASTOREI,
    RESERVED101,
    DINV,
    DDIV,
    DMUL,
    ALOADL,
    ASTOREL,
    ALOADD,
    ASTORED,
    ALOADB,
    ASTOREB,
    RESERVED111,
    IINC,
    I2D,
    I2U64,
    I2U128,
    I2U256,
    I2B,
    I2C,
    I2L,
    I2S,
    D2I,
    D2L,
    IRETURN,
    LRETURN,
    RETURN,
    ARETURN,
    NEW,
    NEWARRAY,
    NEW_MDARRAY,
    DRETURN,
    U32RETURN,
    U64RETURN,
    U128RETURN,
    U256RETURN,
    ALOADU32,
    ASTOREU32,
    ALOADU64,
    ASTOREU64,
    ALOADU128,
    ASTOREU128,
    ALOADU256,
    ASTOREU256,
    ALOADA,
    ASTOREA,
};

#endif //BINARYWRITER_OPCODES_H