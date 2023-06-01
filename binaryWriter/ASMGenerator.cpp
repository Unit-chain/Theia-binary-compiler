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
    buffer.append(
        "section .data\n"
        // db: Define Byte - allocates 1 byte of memory.
        // dw: Define Word - allocates 2 bytes (16 bits) of memory.
        // dd: Define Doubleword - allocates 4 bytes (32 bits) of memory.
        // dq: Define Quadword - allocates 8 bytes (64 bits) of memory.
        // dt: Define Ten Bytes - allocates 10 bytes of memory.
        // ddq: Define Double Quadword - allocates 16 bytes (128 bits) of memory.
        // do: Define Octword - allocates 32 bytes (256 bits) of memory.
        // dy: Define Yottabyte - allocates 256 bytes (2048 bits) of memory.
        "\tstack db " + std::to_string(STACKSIZE) + "dup(?)\n\n"

        "section .text\n"
        "global main\n"
        "extern ExitProcess\n\n\n"

        "section .text\n"
        "main:\n");
#elif defined(__linux__)
    buffer.append(
        "section .data\n"
        // db: Define Byte - allocates 1 byte of memory.
        // dw: Define Word - allocates 2 bytes (16 bits) of memory.
        // dd: Define Doubleword - allocates 4 bytes (32 bits) of memory.
        // dq: Define Quadword - allocates 8 bytes (64 bits) of memory.
        // dt: Define Ten Bytes - allocates 10 bytes of memory.
        // ddq: Define Double Quadword - allocates 16 bytes (128 bits) of memory.
        // do: Define Octword - allocates 32 bytes (256 bits) of memory.
        // dy: Define Yottabyte - allocates 256 bytes (2048 bits) of memory.
        "\tstack db " + std::to_string(STACKSIZE) + "dup(?)\n\n"

        "section .text\n"
        "global main\n"

        "main:\n");
