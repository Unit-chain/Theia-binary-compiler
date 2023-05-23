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

enum class State
{
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

enum Sign : uchar
{
    unsign = 0x10,
    sign = 0x20
};

///@brief size in bytes!!! (not bits)!!!
enum Argument : uchar
{
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

class ASMGenerator
{
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

protected:
    virtual ALWAYS_INLINE std::shared_ptr<char> stop() = 0;
    //    virtual ALWAYS_INLINE std::shared_ptr<char> go_to() = 0;
    //    virtual ALWAYS_INLINE std::shared_ptr<char> swap() = 0;
    //    virtual ALWAYS_INLINE std::shared_ptr<char> iadd() = 0;
    //    virtual ALWAYS_INLINE std::shared_ptr<char> astorea() = 0;
};

class ARM64ASMGenerator : public ASMGenerator
{
public:
    explicit ARM64ASMGenerator(char *path, BytecodeStream &bytecodeStream);

public:
    void write() override;

private:
    int argument; ///@brief (Argument | Sign)
    uchar loadedArgumentBytes;

private:
    ///@brief ALWAYS_INLINE means that function's body will replace invocation place
    virtual ALWAYS_INLINE std::shared_ptr<char> stop() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> go_to() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> swapref() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> iadd() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> isub() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> idivide() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> imul() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> imod() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> ixor() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> reserved9() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> ilshift() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> irshift() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> pop() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> pop2() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> dup() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> ior() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> iand() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> pshnull() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> sha3() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> balance() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> timestamp() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> blockhash() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> chainid() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> create() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> destruct() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> address() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> invalid() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> icnst_0() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> icnst_1() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> icnst_2() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> icnst_3() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> icnst_4() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u64cnst_0() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u64cnst_1() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> checktype() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u32cnst_0() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u32cnst_1() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u32str_0() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u32str_1() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u32str_2() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u32str_3() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u64str_0() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u64str_1() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u64str_2() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u64str_3() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> astorec() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> aloadc() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u128str_0() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u128str_1() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u128str_2() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u128str_3() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> ldc() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> ild_0() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> ild_1() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> ild_2() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> ild_3() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> swap() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> if_acmpeq() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> if_acmpne() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> if_icmpeq() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> if_icmpge() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> if_icmpgt() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> if_icmple() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> if_icmplt() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> if_icmpne() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> ifeq() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> ifge() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> ifgt() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> ifle() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> iflt() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> ifne() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> ifnonnull() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> ifnull() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> nop() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> reserved74() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> dcnst_0() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> dcnst_1() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> lcnst_0() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> lcnst_1() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> reserved79() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> dadd() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u128cnst_0() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u128cnst_1() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u256cnst_0() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u256cnst_1() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> dsub() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> lsub() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> lmul() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> ldiv() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u256str_0() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u256str_1() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u256str_2() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u256str_3() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> rtcall() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> stcall() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> itfcall() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> spcall() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> lld_0() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> lld_1() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> lld_2() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> lld_3() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> aloadi() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> astorei() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> reserved101() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> dinv() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> ddiv() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> dmul() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> aloadl() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> astorel() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> aloadd() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> astored() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> aloadb() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> astoreb() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> reserved111() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> iinc() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> i2d() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> i2u64() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> i2u128() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> i2u256() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> i2b() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> i2c() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> i2l() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> i2s() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> d2i() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> d2l() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> ireturn() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> lreturn() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> Return() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> areturn() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> New() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> newarray() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> new_mdarray() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> dreturn() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u32return() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u64return() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u128return() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> u256return() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> aloadu32() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> astoreu32() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> aloadu64() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> astoreu64() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> aloadu128() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> astoreu128() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> aloadu256() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> astoreu256() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> aloada() = 0;
    // virtual ALWAYS_INLINE std::shared_ptr<char> astorea() = 0;
};

class X86ASMGenerator : public ASMGenerator
{
public:
    explicit X86ASMGenerator(char *path, BytecodeStream &bytecodeStream);

public:
    void write() override; // Implement this
private:
    ///@brief ALWAYS_INLINE means that function's body will replace invocation place
    ALWAYS_INLINE std::shared_ptr<char> stop() override;
    // ALWAYS_INLINE std::shared_ptr<char> go_to() override;
    // ALWAYS_INLINE std::shared_ptr<char> swapref() override;
    // ALWAYS_INLINE std::shared_ptr<char> iadd() override;
    // ALWAYS_INLINE std::shared_ptr<char> isub() override;
    // ALWAYS_INLINE std::shared_ptr<char> idivide() override;
    // ALWAYS_INLINE std::shared_ptr<char> imul() override;
    // ALWAYS_INLINE std::shared_ptr<char> imod() override;
    // ALWAYS_INLINE std::shared_ptr<char> ixor() override;
    // ALWAYS_INLINE std::shared_ptr<char> reserved9() override;
    // ALWAYS_INLINE std::shared_ptr<char> ilshift() override;
    // ALWAYS_INLINE std::shared_ptr<char> irshift() override;
    // ALWAYS_INLINE std::shared_ptr<char> pop() override;
    // ALWAYS_INLINE std::shared_ptr<char> pop2() override;
    // ALWAYS_INLINE std::shared_ptr<char> dup() override;
    // ALWAYS_INLINE std::shared_ptr<char> ior() override;
    // ALWAYS_INLINE std::shared_ptr<char> iand() override;
    // ALWAYS_INLINE std::shared_ptr<char> pshnull() override;
    // ALWAYS_INLINE std::shared_ptr<char> sha3() override;
    // ALWAYS_INLINE std::shared_ptr<char> balance() override;
    // ALWAYS_INLINE std::shared_ptr<char> timestamp() override;
    // ALWAYS_INLINE std::shared_ptr<char> blockhash() override;
    // ALWAYS_INLINE std::shared_ptr<char> chainid() override;
    // ALWAYS_INLINE std::shared_ptr<char> create() override;
    // ALWAYS_INLINE std::shared_ptr<char> destruct() override;
    // ALWAYS_INLINE std::shared_ptr<char> address() override;
    // ALWAYS_INLINE std::shared_ptr<char> invalid() override;
    // ALWAYS_INLINE std::shared_ptr<char> icnst_0() override;
    // ALWAYS_INLINE std::shared_ptr<char> icnst_1() override;
    // ALWAYS_INLINE std::shared_ptr<char> icnst_2() override;
    // ALWAYS_INLINE std::shared_ptr<char> icnst_3() override;
    // ALWAYS_INLINE std::shared_ptr<char> icnst_4() override;
    // ALWAYS_INLINE std::shared_ptr<char> u64cnst_0() override;
    // ALWAYS_INLINE std::shared_ptr<char> u64cnst_1() override;
    // ALWAYS_INLINE std::shared_ptr<char> checktype() override;
    // ALWAYS_INLINE std::shared_ptr<char> u32cnst_0() override;
    // ALWAYS_INLINE std::shared_ptr<char> u32cnst_1() override;
    // ALWAYS_INLINE std::shared_ptr<char> u32str_0() override;
    // ALWAYS_INLINE std::shared_ptr<char> u32str_1() override;
    // ALWAYS_INLINE std::shared_ptr<char> u32str_2() override;
    // ALWAYS_INLINE std::shared_ptr<char> u32str_3() override;
    // ALWAYS_INLINE std::shared_ptr<char> u64str_0() override;
    // ALWAYS_INLINE std::shared_ptr<char> u64str_1() override;
    // ALWAYS_INLINE std::shared_ptr<char> u64str_2() override;
    // ALWAYS_INLINE std::shared_ptr<char> u64str_3() override;
    // ALWAYS_INLINE std::shared_ptr<char> astorec() override;
    // ALWAYS_INLINE std::shared_ptr<char> aloadc() override;
    // ALWAYS_INLINE std::shared_ptr<char> u128str_0() override;
    // ALWAYS_INLINE std::shared_ptr<char> u128str_1() override;
    // ALWAYS_INLINE std::shared_ptr<char> u128str_2() override;
    // ALWAYS_INLINE std::shared_ptr<char> u128str_3() override;
    // ALWAYS_INLINE std::shared_ptr<char> ldc() override;
    // ALWAYS_INLINE std::shared_ptr<char> ild_0() override;
    // ALWAYS_INLINE std::shared_ptr<char> ild_1() override;
    // ALWAYS_INLINE std::shared_ptr<char> ild_2() override;
    // ALWAYS_INLINE std::shared_ptr<char> ild_3() override;
    // ALWAYS_INLINE std::shared_ptr<char> swap() override;
    // ALWAYS_INLINE std::shared_ptr<char> if_acmpeq() override;
    // ALWAYS_INLINE std::shared_ptr<char> if_acmpne() override;
    // ALWAYS_INLINE std::shared_ptr<char> if_icmpeq() override;
    // ALWAYS_INLINE std::shared_ptr<char> if_icmpge() override;
    // ALWAYS_INLINE std::shared_ptr<char> if_icmpgt() override;
    // ALWAYS_INLINE std::shared_ptr<char> if_icmple() override;
    // ALWAYS_INLINE std::shared_ptr<char> if_icmplt() override;
    // ALWAYS_INLINE std::shared_ptr<char> if_icmpne() override;
    // ALWAYS_INLINE std::shared_ptr<char> ifeq() override;
    // ALWAYS_INLINE std::shared_ptr<char> ifge() override;
    // ALWAYS_INLINE std::shared_ptr<char> ifgt() override;
    // ALWAYS_INLINE std::shared_ptr<char> ifle() override;
    // ALWAYS_INLINE std::shared_ptr<char> iflt() override;
    // ALWAYS_INLINE std::shared_ptr<char> ifne() override;
    // ALWAYS_INLINE std::shared_ptr<char> ifnonnull() override;
    // ALWAYS_INLINE std::shared_ptr<char> ifnull() override;
    // ALWAYS_INLINE std::shared_ptr<char> nop() override;
    // ALWAYS_INLINE std::shared_ptr<char> reserved74() override;
    // ALWAYS_INLINE std::shared_ptr<char> dcnst_0() override;
    // ALWAYS_INLINE std::shared_ptr<char> dcnst_1() override;
    // ALWAYS_INLINE std::shared_ptr<char> lcnst_0() override;
    // ALWAYS_INLINE std::shared_ptr<char> lcnst_1() override;
    // ALWAYS_INLINE std::shared_ptr<char> reserved79() override;
    // ALWAYS_INLINE std::shared_ptr<char> dadd() override;
    // ALWAYS_INLINE std::shared_ptr<char> u128cnst_0() override;
    // ALWAYS_INLINE std::shared_ptr<char> u128cnst_1() override;
    // ALWAYS_INLINE std::shared_ptr<char> u256cnst_0() override;
    // ALWAYS_INLINE std::shared_ptr<char> u256cnst_1() override;
    // ALWAYS_INLINE std::shared_ptr<char> dsub() override;
    // ALWAYS_INLINE std::shared_ptr<char> lsub() override;
    // ALWAYS_INLINE std::shared_ptr<char> lmul() override;
    // ALWAYS_INLINE std::shared_ptr<char> ldiv() override;
    // ALWAYS_INLINE std::shared_ptr<char> u256str_0() override;
    // ALWAYS_INLINE std::shared_ptr<char> u256str_1() override;
    // ALWAYS_INLINE std::shared_ptr<char> u256str_2() override;
    // ALWAYS_INLINE std::shared_ptr<char> u256str_3() override;
    // ALWAYS_INLINE std::shared_ptr<char> rtcall() override;
    // ALWAYS_INLINE std::shared_ptr<char> stcall() override;
    // ALWAYS_INLINE std::shared_ptr<char> itfcall() override;
    // ALWAYS_INLINE std::shared_ptr<char> spcall() override;
    // ALWAYS_INLINE std::shared_ptr<char> lld_0() override;
    // ALWAYS_INLINE std::shared_ptr<char> lld_1() override;
    // ALWAYS_INLINE std::shared_ptr<char> lld_2() override;
    // ALWAYS_INLINE std::shared_ptr<char> lld_3() override;
    // ALWAYS_INLINE std::shared_ptr<char> aloadi() override;
    // ALWAYS_INLINE std::shared_ptr<char> astorei() override;
    // ALWAYS_INLINE std::shared_ptr<char> reserved101() override;
    // ALWAYS_INLINE std::shared_ptr<char> dinv() override;
    // ALWAYS_INLINE std::shared_ptr<char> ddiv() override;
    // ALWAYS_INLINE std::shared_ptr<char> dmul() override;
    // ALWAYS_INLINE std::shared_ptr<char> aloadl() override;
    // ALWAYS_INLINE std::shared_ptr<char> astorel() override;
    // ALWAYS_INLINE std::shared_ptr<char> aloadd() override;
    // ALWAYS_INLINE std::shared_ptr<char> astored() override;
    // ALWAYS_INLINE std::shared_ptr<char> aloadb() override;
    // ALWAYS_INLINE std::shared_ptr<char> astoreb() override;
    // ALWAYS_INLINE std::shared_ptr<char> reserved111() override;
    // ALWAYS_INLINE std::shared_ptr<char> iinc() override;
    // ALWAYS_INLINE std::shared_ptr<char> i2d() override;
    // ALWAYS_INLINE std::shared_ptr<char> i2u64() override;
    // ALWAYS_INLINE std::shared_ptr<char> i2u128() override;
    // ALWAYS_INLINE std::shared_ptr<char> i2u256() override;
    // ALWAYS_INLINE std::shared_ptr<char> i2b() override;
    // ALWAYS_INLINE std::shared_ptr<char> i2c() override;
    // ALWAYS_INLINE std::shared_ptr<char> i2l() override;
    // ALWAYS_INLINE std::shared_ptr<char> i2s() override;
    // ALWAYS_INLINE std::shared_ptr<char> d2i() override;
    // ALWAYS_INLINE std::shared_ptr<char> d2l() override;
    // ALWAYS_INLINE std::shared_ptr<char> ireturn() override;
    // ALWAYS_INLINE std::shared_ptr<char> lreturn() override;
    // ALWAYS_INLINE std::shared_ptr<char> Return() override;
    // ALWAYS_INLINE std::shared_ptr<char> areturn() override;
    // ALWAYS_INLINE std::shared_ptr<char> New() override;
    // ALWAYS_INLINE std::shared_ptr<char> newarray() override;
    // ALWAYS_INLINE std::shared_ptr<char> new_mdarray() override;
    // ALWAYS_INLINE std::shared_ptr<char> dreturn() override;
    // ALWAYS_INLINE std::shared_ptr<char> u32return() override;
    // ALWAYS_INLINE std::shared_ptr<char> u64return() override;
    // ALWAYS_INLINE std::shared_ptr<char> u128return() override;
    // ALWAYS_INLINE std::shared_ptr<char> u256return() override;
    // ALWAYS_INLINE std::shared_ptr<char> aloadu32() override;
    // ALWAYS_INLINE std::shared_ptr<char> astoreu32() override;
    // ALWAYS_INLINE std::shared_ptr<char> aloadu64() override;
    // ALWAYS_INLINE std::shared_ptr<char> astoreu64() override;
    // ALWAYS_INLINE std::shared_ptr<char> aloadu128() override;
    // ALWAYS_INLINE std::shared_ptr<char> astoreu128() override;
    // ALWAYS_INLINE std::shared_ptr<char> aloadu256() override;
    // ALWAYS_INLINE std::shared_ptr<char> astoreu256() override;
    // ALWAYS_INLINE std::shared_ptr<char> aloada() override;
    // ALWAYS_INLINE std::shared_ptr<char> astorea() override;
};

#endif // BINARYWRITER_ASMGENERATOR_H
