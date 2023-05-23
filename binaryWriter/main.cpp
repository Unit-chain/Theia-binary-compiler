#include <iostream>
#include <string>
#ifdef __APPLE__
#include <sys/param.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#endif
#include "SystemIdentifier.h"
#include "BinaryWriter.h"

int main() {
    std::string tst = "wadawd";
    BytecodeStream bytecodeStream(tst);
    ARM64BinaryWriter binaryWriter = ARM64BinaryWriter(tst.data(), bytecodeStream);
    return 0;
}
