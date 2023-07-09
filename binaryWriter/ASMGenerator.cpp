//
// Created by Kirill Zhukov on 21.05.2023.
//
#include "ASMGenerator.h"
#define STACKSIZE 64
ASMGenerator::ASMGenerator(char *path, BytecodeStream &bytecodeStream) : path(path), bs(bytecodeStream) {}

ASMGenerator::~ASMGenerator() {}

ARM64ASMGenerator::ARM64ASMGenerator(char *path, BytecodeStream &bytecodeStream) : ASMGenerator(path, bytecodeStream) {}

void ARM64ASMGenerator::write() {
    while (this->bs.hasMoreBytes()) {
        uint8_t instruction = bs.readByte();
        switch (instruction) {
            case(0):
                ARM64ASMGenerator::stop();
                break;
            case(1):
                ARM64ASMGenerator::bl();
                break;
            case(2):
                ARM64ASMGenerator::swap();
                break;
            case(3):
                ARM64ASMGenerator::add();
                break;
            case(4):
                ARM64ASMGenerator::sub();
                break;
            case(5):
                ARM64ASMGenerator::div();
                break;
            case(6):
                ARM64ASMGenerator::mul();
                break;
            case(7):
                ARM64ASMGenerator::mod();
                break;
            case(8):
                ARM64ASMGenerator::f_or();
                break;
            case(9):
                ARM64ASMGenerator::f_and();
                break;
            case(10):
                ARM64ASMGenerator::f_xor();
                break;
            case(11):
                ARM64ASMGenerator::lshift();
                break;
            case(12):
                ARM64ASMGenerator::rshift();
                break;
            case(13):
                ARM64ASMGenerator::pop();
                break;
            case(14):
                ARM64ASMGenerator::pop2();
                break;
            case(15):
                ARM64ASMGenerator::dup();
                break;
            case(16):
                ARM64ASMGenerator::vmcall();
                break;
            case(17):
                ARM64ASMGenerator::cnst_0();
                break;
            case(18):
                ARM64ASMGenerator::cnst_1();
                break;
            case(19):
                ARM64ASMGenerator::cnst_2();
                break;
            case(20):
                ARM64ASMGenerator::cnst_3();
                break;
            case(21):
                ARM64ASMGenerator::cnst_4();
                break;
            case(22):
                ARM64ASMGenerator::astorea();
                break;
            case(23):
                ARM64ASMGenerator::aloada();
                break;
            case(24):
                ARM64ASMGenerator::str();
                break;
            case(25):
                ARM64ASMGenerator::ldr();
                break;
            case(26):
                ARM64ASMGenerator::strp();
                break;
            case(27):
                ARM64ASMGenerator::cmp_eq();
                break;
            case(28):
                ARM64ASMGenerator::cmp_ne();
                break;
            case(29):
                ARM64ASMGenerator::cmp_ge();
                break;
            case(30):
                ARM64ASMGenerator::cmp_le();
                break;
            case(31):
                ARM64ASMGenerator::cmp_gt();
                break;
            case(32):
                ARM64ASMGenerator::cmp_lt();
                break;
            case(33):
                ARM64ASMGenerator::nop();
                break;
            case(34):
                ARM64ASMGenerator::call();
                break;
            case(35):
                ARM64ASMGenerator::ret();
                break;
            case(36):
                ARM64ASMGenerator::virtualcall();
                break;
            case(37):
                ARM64ASMGenerator::align();
                break;
        }
    }
}

ALWAYS_INLINE void ARM64ASMGenerator::stop() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::bl() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::swap() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::add() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::sub() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::div() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::mul() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::mod() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::f_or() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::f_and() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::f_xor() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::lshift() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::rshift() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::pop() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::pop2() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::dup() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::vmcall() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::cnst_0() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::cnst_1() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::cnst_2() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::cnst_3() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::cnst_4() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::astorea() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::aloada() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::str() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::ldr() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::strp() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::cmp_eq() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::cmp_ne() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::cmp_ge() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::cmp_le() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::cmp_gt() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::cmp_lt() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::nop() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::call() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::ret() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::virtualcall() {
    return;
}

