#include <iostream>
#include "IR/IRParser.h"


int main() {
    std::string code = R"(
        #1 	align 4
        #3 	cnst_2 32
        #4 	cnst_2 32
        #5 	add 32, 32
        #6 	cnst_2 32
        @7: ; offset
        #8 	cmp_ge 32, 32, @12
        #9 	cnst_2 32
        #10	add 32, 32
        #11	bl @7
        @12:
        #13 	ret 0, 0 ; 0, 0 means nothing to be returned, second argument not important in this case
    )";

    std::vector<Command> commands = parseCode(code);

    // print commands
    for (const Command &command : commands) {
        std::cout << "Command: " << command.name << std::endl;
        std::cout << "Arguments: ";
        for (int arg : command.args) {
            std::cout << arg << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
