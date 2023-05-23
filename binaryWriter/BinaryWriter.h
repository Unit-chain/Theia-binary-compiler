//
// Created by Kirill Zhukov on 21.05.2023.
//

#ifndef BINARYWRITER_BINARYWRITER_H
#define BINARYWRITER_BINARYWRITER_H
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
     i1 = 0x01, // uint8_t
     i2 = 0x02, // uint16_t
     i4 = 0x03, // uint32_t
     i8 = 0x04, // uint64_t
    i16 = 0x08, // uint128_t
    i32 = 0x09  // uint256_t
};

//ALWAYS_INLINE uchar isSigned(unsigned char symbol) {
//    return (Sign) (symbol & 0xF0);
//}
//
//ALWAYS_INLINE Argument getArg(unsigned char symbol) {
//    return (Argument) (symbol & 0x0F);
//}

class BinaryWriter {
public:
    virtual ~BinaryWriter();

    BinaryWriter(char* path, BytecodeStream &bytecodeStream);
public:
    virtual void write() = 0;
    void setBs(BytecodeStream &bs);
protected:
    std::string path;
    FILE *fp;
    State currentState;
    BytecodeStream bs;
protected:
    virtual ALWAYS_INLINE std::shared_ptr<char> stop() = 0;
//    virtual ALWAYS_INLINE std::shared_ptr<char> go_to() = 0;
//    virtual ALWAYS_INLINE std::shared_ptr<char> swap() = 0;
//    virtual ALWAYS_INLINE std::shared_ptr<char> iadd() = 0;
//    virtual ALWAYS_INLINE std::shared_ptr<char> astorea() = 0;
};

class ARM64BinaryWriter : public BinaryWriter {
public:
    explicit ARM64BinaryWriter(char *path, BytecodeStream &bytecodeStream);
public:
    void write() override;
private:
    int argument; ///@brief (Argument | Sign)
    uchar loadedArgumentBytes;
private:
    ///@brief ALWAYS_INLINE means that function's body will replace invocation place
    ALWAYS_INLINE std::shared_ptr<char> stop() override;
//    ALWAYS_INLINE std::shared_ptr<char> go_to() override;
//    ALWAYS_INLINE std::shared_ptr<char> swap() override;
//    ALWAYS_INLINE std::shared_ptr<char> iadd() override;
//    ALWAYS_INLINE std::shared_ptr<char> astorea() override;
};

class X86BinaryWriter : public BinaryWriter {
public:
    explicit X86BinaryWriter(char *path, BytecodeStream &bytecodeStream);
public:
    void write() override; // Implement this
private:
    ///@brief ALWAYS_INLINE means that function's body will replace invocation place
    ALWAYS_INLINE std::shared_ptr<char> stop() override;
//    ALWAYS_INLINE std::shared_ptr<char> go_to() override;
//    ALWAYS_INLINE std::shared_ptr<char> swap() override;
//    ALWAYS_INLINE std::shared_ptr<char> iadd() override;
//    ALWAYS_INLINE std::shared_ptr<char> astorea() override;
};

#endif //BINARYWRITER_BINARYWRITER_H