ALWAYS_INLINE void ARM64ASMGenerator::align() {
    return;
}


X86ASMGenerator::X86ASMGenerator(char *path, BytecodeStream &bytecodeStream) : ASMGenerator(path, bytecodeStream) {}

void X86ASMGenerator::write() {
    while (this->bs.hasMoreBytes()) {
        uint8_t instruction = bs.readByte();
        switch (instruction) {
            case(0):
                X86ASMGenerator::stop();
                break;
            case(1):
                X86ASMGenerator::bl();
                break;
            case(2):
                X86ASMGenerator::swap();
                break;
            case(3):
                X86ASMGenerator::add();
                break;
            case(4):
                X86ASMGenerator::sub();
                break;
            case(5):
                X86ASMGenerator::div();
                break;
            case(6):
                X86ASMGenerator::mul();
                break;
            case(7):
                X86ASMGenerator::mod();
                break;
            case(8):
                X86ASMGenerator::f_or();
                break;
            case(9):
                X86ASMGenerator::f_and();
                break;
            case(10):
                X86ASMGenerator::f_xor();
                break;
            case(11):
                X86ASMGenerator::lshift();
                break;
            case(12):
                X86ASMGenerator::rshift();
                break;
            case(13):
                X86ASMGenerator::pop();
                break;
            case(14):
                X86ASMGenerator::pop2();
                break;
            case(15):
                X86ASMGenerator::dup();
                break;
            case(16):
                X86ASMGenerator::vmcall();
                break;
            case(17):
                X86ASMGenerator::cnst_0();
                break;
            case(18):
                X86ASMGenerator::cnst_1();
                break;
            case(19):
                X86ASMGenerator::cnst_2();
                break;
            case(20):
                X86ASMGenerator::cnst_3();
                break;
            case(21):
                X86ASMGenerator::cnst_4();
                break;
            case(22):
                X86ASMGenerator::astorea();
                break;
            case(23):
                X86ASMGenerator::aloada();
                break;
            case(24):
                X86ASMGenerator::str();
                break;
            case(25):
                X86ASMGenerator::ldr();
                break;
            case(26):
                X86ASMGenerator::strp();
                break;
            case(27):
                X86ASMGenerator::cmp_eq();
                break;
            case(28):
                X86ASMGenerator::cmp_ne();
                break;
            case(29):
                X86ASMGenerator::cmp_ge();
                break;
            case(30):
                X86ASMGenerator::cmp_le();
                break;
            case(31):
                X86ASMGenerator::cmp_gt();
                break;
            case(32):
                X86ASMGenerator::cmp_lt();
                break;
            case(33):
                X86ASMGenerator::nop();
                break;
            case(34):
                X86ASMGenerator::call();
                break;
            case(35):
                X86ASMGenerator::ret();
                break;
            case(36):
                X86ASMGenerator::virtualcall();
                break;
            case(37):
                X86ASMGenerator::align();
                break;
        }
    }
}

ALWAYS_INLINE void X86ASMGenerator::stop() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::bl() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::swap() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::add() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::sub() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::div() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::mul() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::mod() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::f_or() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::f_and() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::f_xor() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::lshift() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::rshift() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::pop() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::pop2() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::dup() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::vmcall() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::cnst_0() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::cnst_1() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::cnst_2() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::cnst_3() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::cnst_4() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::astorea() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::aloada() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::str() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::ldr() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::strp() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::cmp_eq() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::cmp_ne() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::cmp_ge() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::cmp_le() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::cmp_gt() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::cmp_lt() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::nop() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::call() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::ret() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::virtualcall() {
    return;
}

ALWAYS_INLINE void X86ASMGenerator::align() {
    return;
}
