cmake_minimum_required(VERSION 3.25)
project(binaryWriter)

set(CMAKE_CXX_STANDARD 20)

add_executable(binaryWriter main.cpp SystemIdentifier.cpp SystemIdentifier.h ASMGenerator.h BinaryWriter.cpp BytecodeStream.cpp BytecodeStream.h Opcodes.h)