#endif
    while (this->bs.hasMoreBytes()) {
        uint8_t instruction = bs.readByte();
        switch (instruction) {
            case STOP:
                X86ASMGenerator::stop();
                break;
            case GO_TO:
                X86ASMGenerator::go_to();
                break;
            case SWAPREF:
                X86ASMGenerator::swapref();
                break;
            case IADD:
                X86ASMGenerator::iadd();
                break;
            case ISUB:
                X86ASMGenerator::isub();
                break;
            case IDIVIDE:
                X86ASMGenerator::idivide();
                break;
            case IMUL:
                X86ASMGenerator::imul();
                break;
            case IMOD:
                X86ASMGenerator::imod();
                break;
            case IXOR:
                X86ASMGenerator::ixor();
                break;
            case RESERVED9:
                X86ASMGenerator::reserved9();
                break;
            case ILSHIFT:
                X86ASMGenerator::ilshift();
                break;
            case IRSHIFT:
                X86ASMGenerator::irshift();
                break;
            case POP:
                X86ASMGenerator::pop();
                break;
            case POP2:
                X86ASMGenerator::pop2();
                break;
            case DUP:
                X86ASMGenerator::dup();
                break;
            case IOR:
                X86ASMGenerator::ior();
                break;
            case IAND:
                X86ASMGenerator::iadd();
                break;
            case PSHNULL:
                X86ASMGenerator::pshnull();
                break;
            case SHA3:
                X86ASMGenerator::sha3();
                break;
            case BALANCE:
                X86ASMGenerator::balance();
                break;
            case TIMESTAMP:
                X86ASMGenerator::timestamp();
                break;
            case BLOCKHASH:
                X86ASMGenerator::blockhash();
                break;
            case CHAINID:
                X86ASMGenerator::chainid();
                break;
            case CREATE:
                X86ASMGenerator::create();
                break;
            case DESTRUCT:
                X86ASMGenerator::destruct();
                break;
            case ADDRESS:
                X86ASMGenerator::address();
                break;
            case INVALID:
                X86ASMGenerator::invalid();
                break;
            case ICNST_0:
                X86ASMGenerator::icnst_0();
                break;
            case ICNST_1:
                X86ASMGenerator::icnst_1();
                break;
            case ICNST_2:
                X86ASMGenerator::icnst_2();
                break;
            case ICNST_3:
                X86ASMGenerator::icnst_3();
                break;
            case ICNST_4:
                X86ASMGenerator::icnst_4();
                break;
            case U64CNST_0:
                X86ASMGenerator::u64cnst_0();
                break;
            case U64CNST_1:
                X86ASMGenerator::u64cnst_1();
                break;
            case CHECKTYPE:
                X86ASMGenerator::checktype();
                break;
            case U32CNST_0:
                X86ASMGenerator::u32cnst_0();
                break;
            case U32CNST_1:
                X86ASMGenerator::u32cnst_1();
                break;
            case U32STR_0:
                X86ASMGenerator::u32str_0();
                break;
            case U32STR_1:
                X86ASMGenerator::u32str_1();
                break;
            case U32STR_2:
                X86ASMGenerator::u32str_2();
                break;
            case U32STR_3:
                X86ASMGenerator::u32str_3();
                break;
            case U64STR_0:
                X86ASMGenerator::u64str_0();
                break;
            case U64STR_1:
                X86ASMGenerator::u64str_1();
                break;
            case U64STR_2:
                X86ASMGenerator::u64str_2();
                break;
            case U64STR_3:
                X86ASMGenerator::u64str_3();
                break;
            case ASTOREC:
                X86ASMGenerator::astorec();
                break;
            case ALOADC:
                X86ASMGenerator::aloadc();
                break;
            case U128STR_0:
                X86ASMGenerator::u128str_0();
                break;
            case U128STR_1:
                X86ASMGenerator::u128str_1();
                break;
            case U128STR_2:
                X86ASMGenerator::u128str_2();
                break;
            case U128STR_3:
                X86ASMGenerator::u128str_3();
                break;
            case LDC:
                X86ASMGenerator::ldc();
                break;
            case ILD_0:
                X86ASMGenerator::ild_0();
                break;
            case ILD_1:
                X86ASMGenerator::ild_1();
                break;
            case ILD_2:
                X86ASMGenerator::ild_2();
                break;
            case ILD_3:
                X86ASMGenerator::ild_3();
                break;
            case SWAP:
                X86ASMGenerator::swap();
                break;
            case IF_ACMPEQ:
                X86ASMGenerator::if_acmpeq();
                break;
            case IF_ACMPNE:
                X86ASMGenerator::if_acmpne();
                break;
            case IF_ICMPEQ:
                X86ASMGenerator::if_icmpeq();
                break;
            case IF_ICMPGE:
                X86ASMGenerator::if_icmpge();
                break;
            case IF_ICMPGT:
                X86ASMGenerator::if_icmpgt();
                break;
            case IF_ICMPLE:
                X86ASMGenerator::if_icmple();
                break;
            case IF_ICMPLT:
                X86ASMGenerator::if_icmplt();
                break;
            case IF_ICMPNE:
                X86ASMGenerator::if_icmpne();
                break;
            case IFEQ:
                X86ASMGenerator::ifeq();
                break;
            case IFGE:
                X86ASMGenerator::ifge();
                break;
            case IFGT:
                X86ASMGenerator::ifgt();
                break;
            case IFLE:
                X86ASMGenerator::ifle();
                break;
            case IFLT:
                X86ASMGenerator::iflt();
                break;
            case IFNE:
                X86ASMGenerator::ifne();
                break;
            case IFNONNULL:
                X86ASMGenerator::ifnonnull();
                break;
            case IFNULL:
                X86ASMGenerator::ifnull();
                break;
            case NOP:
                X86ASMGenerator::nop();
                break;
            case RESERVED74:
                X86ASMGenerator::reserved74();
                break;
            case DCNST_0:
                X86ASMGenerator::dcnst_0();
                break;
            case DCNST_1:
                X86ASMGenerator::dcnst_1();
                break;
            case LCNST_0:
                X86ASMGenerator::lcnst_0();
                break;
            case LCNST_1:
                X86ASMGenerator::lcnst_1();
                break;
            case RESERVED79:
                X86ASMGenerator::reserved79();
                break;
            case DADD:
                X86ASMGenerator::dadd();
                break;
            case U128CNST_0:
                X86ASMGenerator::u128cnst_0();
                break;
            case U128CNST_1:
                X86ASMGenerator::u128cnst_1();
                break;
            case U256CNST_0:
                X86ASMGenerator::u256cnst_0();
                break;
            case U256CNST_1:
                X86ASMGenerator::u256cnst_1();
                break;
            case DSUB:
                X86ASMGenerator::dsub();
                break;
            case LSUB:
                X86ASMGenerator::lsub();
                break;
            case LMUL:
                X86ASMGenerator::lmul();
                break;
            case LDIV:
                X86ASMGenerator::ldiv();
                break;
            case U256STR_0:
                X86ASMGenerator::u256str_0();
                break;
            case U256STR_1:
                X86ASMGenerator::u256str_1();
                break;
            case U256STR_2:
                X86ASMGenerator::u256str_2();
                break;
            case U256STR_3:
                X86ASMGenerator::u256str_3();
                break;
            case RTCALL:
                X86ASMGenerator::rtcall();
                break;
            case STCALL:
                X86ASMGenerator::stcall();
                break;
            case ITFCALL:
                X86ASMGenerator::itfcall();
                break;
            case SPCALL:
                X86ASMGenerator::spcall();
                break;
            case LLD_0:
                X86ASMGenerator::lld_0();
                break;
            case LLD_1:
                X86ASMGenerator::lld_1();
                break;
            case LLD_2:
                X86ASMGenerator::lld_2();
                break;
            case LLD_3:
                X86ASMGenerator::lld_3();
                break;
            case ALOADI:
                X86ASMGenerator::aloadi();
                break;
            case ASTOREI:
                X86ASMGenerator::astorei();
                break;
            case RESERVED101:
                X86ASMGenerator::reserved101();
                break;
            case DINV:
                X86ASMGenerator::dinv();
                break;
            case DDIV:
                X86ASMGenerator::ddiv();
                break;
            case DMUL:
                X86ASMGenerator::dmul();
                break;
            case ALOADL:
                X86ASMGenerator::aloadl();
                break;
            case ASTOREL:
                X86ASMGenerator::astorel();
                break;
            case ALOADD:
                X86ASMGenerator::aloadd();
                break;
            case ASTORED:
                X86ASMGenerator::astored();
                break;
            case ALOADB:
                X86ASMGenerator::aloadb();
                break;
            case ASTOREB:
                X86ASMGenerator::astoreb();
                break;
            case RESERVED111:
                X86ASMGenerator::reserved111();
                break;
            case IINC:
                X86ASMGenerator::iinc();
                break;
            case I2D:
                X86ASMGenerator::i2d();
                break;
            case I2U64:
                X86ASMGenerator::i2u64();
                break;
            case I2U128:
                X86ASMGenerator::i2u128();
                break;
            case I2U256:
                X86ASMGenerator::i2u256();
                break;
            case I2B:
                X86ASMGenerator::i2b();
                break;
            case I2C:
                X86ASMGenerator::i2c();
                break;
            case I2L:
                X86ASMGenerator::i2l();
                break;
            case I2S:
                X86ASMGenerator::i2s();
                break;
            case D2I:
                X86ASMGenerator::d2i();
                break;
            case D2L:
                X86ASMGenerator::d2l();
                break;
            case IRETURN:
                X86ASMGenerator::ireturn();
                break;
            case LRETURN:
                X86ASMGenerator::lreturn();
                break;
            case RETURN:
                X86ASMGenerator::Return();
                break;
            case ARETURN:
                X86ASMGenerator::areturn();
                break;
            case NEW:
                X86ASMGenerator::New();
                break;
            case NEWARRAY:
                X86ASMGenerator::newarray();
                break;
            case NEW_MDARRAY:
                X86ASMGenerator::new_mdarray();
                break;
            case DRETURN:
                X86ASMGenerator::dreturn();
                break;
            case U32RETURN:
                X86ASMGenerator::u32return();
                break;
            case U64RETURN:
                X86ASMGenerator::u64return();
                break;
            case U128RETURN:
                X86ASMGenerator::u128return();
                break;
            case U256RETURN:
                X86ASMGenerator::u256return();
                break;
            case ALOADU32:
                X86ASMGenerator::aloadu32();
                break;
            case ASTOREU32:
                X86ASMGenerator::astoreu32();
                break;
            case ALOADU64:
                X86ASMGenerator::aloadu64();
                break;
            case ASTOREU64:
                X86ASMGenerator::astoreu64();
                break;
            case ALOADU128:
                X86ASMGenerator::aloadu128();
                break;
            case ASTOREU128:
                X86ASMGenerator::astoreu128();
                break;
            case ALOADU256:
                X86ASMGenerator::aloadu256();
                break;
            case ASTOREU256:
                X86ASMGenerator::astoreu256();
                break;
            case ALOADA:
                X86ASMGenerator::aloada();
                break;
            case ASTOREA:
                X86ASMGenerator::astorea();
                break;
            default:
                // обработка неизвестного opcode
                break;
        }
    }
}

