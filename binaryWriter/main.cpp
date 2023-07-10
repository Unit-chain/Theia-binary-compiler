#include <iostream>
#include "IR/IRParsedProgram.h"
#include "Opcodes.h"

int main() {
    // can be found in examples folder
    IRParsedProgram irProgram((char *) "/Users/kirillzhukov/Documents/GitHub/Theia-binary-compiler/examples/testFn.txt");
    irProgram.printProgram();
    for (auto &[funcName, func] : irProgram) {
        std::cout << "Function name: " << funcName << ", Function name 2: " << func.name << std::endl;
    }
    std::string fnName = "_main";
    theiaIR::Opcodes op;
    std::cout << "Opcode: " << irProgram.at(fnName).commands.at(0).name << ", index: "
        << (int)op.getIndexByCommand(irProgram.at(fnName).commands.at(0)) << '\n'
        << "command: " << irProgram.at(fnName).commands.at(5).name
        << ", offset: " << (int) op.getIndexByCommand(irProgram.at(fnName).commands.at(5)) << '\n';
    return 0;
}