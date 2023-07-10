cmake_minimum_required(VERSION 3.25)
project(binaryWriter)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        IR
        utils
)

add_executable(
        binaryWriter
        main.cpp
        SystemIdentifier.cpp
        ASMGenerator.cpp
        BytecodeStream.cpp
        Opcodes.cpp
        IR/IRCommandParser.cpp
        IR/IRFunctionParser.cpp
        IR/IRParsedProgram.cpp
        utils/errutils.cpp
        utils/strutils.cpp
        CFG/Graph.cpp
)