// *sp is a stack pointer, *bp is usually used as a base pointer to element of a stack, 
// rax is used in devision as a higher bit of division result also it's what is what is devised 


void X86ASMGenerator::stop() {
#if defined(_WIN32)
    buffer.append("\txor rax, rax\n"
        "\tcall ExitProcess\n");
#elif defined(__linux__)
    buffer.append("\tmov eax, 0x60\n"
        "\txor edi, edi\n"
        "\tsyscall\n")
#endif
        return;
}

void X86ASMGenerator::go_to() {
    buffer.append("\tjmp $+" + std::to_string(bs.readByte()) + "\n");
    return;
}

void X86ASMGenerator::swapref() {
    uint8_t first = STACKSIZE * bs.readByte();
    uint8_t second = STACKSIZE * bs.readByte();
    //depends of size or registers might need to change e**(32 bits) and r**(64 bits)
    buffer.append("\tmov rax, [rsp+" + std::to_string(first) + "]\n");
    buffer.append("\tmov rbx, [rsp+" + std::to_string(second) + "]\n");
    buffer.append("\tmov [rsp+" + std::to_string(first) + "], rbx\n");
    buffer.append("\tmov [rsp+" + std::to_string(second) + "], rax\n");
    return;
}

void X86ASMGenerator::iadd() {
    buffer.append("\tpop rax\n");
    buffer.append("\tpop rbx\n");
    buffer.append("\tadd rax, rbx\n");
    buffer.append("\tpush rax\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::isub() {
    buffer.append("\tpop rax\n");
    buffer.append("\tpop rbx\n");
    buffer.append("\tsub rax, rbx\n");
    buffer.append("\tpush rax\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::idivide() {
    buffer.append("\tpop rax\n");
    buffer.append("\tpop rbx\n");
    // *dx is used to store
    buffer.append("\txor rdx, rdx\n");
    buffer.append("\tidiv rbx\n");
    buffer.append("\tpush rax\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::imul() {
    buffer.append("\tpop rax\n");
    buffer.append("\tpop rbx\n");
    buffer.append("\timul rax, rbx\n");
    buffer.append("\tpush rax\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::imod() {
    buffer.append("\tpop rax\n");
    buffer.append("\tpop rbx\n");
    // *dx is used to store
    buffer.append("\txor rdx, rdx\n");
    buffer.append("\tidiv rbx\n");
    buffer.append("\tpush rdx\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::ixor() {
    buffer.append("\tpop rax\n");
    buffer.append("\tpop rbx\n");
    buffer.append("\txor rax, rbx\n");
    buffer.append("\tpush rax\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::reserved9() {
    buffer.append("\tnop\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::ilshift() {
    uint8_t shift = bs.readByte();
    buffer.append("\tpop rax\n");
    buffer.append("\tpop rbx\n");
    if (shift == 8)
        buffer.append("\tshl rax, cl");
    else if (shift == 16)
        buffer.append("\tshl rax, cx");
    else if (shift == 32)
        buffer.append("\tshl rax, ecx");
    else if (shift > 32)
        printf("shift must not be bigger then 32");
    buffer.append("\tpush rax\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::irshift() {
    uint8_t shift = bs.readByte();
    buffer.append("\tpop rax\n");
    buffer.append("\tpop rbx\n");
    if (shift == 8)
        buffer.append("\tshr rax, cl");
    else if (shift == 16)
        buffer.append("\tshr rax, cx");
    else if (shift == 32)
        buffer.append("\tshr rax, ecx");
    else if (shift > 32)
        printf("shift must not be bigger then 32");
    buffer.append("\tpush rax\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::pop() {
    buffer.append("\tpop rax\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::pop2() {
    buffer.append("\tpop rax\n");
    buffer.append("\tpop rax\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::dup() {
    buffer.append("\tmov rax, [rax]\n");
    buffer.append("\tpush rax\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::ior() {
    buffer.append("\tpop rax\n");
    buffer.append("\tpop rbx\n");
    buffer.append("\tor rax, rbx\n");
    buffer.append("\tpush rax\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::iand() {
    buffer.append("\tpop rax\n");
    buffer.append("\tpop rbx\n");
    buffer.append("\tand rax, rbx\n");
    buffer.append("\tpush rax\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::pshnull() {
    buffer.append("push 0");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::sha3() {
    sha3used = true;
    buffer.append("sha3");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::balance() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::timestamp() {
    timestampused = true;
#if defined(_WIN32)
    buffer.append("\tsub rsp, 40\n");
    buffer.append("\tlea rcx, [systemTimeStruct]\n");
    buffer.append("\tcall GetSystemTime\n");
    buffer.append("\tadd rsp, 40\n");
#elif defined(__linux__)
    buffer.append("mov rax, 228");
    buffer.append("xor rdi, rdi");
    buffer.append("lea rsi, [time_spec]");
    buffer.append("syscall ");
#endif
    return;
}

ALWAYS_INLINE void X86ASMGenerator::blockhash() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::chainid() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::create() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::destruct() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::address() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::invalid() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::icnst_0() {
    buffer.append("\tpush 0\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::icnst_1() {
    buffer.append("\tpush 1\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::icnst_2() {
    buffer.append("\tpush 2\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::icnst_3() {
    buffer.append("\tpush 3\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::icnst_4() {
    buffer.append("\tpush 4\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u64cnst_0() {
    buffer.append("\tpush 0\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u64cnst_1() {
    buffer.append("\tpush 1\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::checktype() {
    buffer.append("\ttodo\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u32cnst_0() {
    buffer.append("\tpush 0\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u32cnst_1() {
    buffer.append("\tpush 1\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u32str_0() {
    buffer.append("\tpop eax\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u32str_1() {
    buffer.append("\tpop ebx\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u32str_2() {
    buffer.append("\tpop ecx\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u32str_3() {
    buffer.append("\tpop edx\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u64str_0() {
    buffer.append("\tpop rax\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u64str_1() {
    buffer.append("\tpop rbx\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u64str_2() {
    buffer.append("\tpop rcx\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u64str_3() {
    buffer.append("\tpop rdx\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::astorec() {
    buffer.append("\tpop rcx\n");
    buffer.append("\tpop rbx\n");
    buffer.append("\tpop rax\n");
    buffer.append("\tmov [rcx+rbx], rax\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::aloadc() {
    buffer.append("\tmov rax, [rcx]\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u128str_0() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u128str_1() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u128str_2() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u128str_3() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::ldc() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::ild_0() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::ild_1() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::ild_2() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::ild_3() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::swap() {
    buffer.append("\tpop rax\n");
    buffer.append("\tpop rbx\n");
    buffer.append("\tpush rax\n");
    buffer.append("\tpush rbx\n");
    return;
}
//This is some weird BCrap TODO
ALWAYS_INLINE void X86ASMGenerator::if_acmpeq() {
    buffer.append("mov rax, [rsp]");
    buffer.append("mov rbx, [rsp+8]");
    buffer.append("cmp rax, rbx");
    buffer.append("je $+" + std::to_string(bs.readByte()));
    return;
}

ALWAYS_INLINE void X86ASMGenerator::if_acmpne() {
    buffer.append("mov rax, [rsp]");
    buffer.append("mov rbx, [rsp+8]");
    buffer.append("cmp rax, rbx");
    buffer.append("jne $+" + std::to_string(bs.readByte()));
    return;
}

ALWAYS_INLINE void X86ASMGenerator::if_icmpeq() {
    buffer.append("mov rax, [rsp]");
    buffer.append("mov rbx, [rsp+8]");
    buffer.append("cmp rax, rbx");
    buffer.append("je $+" + std::to_string(bs.readByte()));
    return;
}

ALWAYS_INLINE void X86ASMGenerator::if_icmpge() {
    buffer.append("mov rax, [rsp]");
    buffer.append("mov rbx, [rsp+8]");
    buffer.append("cmp rax, rbx");
    buffer.append("jge $+" + std::to_string(bs.readByte()));
    return;
}

ALWAYS_INLINE void X86ASMGenerator::if_icmpgt() {
    buffer.append("mov rax, [rsp]");
    buffer.append("mov rbx, [rsp+8]");
    buffer.append("cmp rax, rbx");
    buffer.append("jg $+" + std::to_string(bs.readByte()));
    return;
}

ALWAYS_INLINE void X86ASMGenerator::if_icmple() {
    buffer.append("mov rax, [rsp]");
    buffer.append("mov rbx, [rsp+8]");
    buffer.append("cmp rax, rbx");
    buffer.append("jle $+" + std::to_string(bs.readByte()));
    return;
}

ALWAYS_INLINE void X86ASMGenerator::if_icmplt() {
    buffer.append("mov rax, [rsp]");
    buffer.append("mov rbx, [rsp+8]");
    buffer.append("cmp rax, rbx");
    buffer.append("jl $+" + std::to_string(bs.readByte()));
    return;
}

ALWAYS_INLINE void X86ASMGenerator::if_icmpne() {
    buffer.append("mov rax, [rsp]");
    buffer.append("mov rbx, [rsp+8]");
    buffer.append("cmp rax, rbx");
    buffer.append("jne $+" + std::to_string(bs.readByte()));
    return;
}

ALWAYS_INLINE void X86ASMGenerator::ifeq() {
    buffer.append("mov rax, [rsp]");
    buffer.append("cmp rax, 0");
    buffer.append("je $+" + std::to_string(bs.readByte()));
    return;
}

ALWAYS_INLINE void X86ASMGenerator::ifge() {
    buffer.append("mov rax, [rsp]");
    buffer.append("cmp rax, 0");
    buffer.append("jge $+" + std::to_string(bs.readByte()));
    return;
}

ALWAYS_INLINE void X86ASMGenerator::ifgt() {
    buffer.append("mov rax, [rsp]");
    buffer.append("cmp rax, 0");
    buffer.append("jg $+" + std::to_string(bs.readByte()));
    return;
}

ALWAYS_INLINE void X86ASMGenerator::ifle() {
    buffer.append("mov rax, [rsp]");
    buffer.append("cmp rax, 0");
    buffer.append("jle $+" + std::to_string(bs.readByte()));
    return;
}

ALWAYS_INLINE void X86ASMGenerator::iflt() {
    buffer.append("mov rax, [rsp]");
    buffer.append("cmp rax, 0");
    buffer.append("jl $+" + std::to_string(bs.readByte()));
    return;
}

ALWAYS_INLINE void X86ASMGenerator::ifne() {
    buffer.append("mov rax, [rsp]");
    buffer.append("cmp rax, 0");
    buffer.append("jne $+" + std::to_string(bs.readByte()));
    return;
}

ALWAYS_INLINE void X86ASMGenerator::ifnonnull() {
    buffer.append("mov rax, [rsp]");
    buffer.append("cmp rax, 0");
    buffer.append("jne $+" + std::to_string(bs.readByte()));
    return;
}

ALWAYS_INLINE void X86ASMGenerator::ifnull() {
    buffer.append("mov rax, [rsp]");
    buffer.append("cmp rax, 0");
    buffer.append("je $+" + std::to_string(bs.readByte()));
    return;
}

ALWAYS_INLINE void X86ASMGenerator::nop() {
    buffer.append("\tnop\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::reserved74() {
    buffer.append("\tnop\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::dcnst_0() {
    buffer.append();
    return;
}

ALWAYS_INLINE void X86ASMGenerator::dcnst_1() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::lcnst_0() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::lcnst_1() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::reserved79() {
    buffer.append("\tnop\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::dadd() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u128cnst_0() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u128cnst_1() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u256cnst_0() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u256cnst_1() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::dsub() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::lsub() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::lmul() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::ldiv() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u256str_0() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u256str_1() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u256str_2() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u256str_3() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::rtcall() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::stcall() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::itfcall() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::spcall() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::lld_0() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::lld_1() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::lld_2() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::lld_3() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::aloadi() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::astorei() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::reserved101() {
    buffer.append("\tnop\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::dinv() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::ddiv() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::dmul() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::aloadl() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::astorel() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::aloadd() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::astored() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::aloadb() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::astoreb() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::reserved111() {
    buffer.append("\tnop\n");
    return;
}

ALWAYS_INLINE void X86ASMGenerator::iinc() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::i2d() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::i2u64() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::i2u128() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::i2u256() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::i2b() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::i2c() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::i2l() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::i2s() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::d2i() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::d2l() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::ireturn() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::lreturn() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::Return() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::areturn() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::New() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::newarray() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::new_mdarray() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::dreturn() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u32return() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u64return() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u128return() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::u256return() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::aloadu32() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::astoreu32() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::aloadu64() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::astoreu64() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::aloadu128() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::astoreu128() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::aloadu256() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::astoreu256() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::aloada() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::astorea() {
    return;
}

void X86ASMGenerator::print() {
    printf("asm:\n%s", this->buffer.c_str());
}

