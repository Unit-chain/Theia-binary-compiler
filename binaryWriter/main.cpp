#include <iostream>
#include "IR/IRParsedProgram.h"


int main() {
    // can be found in examples folder
    IRParsedProgram irProgram((char *) "testFn.txt");
    irProgram.printProgram();
    for (auto& [funcName, func] : irProgram) {
        std::cout << "Function name: " << funcName << ", Function name 2: " << func.name << std::endl;
    }
    return 0;
}
