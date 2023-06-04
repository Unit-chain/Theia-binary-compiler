//
// Created by Kirill Zhukov on 21.05.2023.
//

#ifndef BINARYWRITER_ASMGENERATOR_H
#define BINARYWRITER_ASMGENERATOR_H

#include "memory"
#include "BytecodeStream.h"
#include "SystemIdentifier.h"
#include "utility"
#include "Opcodes.h"

typedef unsigned char uchar;

enum class State {
    Idle,
    Branching,
    Logic,
    Math,
    Jump,
    Hash,
    Compare,
    Load,
    Array
};

enum Sign : uchar {
    unsign = 0x10,
    sign = 0x20
};

///@brief size in bytes!!! (not bits)!!!
enum Argument : uchar {
    i1 = 0x01,  // uint8_t
    i2 = 0x02,  // uint16_t
    i4 = 0x03,  // uint32_t
    i8 = 0x04,  // uint64_t
    i16 = 0x08, // uint128_t
    i32 = 0x09  // uint256_t
};

// ALWAYS_INLINE uchar isSigned(unsigned char symbol) {
//     return (Sign) (symbol & 0xF0);
// }
//
// ALWAYS_INLINE Argument getArg(unsigned char symbol) {
//     return (Argument) (symbol & 0x0F);
// }

class ASMGenerator {
public:
    virtual ~ASMGenerator();

    ASMGenerator(char *path, BytecodeStream &bytecodeStream);

public:
    virtual void write() = 0;

    void setBs(BytecodeStream &bs);

protected:
    std::string path;
    State currentState;
    BytecodeStream bs;
    std::string buffer;

protected:
    virtual ALWAYS_INLINE void stop() = 0;
    virtual ALWAYS_INLINE void bl() = 0;
    virtual ALWAYS_INLINE void swap_ref() = 0;
    virtual ALWAYS_INLINE void swap() = 0;
    virtual ALWAYS_INLINE void add() = 0;
    virtual ALWAYS_INLINE void sub() = 0;
    virtual ALWAYS_INLINE void div() = 0;
    virtual ALWAYS_INLINE void mul() = 0;
    virtual ALWAYS_INLINE void mod() = 0;
    virtual ALWAYS_INLINE void f_or();
    virtual ALWAYS_INLINE void f_and();
    virtual ALWAYS_INLINE void f_xor();
    virtual ALWAYS_INLINE void lshift() = 0;
    virtual ALWAYS_INLINE void rshift() = 0;
    virtual ALWAYS_INLINE void pop() = 0;
    virtual ALWAYS_INLINE void pop2() = 0;
    virtual ALWAYS_INLINE void dup() = 0;
    virtual ALWAYS_INLINE void vmcall() = 0;
    virtual ALWAYS_INLINE void cnst_0() = 0;
    virtual ALWAYS_INLINE void cnst_1() = 0;
    virtual ALWAYS_INLINE void cnst_2() = 0;
    virtual ALWAYS_INLINE void cnst_3() = 0;
    virtual ALWAYS_INLINE void cnst_4() = 0;
    virtual ALWAYS_INLINE void astorea() = 0;
    virtual ALWAYS_INLINE void aloada() = 0;
    virtual ALWAYS_INLINE void str() = 0;
    virtual ALWAYS_INLINE void ldr() = 0;
    virtual ALWAYS_INLINE void strp() = 0;
    virtual ALWAYS_INLINE void cmp_eq() = 0;
    virtual ALWAYS_INLINE void cmp_ne() = 0;
    virtual ALWAYS_INLINE void cmp_ge() = 0;
    virtual ALWAYS_INLINE void cmp_le() = 0;
    virtual ALWAYS_INLINE void cmp_gt() = 0;
    virtual ALWAYS_INLINE void cmp_lt() = 0;
    virtual ALWAYS_INLINE void nop() = 0;
    virtual ALWAYS_INLINE void call() = 0;
    virtual ALWAYS_INLINE void ret() = 0;
    virtual ALWAYS_INLINE void virtualcall() = 0;
    virtual ALWAYS_INLINE void align() = 0;
};

