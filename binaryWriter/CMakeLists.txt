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
        SystemIdentifier.h
        ASMGenerator.h
        ASMGenerator.cpp
        BytecodeStream.cpp
        BytecodeStream.h
        Opcodes.h
        IR/IRCommandParser.h
        IR/IRFunctionParser.h
        IR/IRParsedProgram.h
        utils/errutils.h
        utils/strutils.h
)
