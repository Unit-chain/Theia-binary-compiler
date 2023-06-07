cmake_minimum_required(VERSION 3.25)
project(binaryWriter)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        IR
        IR/Parse
        IR/utils
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
        IR/Parse/IRCommandParser.h
        IR/Parse/IRFunctionParser.h
        IR/Parse/IRParsedProgram.h
        IR/utils/errutils.h
        IR/utils/strutils.h
)
