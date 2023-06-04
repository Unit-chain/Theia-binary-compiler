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
            case(STOP):
                ARM64ASMGenerator::stop();
                break;
            case(BL):
                ARM64ASMGenerator::bl();
                break;
            case(SWAP_REF):
                ARM64ASMGenerator::swap_ref();
                break;
            case(SWAP):
                ARM64ASMGenerator::swap();
                break;
            case(ADD):
                ARM64ASMGenerator::add();
                break;
            case(SUB):
                ARM64ASMGenerator::sub();
                break;
            case(DIV):
                ARM64ASMGenerator::div();
                break;
            case(MUL):
                ARM64ASMGenerator::mul();
                break;
            case(MOD):
                ARM64ASMGenerator::mod();
                break;
            case(OR):
                ARM64ASMGenerator::f_or();
                break;
            case(AND):
                ARM64ASMGenerator::f_and();
                break;
            case(XOR):
                ARM64ASMGenerator::f_xor();
                break;
            case(LSHIFT):
                ARM64ASMGenerator::lshift();
                break;
            case(RSHIFT):
                ARM64ASMGenerator::rshift();
                break;
            case(POP):
                ARM64ASMGenerator::pop();
                break;
            case(POP2):
                ARM64ASMGenerator::pop2();
                break;
            case(DUP):
                ARM64ASMGenerator::dup();
                break;
            case(VMCALL):
                ARM64ASMGenerator::vmcall();
                break;
            case(CNST_0):
                ARM64ASMGenerator::cnst_0();
                break;
            case(CNST_1):
                ARM64ASMGenerator::cnst_1();
                break;
            case(CNST_2):
                ARM64ASMGenerator::cnst_2();
                break;
            case(CNST_3):
                ARM64ASMGenerator::cnst_3();
                break;
            case(CNST_4):
                ARM64ASMGenerator::cnst_4();
                break;
            case(ASTOREA):
                ARM64ASMGenerator::astorea();
                break;
            case(ALOADA):
                ARM64ASMGenerator::aloada();
                break;
            case(STR):
                ARM64ASMGenerator::str();
                break;
            case(LDR):
                ARM64ASMGenerator::ldr();
                break;
            case(STRP):
                ARM64ASMGenerator::strp();
                break;
            case(CMP_EQ):
                ARM64ASMGenerator::cmp_eq();
                break;
            case(CMP_NE):
                ARM64ASMGenerator::cmp_ne();
                break;
            case(CMP_GE):
                ARM64ASMGenerator::cmp_ge();
                break;
            case(CMP_LE):
                ARM64ASMGenerator::cmp_le();
                break;
            case(CMP_GT):
                ARM64ASMGenerator::cmp_gt();
                break;
            case(CMP_LT):
                ARM64ASMGenerator::cmp_lt();
                break;
            case(NOP):
                ARM64ASMGenerator::nop();
                break;
            case(CALL):
                ARM64ASMGenerator::call();
                break;
            case(RET):
                ARM64ASMGenerator::ret();
                break;
            case(VIRTUALCALL):
                ARM64ASMGenerator::virtualcall();
                break;
            case(ALIGN):
                ARM64ASMGenerator::align();
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
    while (this->bs.hasMoreBytes()) {
        uint8_t instruction = bs.readByte();
        switch (instruction) {
            case(STOP):
                X86ASMGenerator::stop();
                break;
            case(BL):
                X86ASMGenerator::bl();
                break;
            case(SWAP_REF):
                X86ASMGenerator::swap_ref();
                break;
            case(SWAP):
                X86ASMGenerator::swap();
                break;
            case(ADD):
                X86ASMGenerator::add();
                break;
            case(SUB):
                X86ASMGenerator::sub();
                break;
            case(DIV):
                X86ASMGenerator::div();
                break;
            case(MUL):
                X86ASMGenerator::mul();
                break;
            case(MOD):
                X86ASMGenerator::mod();
                break;
            case(OR):
                X86ASMGenerator::f_or();
                break;
            case(AND):
                X86ASMGenerator::f_and();
                break;
            case(XOR):
                X86ASMGenerator::f_xor();
                break;
            case(LSHIFT):
                X86ASMGenerator::lshift();
                break;
            case(RSHIFT):
                X86ASMGenerator::rshift();
                break;
            case(POP):
                X86ASMGenerator::pop();
                break;
            case(POP2):
                X86ASMGenerator::pop2();
                break;
            case(DUP):
                X86ASMGenerator::dup();
                break;
            case(VMCALL):
                X86ASMGenerator::vmcall();
                break;
            case(CNST_0):
                X86ASMGenerator::cnst_0();
                break;
            case(CNST_1):
                X86ASMGenerator::cnst_1();
                break;
            case(CNST_2):
                X86ASMGenerator::cnst_2();
                break;
            case(CNST_3):
                X86ASMGenerator::cnst_3();
                break;
            case(CNST_4):
                X86ASMGenerator::cnst_4();
                break;
            case(ASTOREA):
                X86ASMGenerator::astorea();
                break;
            case(ALOADA):
                X86ASMGenerator::aloada();
                break;
            case(STR):
                X86ASMGenerator::str();
                break;
            case(LDR):
                X86ASMGenerator::ldr();
                break;
            case(STRP):
                X86ASMGenerator::strp();
                break;
            case(CMP_EQ):
                X86ASMGenerator::cmp_eq();
                break;
            case(CMP_NE):
                X86ASMGenerator::cmp_ne();
                break;
            case(CMP_GE):
                X86ASMGenerator::cmp_ge();
                break;
            case(CMP_LE):
                X86ASMGenerator::cmp_le();
                break;
            case(CMP_GT):
                X86ASMGenerator::cmp_gt();
                break;
            case(CMP_LT):
                X86ASMGenerator::cmp_lt();
                break;
            case(NOP):
                X86ASMGenerator::nop();
                break;
            case(CALL):
                X86ASMGenerator::call();
                break;
            case(RET):
                X86ASMGenerator::ret();
                break;
            case(VIRTUALCALL):
                X86ASMGenerator::virtualcall();
                break;
            case(ALIGN):
                X86ASMGenerator::align();
                break;
        }
    }
}

void X86ASMGenerator::stop() {
    return;
}
