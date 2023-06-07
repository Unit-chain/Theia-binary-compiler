# Examples
How to use IRParsedProgram:
```c++
#include <iostream>
#include "IR/IRParsedProgram.h"

int main() {
    IRParsedProgram irProgram("/Users/kirillzhukov/Documents/TheiaIR/testFn.txt");
    irProgram.printProgram(); // prints program in readeble format
    // iterating through the parsed program
    // func.command is a vector with parsed instructions
    for (IRFunction &func : irProgram) {
        std::cout << func.name << std::endl;
        // to iterate through instructions, need to use this:
        for (auto Command &c : func.commands) {
            // c contains:
            // name - function name
            // args - vector of arguments
            // flag - conditional flag
        }
    }
    return 0;
}
```
