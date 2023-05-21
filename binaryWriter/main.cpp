#include <iostream>
#include <string>
#ifdef __APPLE__
#include <sys/param.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#endif
#include "SystemIdentifier.h"

int main() {
    SystemIdentifier si = SystemIdentifier();
    std::cout << "System: 0x" << std::hex << si.system << std::endl;
    return 0;
}
