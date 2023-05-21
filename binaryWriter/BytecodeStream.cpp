//
// Created by Kirill Zhukov on 21.05.2023.
//

#include "BytecodeStream.h"

bool BytecodeStream::hasMoreBytes() const {
    return this->currentPosition < this->bytecode.size();
}

unsigned char BytecodeStream::readByte() {
    if (this->currentPosition >= this->bytecode.size()) {
        throw std::out_of_range("No more bytes to read.");
    }
    return this->bytecode[this->currentPosition++];
}

std::string BytecodeStream::readBytes(std::size_t count) {
    if (currentPosition + count > bytecode.size()) {
        throw std::out_of_range("Not enough bytes to read.");
    }

    std::string bytes = bytecode.substr(currentPosition, count);
    currentPosition += count;
    return bytes;
}

uint16_t BytecodeStream::readUInt16() {
    if (currentPosition + 2 > bytecode.size()) {
        throw std::out_of_range("Not enough bytes to read.");
    }

    std::uint16_t value = (static_cast<std::uint16_t>(bytecode[currentPosition]) << 8) |
                          static_cast<std::uint16_t>(bytecode[currentPosition + 1]);
    currentPosition += 2;
    return value;
}

uint32_t BytecodeStream::readUInt32() {
    if (currentPosition + 4 > bytecode.size()) {
        throw std::out_of_range("Not enough bytes to read.");
    }

    std::uint32_t value = (static_cast<std::uint32_t>(bytecode[currentPosition]) << 24) |
                          (static_cast<std::uint32_t>(bytecode[currentPosition + 1]) << 16) |
                          (static_cast<std::uint32_t>(bytecode[currentPosition + 2]) << 8) |
                          static_cast<std::uint32_t>(bytecode[currentPosition + 3]);
    currentPosition += 4;
    return value;
}

std::string BytecodeStream::read2Bytes() {
    std::string bytes = readBytes(2);
    return bytes;
}

std::string BytecodeStream::read4Bytes() {
    std::string bytes = readBytes(4);
    return bytes;
}

std::string BytecodeStream::read8Bytes() {
    std::string bytes = readBytes(8);
    return bytes;
}

