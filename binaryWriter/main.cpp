#include <iostream>
#include <string>
#ifdef __APPLE__
#include <sys/param.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#endif
#include "SystemIdentifier.h"
#include "ASMGenerator.h"

int main() {
    std::string tst = "00";
    BytecodeStream bytecodeStream(tst);
    X86ASMGenerator binaryWriter = X86ASMGenerator(tst.data(), bytecodeStream);
    binaryWriter.write();
    binaryWriter.print();
    return 0;
}
