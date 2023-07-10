#include "errUtils.h"

void closeCompiler(const char *mess) {
    fprintf(stderr, "Error: %s\n", mess);
    exit(EXIT_FAILURE);
}