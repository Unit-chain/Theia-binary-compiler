#include <iostream>
#include "IR/IRParser.h"


int main() {
    /*
     * command.txt
     * remove slashes before pasting code below
     */

    //#1	align 4
    //#3	cnst_2 32
    //#4	cnst_2 32
    //#5	add 32, 32
    //#6	cnst_2 32
    //    @7: ; offset
    //#8	cmp_ge 32, 32, @12
    //#9	cnst_2 32
    //#10	add 32, 32
    //#11	bl @7
    //    @12:
    //#5	ret 0, 0 ; 0, 0 means nothing to be returned, second argument not important in this case

    /*
     * command.txt
     */

    // need to fill full path
    FILE *fp = fopen("command.txt", "r");
    fseek(fp, SEEK_SET, SEEK_END);
    size_t fs = ftell(fp);
    fseek(fp, SEEK_SET, 0);
    char buff[fs];
    fread(buff, fs, 1, fp);
    std::string code(buff);
    std::vector<Command> commands = parseCode(code);

    for (const Command& command : commands) {
        std::cout << "Command: " << command.name << ", flag: " << command.flag << std::endl;
        std::cout << "Arguments: \n";
        for (int i = 0; i < command.args.size(); i++) {
            printf("\targ%d: %s\n", i, command.args[i].c_str());
        }
        std::cout << std::endl;
    }

    return 0;
}
