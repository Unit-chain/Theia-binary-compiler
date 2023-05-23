#include <iostream>
#include <string>
#ifdef __APPLE__
#include <sys/param.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#endif
#include "SystemIdentifier.h"
#include "ASMGenerator.h"
#include <mach-o/loader.h>

int main() {
    std::string tst = "wadawd";
    BytecodeStream bytecodeStream(tst);
    ARM64ASMGenerator binaryWriter = ARM64ASMGenerator(tst.data(), bytecodeStream);
    return 0;
}
