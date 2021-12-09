#include <stdio.h>
#include "../define.h"
#include "version.h"

int version(int argc, const char **argv) {
    puts("wmc - version " WMC_VERSION);
    return 0;
}
