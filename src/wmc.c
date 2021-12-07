#include "parse.h"
#if _POSIX_C_SOURCE >= 2 || _XOPEN_SOURCE
#include <unistd.h>
#else
#include "getopt.h"
#endif

#define ARGS "s:"

int main(int argc, char** argv) {
    if (getopt(argc, argv, ARGS) != -1) {
        return parse_file(optarg);
    } else {
        return parse_line(argc - 1, argv + 1);
    }
}
