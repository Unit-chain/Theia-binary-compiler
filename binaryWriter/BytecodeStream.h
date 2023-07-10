//
// Created by Kirill Zhukov on 21.05.2023.
//

#ifndef BINARYWRITER_BYTECODESTREAM_H
#define BINARYWRITER_BYTECODESTREAM_H

#include "string"
#include "stdexcept"

class BytecodeStream {
private:
    std::string &bytecode;
    std::size_t currentPosition;
public:
    explicit BytecodeStream(std::string &bytecode) : bytecode(bytecode), currentPosition(0) {}

public:
    [[nodiscard]] bool hasMoreBytes() const;

    unsigned char readByte();

    std::string readBytes(std::size_t count);

    std::string read2Bytes();

    std::string read4Bytes();

    std::string read8Bytes();

    uint16_t readUInt16();

    uint32_t readUInt32();

public:
    BytecodeStream &operator=(const BytecodeStream &other) {
        if (this != &other) {
            this->bytecode = other.bytecode;
            this->currentPosition = other.currentPosition;
        }
        return *this;
    }
};


#endif //BINARYWRITER_BYTECODESTREAM_H