class ARM64ASMGenerator : public ASMGenerator {
public:
    explicit ARM64ASMGenerator(char *path, BytecodeStream &bytecodeStream);

public:
    void write() override;

private:
    int argument; ///@brief (Argument ALWAYS_INLINE Sign() = 0;)
    uchar loadedArgumentBytes;

private:
    ALWAYS_INLINE void stop();
    ALWAYS_INLINE void bl();
    ALWAYS_INLINE void swap_ref();
    ALWAYS_INLINE void swap();
    ALWAYS_INLINE void add();
    ALWAYS_INLINE void sub();
    ALWAYS_INLINE void div();
    ALWAYS_INLINE void mul();
    ALWAYS_INLINE void mod();
    ALWAYS_INLINE void f_or();
    ALWAYS_INLINE void f_and();
    ALWAYS_INLINE void f_xor();
    ALWAYS_INLINE void lshift();
    ALWAYS_INLINE void rshift();
    ALWAYS_INLINE void pop();
    ALWAYS_INLINE void pop2();
    ALWAYS_INLINE void dup();
    ALWAYS_INLINE void vmcall();
    ALWAYS_INLINE void cnst_0();
    ALWAYS_INLINE void cnst_1();
    ALWAYS_INLINE void cnst_2();
    ALWAYS_INLINE void cnst_3();
    ALWAYS_INLINE void cnst_4();
    ALWAYS_INLINE void astorea();
    ALWAYS_INLINE void aloada();
    ALWAYS_INLINE void str();
    ALWAYS_INLINE void ldr();
    ALWAYS_INLINE void strp();
    ALWAYS_INLINE void cmp_eq();
    ALWAYS_INLINE void cmp_ne();
    ALWAYS_INLINE void cmp_ge();
    ALWAYS_INLINE void cmp_le();
    ALWAYS_INLINE void cmp_gt();
    ALWAYS_INLINE void cmp_lt();
    ALWAYS_INLINE void nop();
    ALWAYS_INLINE void call();
    ALWAYS_INLINE void ret();
    ALWAYS_INLINE void virtualcall();
    ALWAYS_INLINE void align();
};

class X86ASMGenerator : public ASMGenerator {
public:
    explicit X86ASMGenerator(char *path, BytecodeStream &bytecodeStream);

public:
    void write() override; // Implement this
private:
    ALWAYS_INLINE void stop();
    ALWAYS_INLINE void bl();
    ALWAYS_INLINE void swap_ref();
    ALWAYS_INLINE void swap();
    ALWAYS_INLINE void add();
    ALWAYS_INLINE void sub();
    ALWAYS_INLINE void div();
    ALWAYS_INLINE void mul();
    ALWAYS_INLINE void mod();
    ALWAYS_INLINE void f_or();
    ALWAYS_INLINE void f_and();
    ALWAYS_INLINE void f_xor();
    ALWAYS_INLINE void lshift();
    ALWAYS_INLINE void rshift();
    ALWAYS_INLINE void pop();
    ALWAYS_INLINE void pop2();
    ALWAYS_INLINE void dup();
    ALWAYS_INLINE void vmcall();
    ALWAYS_INLINE void cnst_0();
    ALWAYS_INLINE void cnst_1();
    ALWAYS_INLINE void cnst_2();
    ALWAYS_INLINE void cnst_3();
    ALWAYS_INLINE void cnst_4();
    ALWAYS_INLINE void astorea();
    ALWAYS_INLINE void aloada();
    ALWAYS_INLINE void str();
    ALWAYS_INLINE void ldr();
    ALWAYS_INLINE void strp();
    ALWAYS_INLINE void cmp_eq();
    ALWAYS_INLINE void cmp_ne();
    ALWAYS_INLINE void cmp_ge();
    ALWAYS_INLINE void cmp_le();
    ALWAYS_INLINE void cmp_gt();
    ALWAYS_INLINE void cmp_lt();
    ALWAYS_INLINE void nop();
    ALWAYS_INLINE void call();
    ALWAYS_INLINE void ret();
    ALWAYS_INLINE void virtualcall();
    ALWAYS_INLINE void align();
};

#endif // BINARYWRITER_ASMGENERATOR_H
