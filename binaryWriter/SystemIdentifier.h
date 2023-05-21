//
// Created by Kirill Zhukov on 21.05.2023.
//

#ifndef BINARYWRITER_SYSTEMIDENTIFIER_H
#define BINARYWRITER_SYSTEMIDENTIFIER_H
#include "string"
#include "iostream"

#ifdef __APPLE__

#include <sys/param.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#define ALWAYS_INLINE __attribute__((always_inline))

#elifdef __linux__

#include <sys/utsname.h>
#define ALWAYS_INLINE __attribute__((always_inline))

#elifdef _WIN32

#define ALWAYS_INLINE __forceinline

#endif

typedef unsigned char uchar;

enum OSFlag : uchar {
      LINUX = 0x01,
      MACOS = 0x02,
    WINDOWS = 0x03,
    UNKNOWN = 0x04
};

enum CPUFlag : uchar {
     ARM64 = 0x10,
    X86_64 = 0x20,
      X86S = 0x30, // Not implemented yet by Intel
};

static inline OSFlag getOS(uchar symbol) {
    return (OSFlag) (symbol & 0x0F);
}

static inline CPUFlag getCPU(uchar symbol) {
    return (CPUFlag) (symbol & 0xF0);
}

class SystemIdentifier {
public:
    explicit SystemIdentifier();
public:
    uchar system;
private:
    static CPUFlag getProcessorArchitecture();
};

#endif //BINARYWRITER_SYSTEMIDENTIFIER_H
