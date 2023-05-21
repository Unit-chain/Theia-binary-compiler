//
// Created by Kirill Zhukov on 21.05.2023.
//

#include "SystemIdentifier.h"


SystemIdentifier::SystemIdentifier() {
    OSFlag o;
    #ifdef _WIN32
        this->os = WINDOWS;
    #elif __APPLE__
        o = MACOS;
    #elif __linux__
        this->os = LINUX;
    #else
        this->os = UNKNOWN;
    #endif
    ushort flag = (static_cast<uchar>(o) | static_cast<uchar>(getProcessorArchitecture()));
    printf("Flag: %d\n", flag);
    this->system = flag;
}

CPUFlag SystemIdentifier::getProcessorArchitecture() {
#if defined(_WIN32)
#if defined(_WIN64)
    return X86_64;
#endif
#elif defined(__APPLE__) && defined(__MACH__)
#include <sys/sysctl.h>
    size_t len = 0;
    sysctlbyname("hw.machine", NULL, &len, NULL, 0);
    char *machine = new char[len];
    sysctlbyname("hw.machine", machine, &len, NULL, 0);
    std::string arch(machine);
    delete[] machine;
    if (arch == "arm64" || arch == "aarch64")
        return ARM64;
    else if (arch == "x86_64")
        return X86_64;
    else
        return X86S;
#elif defined(__linux__)
    struct utsname buffer;
    uname(&buffer);
    std::string arch(buffer.machine);
    if (arch == "aarch64")
        return ARM64;
    else if (arch == "x86_64")
        return X86_64;
    else
        return X86S;
#else
    return X86S;
#endif
}