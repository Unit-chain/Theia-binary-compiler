//
// Created by Kirill Zhukov on 21.05.2023.
//
#include "ASMGenerator.h"

ASMGenerator::ASMGenerator(char *path, BytecodeStream &bytecodeStream) : path(path), bs(bytecodeStream) {}

ASMGenerator::~ASMGenerator() {}

ARM64ASMGenerator::ARM64ASMGenerator(char *path, BytecodeStream &bytecodeStream) : ASMGenerator(path, bytecodeStream) {}

void ARM64ASMGenerator::write() {
    while (this->bs.hasMoreBytes()) {
        uint8_t instruction = bs.readByte();
        switch (instruction) {
            case STOP:
                // обработка STOP
                break;
            case GO_TO:
                // обработка GO_TO
                break;
            case SWAPREF:
                // обработка SWAPREF
                break;
            case IADD:
                // обработка IADD
                break;
            case ISUB:
                // обработка ISUB
                break;
            case IDIVIDE:
                // обработка IDIVIDE
                break;
            case IMUL:
                // обработка IMUL
                break;
            case IMOD:
                // обработка IMOD
                break;
            case IXOR:
                // обработка IXOR
                break;
            case RESERVED9:
                // обработка RESERVED9
                break;
            case ILSHIFT:
                // обработка ILSHIFT
                break;
            case IRSHIFT:
                // обработка IRSHIFT
                break;
            case POP:
                // обработка POP
                break;
            case POP2:
                // обработка POP2
                break;
            case DUP:
                // обработка DUP
                break;
            case IOR:
                // обработка IOR
                break;
            case IAND:
                // обработка IAND
                break;
            case PSHNULL:
                // обработка PSHNULL
                break;
            case SHA3:
                // обработка SHA3
                break;
            case BALANCE:
                // обработка BALANCE
                break;
            case TIMESTAMP:
                // обработка TIMESTAMP
                break;
            case BLOCKHASH:
                // обработка BLOCKHASH
                break;
            case CHAINID:
                // обработка CHAINID
                break;
            case CREATE:
                // обработка CREATE
                break;
            case DESTRUCT:
                // обработка DESTRUCT
                break;
            case ADDRESS:
                // обработка ADDRESS
                break;
            case INVALID:
                // обработка INVALID
                break;
            case ICNST_0:
                // обработка ICNST_0
                break;
            case ICNST_1:
                // обработка ICNST_1
                break;
            case ICNST_2:
                // обработка ICNST_2
                break;
            case ICNST_3:
                // обработка ICNST_3
                break;
            case ICNST_4:
                // обработка ICNST_4
                break;
            case U64CNST_0:
                // обработка U64CNST_0
                break;
            case U64CNST_1:
                // обработка U64CNST_1
                break;
            case CHECKTYPE:
                // обработка CHECKTYPE
                break;
            case U32CNST_0:
                // обработка U32CNST_0
                break;
            case U32CNST_1:
                // обработка U32CNST_1
                break;
            case U32STR_0:
                // обработка U32STR_0
                break;
            case U32STR_1:
                // обработка U32STR_1
                break;
            case U32STR_2:
                // обработка U32STR_2
                break;
            case U32STR_3:
                // обработка U32STR_3
                break;
            case U64STR_0:
                // обработка U64STR_0
                break;
            case U64STR_1:
                // обработка U64STR_1
                break;
            case U64STR_2:
                // обработка U64STR_2
                break;
            case U64STR_3:
                // обработка U64STR_3
                break;
            case ASTOREC:
                // обработка ASTOREC
                break;
            case ALOADC:
                // обработка ALOADC
                break;
            case U128STR_0:
                // обработка U128STR_0
                break;
            case U128STR_1:
                // обработка U128STR_1
                break;
            case U128STR_2:
                // обработка U128STR_2
                break;
            case U128STR_3:
                // обработка U128STR_3
                break;
            case LDC:
                // обработка LDC
                break;
            case ILD_0:
                // обработка ILD_0
                break;
            case ILD_1:
                // обработка ILD_1
                break;
            case ILD_2:
                // обработка ILD_2
                break;
            case ILD_3:
                // обработка ILD_3
                break;
            case SWAP:
                // обработка SWAP
                break;
            case IF_ACMPEQ:
                // обработка IF_ACMPEQ
                break;
            case IF_ACMPNE:
                // обработка IF_ACMPNE
                break;
            case IF_ICMPEQ:
                // обработка IF_ICMPEQ
                break;
            case IF_ICMPGE:
                // обработка IF_ICMPGE
                break;
            case IF_ICMPGT:
                // обработка IF_ICMPGT
                break;
            case IF_ICMPLE:
                // обработка IF_ICMPLE
                break;
            case IF_ICMPLT:
                // обработка IF_ICMPLT
                break;
            case IF_ICMPNE:
                // обработка IF_ICMPNE
                break;
            case IFEQ:
                // обработка IFEQ
                break;
            case IFGE:
                // обработка IFGE
                break;
            case IFGT:
                // обработка IFGT
                break;
            case IFLE:
                // обработка IFLE
                break;
            case IFLT:
                // обработка IFLT
                break;
            case IFNE:
                // обработка IFNE
                break;
            case IFNONNULL:
                // обработка IFNONNULL
                break;
            case IFNULL:
                // обработка IFNULL
                break;
            case NOP:
                // обработка NOP
                break;
            case RESERVED74:
                // обработка RESERVED74
                break;
            case DCNST_0:
                // обработка DCNST_0
                break;
            case DCNST_1:
                // обработка DCNST_1
                break;
            case LCNST_0:
                // обработка LCNST_0
                break;
            case LCNST_1:
                // обработка LCNST_1
                break;
            case RESERVED79:
                // обработка RESERVED79
                break;
            case DADD:
                // обработка DADD
                break;
            case U128CNST_0:
                // обработка U128CNST_0
                break;
            case U128CNST_1:
                // обработка U128CNST_1
                break;
            case U256CNST_0:
                // обработка U256CNST_0
                break;
            case U256CNST_1:
                // обработка U256CNST_1
                break;
            case DSUB:
                // обработка DSUB
                break;
            case LSUB:
                // обработка LSUB
                break;
            case LMUL:
                // обработка LMUL
                break;
            case LDIV:
                // обработка LDIV
                break;
            case U256STR_0:
                // обработка U256STR_0
                break;
            case U256STR_1:
                // обработка U256STR_1
                break;
            case U256STR_2:
                // обработка U256STR_2
                break;
            case U256STR_3:
                // обработка U256STR_3
                break;
            case RTCALL:
                // обработка RTCALL
                break;
            case STCALL:
                // обработка STCALL
                break;
            case ITFCALL:
                // обработка ITFCALL
                break;
            case SPCALL:
                // обработка SPCALL
                break;
            case LLD_0:
                // обработка LLD_0
                break;
            case LLD_1:
                // обработка LLD_1
                break;
            case LLD_2:
                // обработка LLD_2
                break;
            case LLD_3:
                // обработка LLD_3
                break;
            case ALOADI:
                // обработка ALOADI
                break;
            case ASTOREI:
                // обработка ASTOREI
                break;
            case RESERVED101:
                // обработка RESERVED101
                break;
            case DINV:
                // обработка DINV
                break;
            case DDIV:
                // обработка DDIV
                break;
            case DMUL:
                // обработка DMUL
                break;
            case ALOADL:
                // обработка ALOADL
                break;
            case ASTOREL:
                // обработка ASTOREL
                break;
            case ALOADD:
                // обработка ALOADD
                break;
            case ASTORED:
                // обработка ASTORED
                break;
            case ALOADB:
                // обработка ALOADB
                break;
            case ASTOREB:
                // обработка ASTOREB
                break;
            case RESERVED111:
                // обработка RESERVED111
                break;
            case IINC:
                // обработка IINC
                break;
            case I2D:
                // обработка I2D
                break;
            case I2U64:
                // обработка I2U64
                break;
            case I2U128:
                // обработка I2U128
                break;
            case I2U256:
                // обработка I2U256
                break;
            case I2B:
                // обработка I2B
                break;
            case I2C:
                // обработка I2C
                break;
            case I2L:
                // обработка I2L
                break;
            case I2S:
                // обработка I2S
                break;
            case D2I:
                // обработка D2I
                break;
            case D2L:
                // обработка D2L
                break;
            case IRETURN:
                // обработка IRETURN
                break;
            case LRETURN:
                // обработка LRETURN
                break;
            case RETURN:
                // обработка RETURN
                break;
            case ARETURN:
                // обработка ARETURN
                break;
            case NEW:
                // обработка NEW
                break;
            case NEWARRAY:
                // обработка NEWARRAY
                break;
            case NEW_MDARRAY:
                // обработка NEW_MDARRAY
                break;
            case DRETURN:
                // обработка DRETURN
                break;
            case U32RETURN:
                // обработка U32RETURN
                break;
            case U64RETURN:
                // обработка U64RETURN
                break;
            case U128RETURN:
                // обработка U128RETURN
                break;
            case U256RETURN:
                // обработка U256RETURN
                break;
            case ALOADU32:
                // обработка ALOADU32
                break;
            case ASTOREU32:
                // обработка ASTOREU32
                break;
            case ALOADU64:
                // обработка ALOADU64
                break;
            case ASTOREU64:
                // обработка ASTOREU64
                break;
            case ALOADU128:
                // обработка ALOADU128
                break;
            case ASTOREU128:
                // обработка ASTOREU128
                break;
            case ALOADU256:
                // обработка ALOADU256
                break;
            case ASTOREU256:
                // обработка ASTOREU256
                break;
            case ALOADA:
                // обработка ALOADA
                break;
            case ASTOREA:
                // обработка ASTOREA
                break;
            default:
                // обработка неизвестного opcode
                break;
        }
    }
}

