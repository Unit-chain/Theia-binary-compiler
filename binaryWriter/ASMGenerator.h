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

#define STACKSIZE 8

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
    virtual ALWAYS_INLINE void go_to() = 0;
    virtual ALWAYS_INLINE void swapref() = 0;
    //    virtual ALWAYS_INLINE void iadd() = 0;
    //    virtual ALWAYS_INLINE void isub() = 0;
    //    virtual ALWAYS_INLINE void idivide() = 0;
    //    virtual ALWAYS_INLINE void imul() = 0;
    //    virtual ALWAYS_INLINE void imod() = 0;
    //    virtual ALWAYS_INLINE void ixor() = 0;
    //    virtual ALWAYS_INLINE void reserved9() = 0;
    //    virtual ALWAYS_INLINE void ilshift() = 0;
    //    virtual ALWAYS_INLINE void irshift() = 0;
    //    virtual ALWAYS_INLINE void pop() = 0;
    //    virtual ALWAYS_INLINE void pop2() = 0;
    //    virtual ALWAYS_INLINE void dup() = 0;
    //    virtual ALWAYS_INLINE void ior() = 0;
    //    virtual ALWAYS_INLINE void iand() = 0;
    //    virtual ALWAYS_INLINE void pshnull() = 0;
    //    virtual ALWAYS_INLINE void sha3() = 0;
    //    virtual ALWAYS_INLINE void balance() = 0;
    //    virtual ALWAYS_INLINE void timestamp() = 0;
    //    virtual ALWAYS_INLINE void blockhash() = 0;
    //    virtual ALWAYS_INLINE void chainid() = 0;
    //    virtual ALWAYS_INLINE void create() = 0;
    //    virtual ALWAYS_INLINE void destruct() = 0;
    //    virtual ALWAYS_INLINE void address() = 0;
    //    virtual ALWAYS_INLINE void invalid() = 0;
    //    virtual ALWAYS_INLINE void icnst_0() = 0;
    //    virtual ALWAYS_INLINE void icnst_1() = 0;
    //    virtual ALWAYS_INLINE void icnst_2() = 0;
    //    virtual ALWAYS_INLINE void icnst_3() = 0;
    //    virtual ALWAYS_INLINE void icnst_4() = 0;
    //    virtual ALWAYS_INLINE void u64cnst_0() = 0;
    //    virtual ALWAYS_INLINE void u64cnst_1() = 0;
    //    virtual ALWAYS_INLINE void checktype() = 0;
    //    virtual ALWAYS_INLINE void u32cnst_0() = 0;
    //    virtual ALWAYS_INLINE void u32cnst_1() = 0;
    //    virtual ALWAYS_INLINE void u32str_0() = 0;
    //    virtual ALWAYS_INLINE void u32str_1() = 0;
    //    virtual ALWAYS_INLINE void u32str_2() = 0;
    //    virtual ALWAYS_INLINE void u32str_3() = 0;
    //    virtual ALWAYS_INLINE void u64str_0() = 0;
    //    virtual ALWAYS_INLINE void u64str_1() = 0;
    //    virtual ALWAYS_INLINE void u64str_2() = 0;
    //    virtual ALWAYS_INLINE void u64str_3() = 0;
    //    virtual ALWAYS_INLINE void astorec() = 0;
    //    virtual ALWAYS_INLINE void aloadc() = 0;
    //    virtual ALWAYS_INLINE void u128str_0() = 0;
    //    virtual ALWAYS_INLINE void u128str_1() = 0;
    //    virtual ALWAYS_INLINE void u128str_2() = 0;
    //    virtual ALWAYS_INLINE void u128str_3() = 0;
    //    virtual ALWAYS_INLINE void ldc() = 0;
    //    virtual ALWAYS_INLINE void ild_0() = 0;
    //    virtual ALWAYS_INLINE void ild_1() = 0;
    //    virtual ALWAYS_INLINE void ild_2() = 0;
    //    virtual ALWAYS_INLINE void ild_3() = 0;
    //    virtual ALWAYS_INLINE void swap() = 0;
    //    virtual ALWAYS_INLINE void if_acmpeq() = 0;
    //    virtual ALWAYS_INLINE void if_acmpne() = 0;
    //    virtual ALWAYS_INLINE void if_icmpeq() = 0;
    //    virtual ALWAYS_INLINE void if_icmpge() = 0;
    //    virtual ALWAYS_INLINE void if_icmpgt() = 0;
    //    virtual ALWAYS_INLINE void if_icmple() = 0;
    //    virtual ALWAYS_INLINE void if_icmplt() = 0;
    //    virtual ALWAYS_INLINE void if_icmpne() = 0;
    //    virtual ALWAYS_INLINE void ifeq() = 0;
    //    virtual ALWAYS_INLINE void ifge() = 0;
    //    virtual ALWAYS_INLINE void ifgt() = 0;
    //    virtual ALWAYS_INLINE void ifle() = 0;
    //    virtual ALWAYS_INLINE void iflt() = 0;
    //    virtual ALWAYS_INLINE void ifne() = 0;
    //    virtual ALWAYS_INLINE void ifnonnull() = 0;
    //    virtual ALWAYS_INLINE void ifnull() = 0;
    //    virtual ALWAYS_INLINE void nop() = 0;
    //    virtual ALWAYS_INLINE void reserved74() = 0;
    //    virtual ALWAYS_INLINE void dcnst_0() = 0;
    //    virtual ALWAYS_INLINE void dcnst_1() = 0;
    //    virtual ALWAYS_INLINE void lcnst_0() = 0;
    //    virtual ALWAYS_INLINE void lcnst_1() = 0;
    //    virtual ALWAYS_INLINE void reserved79() = 0;
    //    virtual ALWAYS_INLINE void dadd() = 0;
    //    virtual ALWAYS_INLINE void u128cnst_0() = 0;
    //    virtual ALWAYS_INLINE void u128cnst_1() = 0;
    //    virtual ALWAYS_INLINE void u256cnst_0() = 0;
    //    virtual ALWAYS_INLINE void u256cnst_1() = 0;
    //    virtual ALWAYS_INLINE void dsub() = 0;
    //    virtual ALWAYS_INLINE void lsub() = 0;
    //    virtual ALWAYS_INLINE void lmul() = 0;
    //    virtual ALWAYS_INLINE void ldiv() = 0;
    //    virtual ALWAYS_INLINE void u256str_0() = 0;
    //    virtual ALWAYS_INLINE void u256str_1() = 0;
    //    virtual ALWAYS_INLINE void u256str_2() = 0;
    //    virtual ALWAYS_INLINE void u256str_3() = 0;
    //    virtual ALWAYS_INLINE void rtcall() = 0;
    //    virtual ALWAYS_INLINE void stcall() = 0;
    //    virtual ALWAYS_INLINE void itfcall() = 0;
    //    virtual ALWAYS_INLINE void spcall() = 0;
    //    virtual ALWAYS_INLINE void lld_0() = 0;
    //    virtual ALWAYS_INLINE void lld_1() = 0;
    //    virtual ALWAYS_INLINE void lld_2() = 0;
    //    virtual ALWAYS_INLINE void lld_3() = 0;
    //    virtual ALWAYS_INLINE void aloadi() = 0;
    //    virtual ALWAYS_INLINE void astorei() = 0;
    //    virtual ALWAYS_INLINE void reserved101() = 0;
    //    virtual ALWAYS_INLINE void dinv() = 0;
    //    virtual ALWAYS_INLINE void ddiv() = 0;
    //    virtual ALWAYS_INLINE void dmul() = 0;
    //    virtual ALWAYS_INLINE void aloadl() = 0;
    //    virtual ALWAYS_INLINE void astorel() = 0;
    //    virtual ALWAYS_INLINE void aloadd() = 0;
    //    virtual ALWAYS_INLINE void astored() = 0;
    //    virtual ALWAYS_INLINE void aloadb() = 0;
    //    virtual ALWAYS_INLINE void astoreb() = 0;
    //    virtual ALWAYS_INLINE void reserved111() = 0;
    //    virtual ALWAYS_INLINE void iinc() = 0;
    //    virtual ALWAYS_INLINE void i2d() = 0;
    //    virtual ALWAYS_INLINE void i2u64() = 0;
    //    virtual ALWAYS_INLINE void i2u128() = 0;
    //    virtual ALWAYS_INLINE void i2u256() = 0;
    //    virtual ALWAYS_INLINE void i2b() = 0;
    //    virtual ALWAYS_INLINE void i2c() = 0;
    //    virtual ALWAYS_INLINE void i2l() = 0;
    //    virtual ALWAYS_INLINE void i2s() = 0;
    //    virtual ALWAYS_INLINE void d2i() = 0;
    //    virtual ALWAYS_INLINE void d2l() = 0;
    //    virtual ALWAYS_INLINE void ireturn() = 0;
    //    virtual ALWAYS_INLINE void lreturn() = 0;
    //    virtual ALWAYS_INLINE void Return() = 0;
    //    virtual ALWAYS_INLINE void areturn() = 0;
    //    virtual ALWAYS_INLINE void New() = 0;
    //    virtual ALWAYS_INLINE void newarray() = 0;
    //    virtual ALWAYS_INLINE void new_mdarray() = 0;
    //    virtual ALWAYS_INLINE void dreturn() = 0;
    //    virtual ALWAYS_INLINE void u32return() = 0;
    //    virtual ALWAYS_INLINE void u64return() = 0;
    //    virtual ALWAYS_INLINE void u128return() = 0;
    //    virtual ALWAYS_INLINE void u256return() = 0;
    //    virtual ALWAYS_INLINE void aloadu32() = 0;
    //    virtual ALWAYS_INLINE void astoreu32() = 0;
    //    virtual ALWAYS_INLINE void aloadu64() = 0;
    //    virtual ALWAYS_INLINE void astoreu64() = 0;
    //    virtual ALWAYS_INLINE void aloadu128() = 0;
    //    virtual ALWAYS_INLINE void astoreu128() = 0;
    //    virtual ALWAYS_INLINE void aloadu256() = 0;
    //    virtual ALWAYS_INLINE void astoreu256() = 0;
    //    virtual ALWAYS_INLINE void aloada() = 0;
    //    virtual ALWAYS_INLINE void astorea() = 0;
};

