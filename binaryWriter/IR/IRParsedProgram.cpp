#include "IRParsedProgram.h"

IRParsedProgram::IRParsedProgram(char *path) {
    FILE *fp = fopen(path, "r");
    fseek(fp, SEEK_SET, SEEK_END);
    size_t fs = ftell(fp);
    fseek(fp, SEEK_SET, 0);
    char *buff = static_cast<char *>(std::malloc(fs));
    if (buff == nullptr) {
        throw std::exception("null ptr exception");
    }
    fread(buff, fs, 1, fp);
    std::string str(buff, fs);
    this->program = getFnLines(str);
    std::free(buff);
}

IRParsedProgram::IRParsedProgram(std::string &program) {
    this->program = getFnLines(program);
}

IRFunction IRParsedProgram::at(std::string &name) {
    return this->program.at(name);
}

size_t IRParsedProgram::size() {
    return this->program.size();
}

std::unordered_map<std::string, IRFunction>::iterator IRParsedProgram::begin() {
    return this->program.begin();
}

std::unordered_map<std::string, IRFunction>::iterator IRParsedProgram::end() {
    return this->program.end();
}

void IRParsedProgram::printProgram() {
    for (auto &[funcName, func] : program) {
        std::cout << "function name: " << func.name << ", offset: " << func.offset << "\ninstructions: " << '\n';
        for (Command &command : func.commands) {
            std::cout << "Command: " << command.name << ", flag: " << command.flag << std::endl;
            std::cout << "Arguments: \n";
            for (int i = 0; i < command.args.size(); i++) {
                printf("\targ%d: %s\n", i, command.args[i].c_str());
            }
            std::cout << std::endl;
        }
    }
}

