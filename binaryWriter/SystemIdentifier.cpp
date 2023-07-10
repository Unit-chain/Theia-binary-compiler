//
// Created by Kirill Zhukov on 21.05.2023.
//

#include "SystemIdentifier.h"


SystemIdentifier::SystemIdentifier() {
    OSFlag os;
#ifdef _WIN32
    os = WINDOWS;
#elif __APPLE__
    os = MACOS;
#elif __linux__
    os = LINUX;
#else
    os = UNKNOWN;
#endif
    this->system = static_cast<uchar>(os) | static_cast<uchar>(getProcessorArchitecture());
}

CPUFlag SystemIdentifier::getProcessorArchitecture() {
#if defined(_WIN32)
    return X86_64;
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

SystemIdentifier &SystemIdentifier::operator=(const SystemIdentifier &other) {
    if (this != &other) {
        this->system = other.system;
    }
    return *this;
}