class ARM64ASMGenerator : public ASMGenerator {
public:
    explicit ARM64ASMGenerator(char *path, BytecodeStream &bytecodeStream);

public:
    void write() override;

private:
    int argument; ///@brief (Argument | Sign)
    uchar loadedArgumentBytes;

private:
    ///@brief ALWAYS_INLINE means that function's body will replace invocation place
    ALWAYS_INLINE void stop() override;
    //    ALWAYS_INLINE void go_to() override;
    //    ALWAYS_INLINE void swapref() override;
    //    ALWAYS_INLINE void iadd() override;
    //    ALWAYS_INLINE void isub() override;
    //    ALWAYS_INLINE void idivide() override;
    //    ALWAYS_INLINE void imul() override;
    //    ALWAYS_INLINE void imod() override;
    //    ALWAYS_INLINE void ixor() override;
    //    ALWAYS_INLINE void reserved9() override;
    //    ALWAYS_INLINE void ilshift() override;
    //    ALWAYS_INLINE void irshift() override;
    //    ALWAYS_INLINE void pop() override;
    //    ALWAYS_INLINE void pop2() override;
    //    ALWAYS_INLINE void dup() override;
    //    ALWAYS_INLINE void ior() override;
    //    ALWAYS_INLINE void iand() override;
    //    ALWAYS_INLINE void pshnull() override;
    //    ALWAYS_INLINE void sha3() override;
    //    ALWAYS_INLINE void balance() override;
    //    ALWAYS_INLINE void timestamp() override;
    //    ALWAYS_INLINE void blockhash() override;
    //    ALWAYS_INLINE void chainid() override;
    //    ALWAYS_INLINE void create() override;
    //    ALWAYS_INLINE void destruct() override;
    //    ALWAYS_INLINE void address() override;
    //    ALWAYS_INLINE void invalid() override;
    //    ALWAYS_INLINE void icnst_0() override;
    //    ALWAYS_INLINE void icnst_1() override;
    //    ALWAYS_INLINE void icnst_2() override;
    //    ALWAYS_INLINE void icnst_3() override;
    //    ALWAYS_INLINE void icnst_4() override;
    //    ALWAYS_INLINE void u64cnst_0() override;
    //    ALWAYS_INLINE void u64cnst_1() override;
    //    ALWAYS_INLINE void checktype() override;
    //    ALWAYS_INLINE void u32cnst_0() override;
    //    ALWAYS_INLINE void u32cnst_1() override;
    //    ALWAYS_INLINE void u32str_0() override;
    //    ALWAYS_INLINE void u32str_1() override;
    //    ALWAYS_INLINE void u32str_2() override;
    //    ALWAYS_INLINE void u32str_3() override;
    //    ALWAYS_INLINE void u64str_0() override;
    //    ALWAYS_INLINE void u64str_1() override;
    //    ALWAYS_INLINE void u64str_2() override;
    //    ALWAYS_INLINE void u64str_3() override;
    //    ALWAYS_INLINE void astorec() override;
    //    ALWAYS_INLINE void aloadc() override;
    //    ALWAYS_INLINE void u128str_0() override;
    //    ALWAYS_INLINE void u128str_1() override;
    //    ALWAYS_INLINE void u128str_2() override;
    //    ALWAYS_INLINE void u128str_3() override;
    //    ALWAYS_INLINE void ldc() override;
    //    ALWAYS_INLINE void ild_0() override;
    //    ALWAYS_INLINE void ild_1() override;
    //    ALWAYS_INLINE void ild_2() override;
    //    ALWAYS_INLINE void ild_3() override;
    //    ALWAYS_INLINE void swap() override;
    //    ALWAYS_INLINE void if_acmpeq() override;
    //    ALWAYS_INLINE void if_acmpne() override;
    //    ALWAYS_INLINE void if_icmpeq() override;
    //    ALWAYS_INLINE void if_icmpge() override;
    //    ALWAYS_INLINE void if_icmpgt() override;
    //    ALWAYS_INLINE void if_icmple() override;
    //    ALWAYS_INLINE void if_icmplt() override;
    //    ALWAYS_INLINE void if_icmpne() override;
    //    ALWAYS_INLINE void ifeq() override;
    //    ALWAYS_INLINE void ifge() override;
    //    ALWAYS_INLINE void ifgt() override;
    //    ALWAYS_INLINE void ifle() override;
    //    ALWAYS_INLINE void iflt() override;
    //    ALWAYS_INLINE void ifne() override;
    //    ALWAYS_INLINE void ifnonnull() override;
    //    ALWAYS_INLINE void ifnull() override;
    //    ALWAYS_INLINE void nop() override;
    //    ALWAYS_INLINE void reserved74() override;
    //    ALWAYS_INLINE void dcnst_0() override;
    //    ALWAYS_INLINE void dcnst_1() override;
    //    ALWAYS_INLINE void lcnst_0() override;
    //    ALWAYS_INLINE void lcnst_1() override;
    //    ALWAYS_INLINE void reserved79() override;
    //    ALWAYS_INLINE void dadd() override;
    //    ALWAYS_INLINE void u128cnst_0() override;
    //    ALWAYS_INLINE void u128cnst_1() override;
    //    ALWAYS_INLINE void u256cnst_0() override;
    //    ALWAYS_INLINE void u256cnst_1() override;
    //    ALWAYS_INLINE void dsub() override;
    //    ALWAYS_INLINE void lsub() override;
    //    ALWAYS_INLINE void lmul() override;
    //    ALWAYS_INLINE void ldiv() override;
    //    ALWAYS_INLINE void u256str_0() override;
    //    ALWAYS_INLINE void u256str_1() override;
    //    ALWAYS_INLINE void u256str_2() override;
    //    ALWAYS_INLINE void u256str_3() override;
    //    ALWAYS_INLINE void rtcall() override;
    //    ALWAYS_INLINE void stcall() override;
    //    ALWAYS_INLINE void itfcall() override;
    //    ALWAYS_INLINE void spcall() override;
    //    ALWAYS_INLINE void lld_0() override;
    //    ALWAYS_INLINE void lld_1() override;
    //    ALWAYS_INLINE void lld_2() override;
    //    ALWAYS_INLINE void lld_3() override;
    //    ALWAYS_INLINE void aloadi() override;
    //    ALWAYS_INLINE void astorei() override;
    //    ALWAYS_INLINE void reserved101() override;
    //    ALWAYS_INLINE void dinv() override;
    //    ALWAYS_INLINE void ddiv() override;
    //    ALWAYS_INLINE void dmul() override;
    //    ALWAYS_INLINE void aloadl() override;
    //    ALWAYS_INLINE void astorel() override;
    //    ALWAYS_INLINE void aloadd() override;
    //    ALWAYS_INLINE void astored() override;
    //    ALWAYS_INLINE void aloadb() override;
    //    ALWAYS_INLINE void astoreb() override;
    //    ALWAYS_INLINE void reserved111() override;
    //    ALWAYS_INLINE void iinc() override;
    //    ALWAYS_INLINE void i2d() override;
    //    ALWAYS_INLINE void i2u64() override;
    //    ALWAYS_INLINE void i2u128() override;
    //    ALWAYS_INLINE void i2u256() override;
    //    ALWAYS_INLINE void i2b() override;
    //    ALWAYS_INLINE void i2c() override;
    //    ALWAYS_INLINE void i2l() override;
    //    ALWAYS_INLINE void i2s() override;
    //    ALWAYS_INLINE void d2i() override;
    //    ALWAYS_INLINE void d2l() override;
    //    ALWAYS_INLINE void ireturn() override;
    //    ALWAYS_INLINE void lreturn() override;
    //    ALWAYS_INLINE void Return() override;
    //    ALWAYS_INLINE void areturn() override;
    //    ALWAYS_INLINE void New() override;
    //    ALWAYS_INLINE void newarray() override;
    //    ALWAYS_INLINE void new_mdarray() override;
    //    ALWAYS_INLINE void dreturn() override;
    //    ALWAYS_INLINE void u32return() override;
    //    ALWAYS_INLINE void u64return() override;
    //    ALWAYS_INLINE void u128return() override;
    //    ALWAYS_INLINE void u256return() override;
    //    ALWAYS_INLINE void aloadu32() override;
    //    ALWAYS_INLINE void astoreu32() override;
    //    ALWAYS_INLINE void aloadu64() override;
    //    ALWAYS_INLINE void astoreu64() override;
    //    ALWAYS_INLINE void aloadu128() override;
    //    ALWAYS_INLINE void astoreu128() override;
    //    ALWAYS_INLINE void aloadu256() override;
    //    ALWAYS_INLINE void astoreu256() override;
    //    ALWAYS_INLINE void aloada() override;
    //    ALWAYS_INLINE void astorea() override;
};

