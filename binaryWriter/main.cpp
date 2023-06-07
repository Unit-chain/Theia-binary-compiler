#include <iostream>
#include "IR/Parse/IRParsedProgram.h"


int main() {
    // can be found in examples folder
    IRParsedProgram irProgram("testFn.txt");
    irProgram.printProgram();
    for (IRFunction &func : irProgram) {
        std::cout << func.name << std::endl;
    }
    return 0;
}
