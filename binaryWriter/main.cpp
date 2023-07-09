#include <iostream>
#include "IR/IRParsedProgram.h"
#include "Opcodes.h"

int main() {
    // can be found in examples folder
    IRParsedProgram irProgram((char *)"C:\\Users\\pasha\\Desktop\\Theia-binary-compiler\\examples\\testFn.txt");
    irProgram.printProgram();
    for (auto &[funcName, func] : irProgram) {
        std::cout << "Function name: " << funcName << ", Function name 2: " << func.name << std::endl;
    }
    std::string fnName = "_main";
    theiaIR::Opcodes op;
    std::cout << "Opcode: " << irProgram.at(fnName).commands.at(0).name << ", index: "
        << (int)op.getIndexByCommand(irProgram.at(fnName).commands.at(0)) << '\n';
    return 0;
}