class X86ASMGenerator : public ASMGenerator {
public:
    explicit X86ASMGenerator(char *path, BytecodeStream &bytecodeStream);

public:
    void write() override; // Implement this
    void print();
private:
    ///@brief ALWAYS_INLINE means that function's body will replace invocation place
    ALWAYS_INLINE void stop() override;
    ALWAYS_INLINE void go_to() override;
    ALWAYS_INLINE void swapref() override;
    //    ALWAYS_INLINE void iadd() override;
    //    ALWAYS_INLINE void isub() override;
    //    ALWAYS_INLINE void idivide() override;
    //    ALWAYS_INLINE void imul() override;
    //    ALWAYS_INLINE void imod() override;
    //    ALWAYS_INLINE void ixor() override;
    //    ALWAYS_INLINE void reserved9() override;
    //    ALWAYS_INLINE void ilshift() override;
    //    ALWAYS_INLINE void irshift() override;
    //    ALWAYS_INLINE void pop() override;
    //    ALWAYS_INLINE void pop2() override;
    //    ALWAYS_INLINE void dup() override;
    //    ALWAYS_INLINE void ior() override;
    //    ALWAYS_INLINE void iand() override;
    //    ALWAYS_INLINE void pshnull() override;
    //    ALWAYS_INLINE void sha3() override;
    //    ALWAYS_INLINE void balance() override;
    //    ALWAYS_INLINE void timestamp() override;
    //    ALWAYS_INLINE void blockhash() override;
    //    ALWAYS_INLINE void chainid() override;
    //    ALWAYS_INLINE void create() override;
    //    ALWAYS_INLINE void destruct() override;
    //    ALWAYS_INLINE void address() override;
    //    ALWAYS_INLINE void invalid() override;
    //    ALWAYS_INLINE void icnst_0() override;
    //    ALWAYS_INLINE void icnst_1() override;
    //    ALWAYS_INLINE void icnst_2() override;
    //    ALWAYS_INLINE void icnst_3() override;
    //    ALWAYS_INLINE void icnst_4() override;
    //    ALWAYS_INLINE void u64cnst_0() override;
    //    ALWAYS_INLINE void u64cnst_1() override;
    //    ALWAYS_INLINE void checktype() override;
    //    ALWAYS_INLINE void u32cnst_0() override;
    //    ALWAYS_INLINE void u32cnst_1() override;
    //    ALWAYS_INLINE void u32str_0() override;
    //    ALWAYS_INLINE void u32str_1() override;
    //    ALWAYS_INLINE void u32str_2() override;
    //    ALWAYS_INLINE void u32str_3() override;
    //    ALWAYS_INLINE void u64str_0() override;
    //    ALWAYS_INLINE void u64str_1() override;
    //    ALWAYS_INLINE void u64str_2() override;
    //    ALWAYS_INLINE void u64str_3() override;
    //    ALWAYS_INLINE void astorec() override;
    //    ALWAYS_INLINE void aloadc() override;
    //    ALWAYS_INLINE void u128str_0() override;
    //    ALWAYS_INLINE void u128str_1() override;
    //    ALWAYS_INLINE void u128str_2() override;
    //    ALWAYS_INLINE void u128str_3() override;
    //    ALWAYS_INLINE void ldc() override;
    //    ALWAYS_INLINE void ild_0() override;
    //    ALWAYS_INLINE void ild_1() override;
    //    ALWAYS_INLINE void ild_2() override;
    //    ALWAYS_INLINE void ild_3() override;
    //    ALWAYS_INLINE void swap() override;
    //    ALWAYS_INLINE void if_acmpeq() override;
    //    ALWAYS_INLINE void if_acmpne() override;
    //    ALWAYS_INLINE void if_icmpeq() override;
    //    ALWAYS_INLINE void if_icmpge() override;
    //    ALWAYS_INLINE void if_icmpgt() override;
    //    ALWAYS_INLINE void if_icmple() override;
    //    ALWAYS_INLINE void if_icmplt() override;
    //    ALWAYS_INLINE void if_icmpne() override;
    //    ALWAYS_INLINE void ifeq() override;
    //    ALWAYS_INLINE void ifge() override;
    //    ALWAYS_INLINE void ifgt() override;
    //    ALWAYS_INLINE void ifle() override;
    //    ALWAYS_INLINE void iflt() override;
    //    ALWAYS_INLINE void ifne() override;
    //    ALWAYS_INLINE void ifnonnull() override;
    //    ALWAYS_INLINE void ifnull() override;
    //    ALWAYS_INLINE void nop() override;
    //    ALWAYS_INLINE void reserved74() override;
    //    ALWAYS_INLINE void dcnst_0() override;
    //    ALWAYS_INLINE void dcnst_1() override;
    //    ALWAYS_INLINE void lcnst_0() override;
    //    ALWAYS_INLINE void lcnst_1() override;
    //    ALWAYS_INLINE void reserved79() override;
    //    ALWAYS_INLINE void dadd() override;
    //    ALWAYS_INLINE void u128cnst_0() override;
    //    ALWAYS_INLINE void u128cnst_1() override;
    //    ALWAYS_INLINE void u256cnst_0() override;
    //    ALWAYS_INLINE void u256cnst_1() override;
    //    ALWAYS_INLINE void dsub() override;
    //    ALWAYS_INLINE void lsub() override;
    //    ALWAYS_INLINE void lmul() override;
    //    ALWAYS_INLINE void ldiv() override;
    //    ALWAYS_INLINE void u256str_0() override;
    //    ALWAYS_INLINE void u256str_1() override;
    //    ALWAYS_INLINE void u256str_2() override;
    //    ALWAYS_INLINE void u256str_3() override;
    //    ALWAYS_INLINE void rtcall() override;
    //    ALWAYS_INLINE void stcall() override;
    //    ALWAYS_INLINE void itfcall() override;
    //    ALWAYS_INLINE void spcall() override;
    //    ALWAYS_INLINE void lld_0() override;
    //    ALWAYS_INLINE void lld_1() override;
    //    ALWAYS_INLINE void lld_2() override;
    //    ALWAYS_INLINE void lld_3() override;
    //    ALWAYS_INLINE void aloadi() override;
    //    ALWAYS_INLINE void astorei() override;
    //    ALWAYS_INLINE void reserved101() override;
    //    ALWAYS_INLINE void dinv() override;
    //    ALWAYS_INLINE void ddiv() override;
    //    ALWAYS_INLINE void dmul() override;
    //    ALWAYS_INLINE void aloadl() override;
    //    ALWAYS_INLINE void astorel() override;
    //    ALWAYS_INLINE void aloadd() override;
    //    ALWAYS_INLINE void astored() override;
    //    ALWAYS_INLINE void aloadb() override;
    //    ALWAYS_INLINE void astoreb() override;
    //    ALWAYS_INLINE void reserved111() override;
    //    ALWAYS_INLINE void iinc() override;
    //    ALWAYS_INLINE void i2d() override;
    //    ALWAYS_INLINE void i2u64() override;
    //    ALWAYS_INLINE void i2u128() override;
    //    ALWAYS_INLINE void i2u256() override;
    //    ALWAYS_INLINE void i2b() override;
    //    ALWAYS_INLINE void i2c() override;
    //    ALWAYS_INLINE void i2l() override;
    //    ALWAYS_INLINE void i2s() override;
    //    ALWAYS_INLINE void d2i() override;
    //    ALWAYS_INLINE void d2l() override;
    //    ALWAYS_INLINE void ireturn() override;
    //    ALWAYS_INLINE void lreturn() override;
    //    ALWAYS_INLINE void Return() override;
    //    ALWAYS_INLINE void areturn() override;
    //    ALWAYS_INLINE void New() override;
    //    ALWAYS_INLINE void newarray() override;
    //    ALWAYS_INLINE void new_mdarray() override;
    //    ALWAYS_INLINE void dreturn() override;
    //    ALWAYS_INLINE void u32return() override;
    //    ALWAYS_INLINE void u64return() override;
    //    ALWAYS_INLINE void u128return() override;
    //    ALWAYS_INLINE void u256return() override;
    //    ALWAYS_INLINE void aloadu32() override;
    //    ALWAYS_INLINE void astoreu32() override;
    //    ALWAYS_INLINE void aloadu64() override;
    //    ALWAYS_INLINE void astoreu64() override;
    //    ALWAYS_INLINE void aloadu128() override;
    //    ALWAYS_INLINE void astoreu128() override;
    //    ALWAYS_INLINE void aloadu256() override;
    //    ALWAYS_INLINE void astoreu256() override;
    //    ALWAYS_INLINE void aloada() override;
    //    ALWAYS_INLINE void astorea() override;
};

#endif // BINARYWRITER_ASMGENERATOR_H
