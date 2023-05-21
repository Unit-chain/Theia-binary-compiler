////
//// Created by Kirill Zhukov on 21.05.2023.
////
//
//#ifndef BINARYWRITER_BINARYWRITER_H
//#define BINARYWRITER_BINARYWRITER_H
//#include "memory"
//#include "BytecodeStream.h"
//#include "SystemIdentifier.h"
//
//typedef unsigned char uchar;
//
//enum class State {
//         Idle,
//    Branching,
//        Logic,
//         Math,
//         Jump,
//         Hash,
//      Compare,
//         Load,
//        Array
//};
//
//enum Sign : uchar {
//    unsign = 0x10,
//      sign = 0x20
//};
//
/////@brief size in bytes!!! (not bits)!!!
//enum Argument : uchar {
//     i1 = 0x01, // uint8_t
//     i2 = 0x02, // uint16_t
//     i4 = 0x03, // uint32_t
//     i8 = 0x04, // uint64_t
//    i16 = 0x08, // uint128_t
//    i32 = 0x09  // uint256_t
//};
//
//static inline uchar isSigned(unsigned char symbol) {
//    return (Sign) (symbol & 0xF0);
//}
//
//static inline Argument getArg(unsigned char symbol) {
//    return (Argument) (symbol & 0x0F);
//}
//
//class BinaryWriter {
//public:
//    explicit BinaryWriter(char* path);
//public:
//    virtual void write() = 0;
//    void setBs(BytecodeStream &bs);
//protected:
//    std::shared_ptr<char> path;
//    std::unique_ptr<FILE> fp;
//    State currentState;
//    BytecodeStream bs;
//};
//
//class ARM64BinaryWriter : public BinaryWriter {
//public:
//    explicit ARM64BinaryWriter(char *path);
//public:
//    void write() override;
//private:
//    int argument; ///@brief (Argument | Sign)
//    ushort loadedArgumentBytes;
//private:
//    ///@brief ALWAYS_INLINE means that function's body will replace invocation place
//    ALWAYS_INLINE std::shared_ptr<char> stop();
//    ALWAYS_INLINE std::shared_ptr<char> go_to();
//    ALWAYS_INLINE std::shared_ptr<char> swap();
//    ALWAYS_INLINE std::shared_ptr<char> iadd();
//    /// ...
//    ALWAYS_INLINE std::shared_ptr<char> astorea();
//};
//
//class X86BinaryWriter : public BinaryWriter {
//public:
//    explicit X86BinaryWriter(char *path);
//public:
//    void write() override; // Implement this
//private:
//    ///@brief ALWAYS_INLINE means that function's body will replace invocation place
//    ALWAYS_INLINE std::shared_ptr<char> stop();
//    ALWAYS_INLINE std::shared_ptr<char> go_to();
//    ALWAYS_INLINE std::shared_ptr<char> swap();
//    ALWAYS_INLINE std::shared_ptr<char> iadd();
//    /// ...
//    ALWAYS_INLINE std::shared_ptr<char> astorea();
//};
//
//#endif //BINARYWRITER_BINARYWRITER_H