//std::shared_ptr<char> ARM64ASMGenerator::iadd() {
//    char *iadd = (char *) std::malloc(8);
//    iadd = (char *) "add x0, x1, x1\n";
//    return std::shared_ptr<char>(iadd);
//}

void ARM64ASMGenerator::stop() {
    return;
}

X86ASMGenerator::X86ASMGenerator(char *path, BytecodeStream &bytecodeStream) : ASMGenerator(path, bytecodeStream) {}

void X86ASMGenerator::write() {
#if defined(_WIN32)
    buffer.append("global main\n"
        "extern ExitProcess\n\n\n"

        "section .text\n"
        "main:\n");
#elif defined(__linux__)
    buffer.append("global main\n"

        "section .text\n"
        "main:\n");
#endif
    while (this->bs.hasMoreBytes()) {
        uint8_t instruction = bs.readByte();
        switch (instruction) {
            case STOP:
                X86ASMGenerator::stop();
                break;
            case GO_TO:
                // обработка GO_TO
                break;
            case SWAPREF:
                // обработка SWAPREF
                break;
            case IADD:
                // обработка IADD
                break;
            case ISUB:
                // обработка ISUB
                break;
            case IDIVIDE:
                // обработка IDIVIDE
                break;
            case IMUL:
                // обработка IMUL
                break;
            case IMOD:
                // обработка IMOD
                break;
            case IXOR:
                // обработка IXOR
                break;
            case RESERVED9:
                // обработка RESERVED9
                break;
            case ILSHIFT:
                // обработка ILSHIFT
                break;
            case IRSHIFT:
                // обработка IRSHIFT
                break;
            case POP:
                // обработка POP
                break;
            case POP2:
                // обработка POP2
                break;
            case DUP:
                // обработка DUP
                break;
            case IOR:
                // обработка IOR
                break;
            case IAND:
                // обработка IAND
                break;
            case PSHNULL:
                // обработка PSHNULL
                break;
            case SHA3:
                // обработка SHA3
                break;
            case BALANCE:
                // обработка BALANCE
                break;
            case TIMESTAMP:
                // обработка TIMESTAMP
                break;
            case BLOCKHASH:
                // обработка BLOCKHASH
                break;
            case CHAINID:
                // обработка CHAINID
                break;
            case CREATE:
                // обработка CREATE
                break;
            case DESTRUCT:
                // обработка DESTRUCT
                break;
            case ADDRESS:
                // обработка ADDRESS
                break;
            case INVALID:
                // обработка INVALID
                break;
            case ICNST_0:
                // обработка ICNST_0
                break;
            case ICNST_1:
                // обработка ICNST_1
                break;
            case ICNST_2:
                // обработка ICNST_2
                break;
            case ICNST_3:
                // обработка ICNST_3
                break;
            case ICNST_4:
                // обработка ICNST_4
                break;
            case U64CNST_0:
                // обработка U64CNST_0
                break;
            case U64CNST_1:
                // обработка U64CNST_1
                break;
            case CHECKTYPE:
                // обработка CHECKTYPE
                break;
            case U32CNST_0:
                // обработка U32CNST_0
                break;
            case U32CNST_1:
                // обработка U32CNST_1
                break;
            case U32STR_0:
                // обработка U32STR_0
                break;
            case U32STR_1:
                // обработка U32STR_1
                break;
            case U32STR_2:
                // обработка U32STR_2
                break;
            case U32STR_3:
                // обработка U32STR_3
                break;
            case U64STR_0:
                // обработка U64STR_0
                break;
            case U64STR_1:
                // обработка U64STR_1
                break;
            case U64STR_2:
                // обработка U64STR_2
                break;
            case U64STR_3:
                // обработка U64STR_3
                break;
            case ASTOREC:
                // обработка ASTOREC
                break;
            case ALOADC:
                // обработка ALOADC
                break;
            case U128STR_0:
                // обработка U128STR_0
                break;
            case U128STR_1:
                // обработка U128STR_1
                break;
            case U128STR_2:
                // обработка U128STR_2
                break;
            case U128STR_3:
                // обработка U128STR_3
                break;
            case LDC:
                // обработка LDC
                break;
            case ILD_0:
                // обработка ILD_0
                break;
            case ILD_1:
                // обработка ILD_1
                break;
            case ILD_2:
                // обработка ILD_2
                break;
            case ILD_3:
                // обработка ILD_3
                break;
            case SWAP:
                // обработка SWAP
                break;
            case IF_ACMPEQ:
                // обработка IF_ACMPEQ
                break;
            case IF_ACMPNE:
                // обработка IF_ACMPNE
                break;
            case IF_ICMPEQ:
                // обработка IF_ICMPEQ
                break;
            case IF_ICMPGE:
                // обработка IF_ICMPGE
                break;
            case IF_ICMPGT:
                // обработка IF_ICMPGT
                break;
            case IF_ICMPLE:
                // обработка IF_ICMPLE
                break;
            case IF_ICMPLT:
                // обработка IF_ICMPLT
                break;
            case IF_ICMPNE:
                // обработка IF_ICMPNE
                break;
            case IFEQ:
                // обработка IFEQ
                break;
            case IFGE:
                // обработка IFGE
                break;
            case IFGT:
                // обработка IFGT
                break;
            case IFLE:
                // обработка IFLE
                break;
            case IFLT:
                // обработка IFLT
                break;
            case IFNE:
                // обработка IFNE
                break;
            case IFNONNULL:
                // обработка IFNONNULL
                break;
            case IFNULL:
                // обработка IFNULL
                break;
            case NOP:
                // обработка NOP
                break;
            case RESERVED74:
                // обработка RESERVED74
                break;
            case DCNST_0:
                // обработка DCNST_0
                break;
            case DCNST_1:
                // обработка DCNST_1
                break;
            case LCNST_0:
                // обработка LCNST_0
                break;
            case LCNST_1:
                // обработка LCNST_1
                break;
            case RESERVED79:
                // обработка RESERVED79
                break;
            case DADD:
                // обработка DADD
                break;
            case U128CNST_0:
                // обработка U128CNST_0
                break;
            case U128CNST_1:
                // обработка U128CNST_1
                break;
            case U256CNST_0:
                // обработка U256CNST_0
                break;
            case U256CNST_1:
                // обработка U256CNST_1
                break;
            case DSUB:
                // обработка DSUB
                break;
            case LSUB:
                // обработка LSUB
                break;
            case LMUL:
                // обработка LMUL
                break;
            case LDIV:
                // обработка LDIV
                break;
            case U256STR_0:
                // обработка U256STR_0
                break;
            case U256STR_1:
                // обработка U256STR_1
                break;
            case U256STR_2:
                // обработка U256STR_2
                break;
            case U256STR_3:
                // обработка U256STR_3
                break;
            case RTCALL:
                // обработка RTCALL
                break;
            case STCALL:
                // обработка STCALL
                break;
            case ITFCALL:
                // обработка ITFCALL
                break;
            case SPCALL:
                // обработка SPCALL
                break;
            case LLD_0:
                // обработка LLD_0
                break;
            case LLD_1:
                // обработка LLD_1
                break;
            case LLD_2:
                // обработка LLD_2
                break;
            case LLD_3:
                // обработка LLD_3
                break;
            case ALOADI:
                // обработка ALOADI
                break;
            case ASTOREI:
                // обработка ASTOREI
                break;
            case RESERVED101:
                // обработка RESERVED101
                break;
            case DINV:
                // обработка DINV
                break;
            case DDIV:
                // обработка DDIV
                break;
            case DMUL:
                // обработка DMUL
                break;
            case ALOADL:
                // обработка ALOADL
                break;
            case ASTOREL:
                // обработка ASTOREL
                break;
            case ALOADD:
                // обработка ALOADD
                break;
            case ASTORED:
                // обработка ASTORED
                break;
            case ALOADB:
                // обработка ALOADB
                break;
            case ASTOREB:
                // обработка ASTOREB
                break;
            case RESERVED111:
                // обработка RESERVED111
                break;
            case IINC:
                // обработка IINC
                break;
            case I2D:
                // обработка I2D
                break;
            case I2U64:
                // обработка I2U64
                break;
            case I2U128:
                // обработка I2U128
                break;
            case I2U256:
                // обработка I2U256
                break;
            case I2B:
                // обработка I2B
                break;
            case I2C:
                // обработка I2C
                break;
            case I2L:
                // обработка I2L
                break;
            case I2S:
                // обработка I2S
                break;
            case D2I:
                // обработка D2I
                break;
            case D2L:
                // обработка D2L
                break;
            case IRETURN:
                // обработка IRETURN
                break;
            case LRETURN:
                // обработка LRETURN
                break;
            case RETURN:
                // обработка RETURN
                break;
            case ARETURN:
                // обработка ARETURN
                break;
            case NEW:
                // обработка NEW
                break;
            case NEWARRAY:
                // обработка NEWARRAY
                break;
            case NEW_MDARRAY:
                // обработка NEW_MDARRAY
                break;
            case DRETURN:
                // обработка DRETURN
                break;
            case U32RETURN:
                // обработка U32RETURN
                break;
            case U64RETURN:
                // обработка U64RETURN
                break;
            case U128RETURN:
                // обработка U128RETURN
                break;
            case U256RETURN:
                // обработка U256RETURN
                break;
            case ALOADU32:
                // обработка ALOADU32
                break;
            case ASTOREU32:
                // обработка ASTOREU32
                break;
            case ALOADU64:
                // обработка ALOADU64
                break;
            case ASTOREU64:
                // обработка ASTOREU64
                break;
            case ALOADU128:
                // обработка ALOADU128
                break;
            case ASTOREU128:
                // обработка ASTOREU128
                break;
            case ALOADU256:
                // обработка ALOADU256
                break;
            case ASTOREU256:
                // обработка ASTOREU256
                break;
            case ALOADA:
                // обработка ALOADA
                break;
            case ASTOREA:
                // обработка ASTOREA
                break;
            default:
                // обработка неизвестного opcode
                break;
        }
    }
}

void X86ASMGenerator::stop() {
#if defined(_WIN32)
    buffer.append("\txor rax, rax\n"
        "\tcall ExitProcess\n");
#elif defined(__linux__)
    buffer.append("\tmov eax, 60\n"
        "\txor edi, edi\n"
        "\tsyscall\n")
#endif
        return;
}

void X86ASMGenerator::print() {
    printf("asm:\n%s", this->buffer.c_str());
}