#include <stdio.h>
#include "commands.h"

#define COMMAND_COUNT 1

struct cmd {
    const char *name;
    int (*func)(int, const char**);
};

int help(int argc, const char **argv);

int strcmp(const char *a, const char *b);

static struct cmd commands[COMMAND_COUNT] = {
        {"help", help},
};

int execute(int argc, const char **argv) {
    for (int i = 0; i < COMMAND_COUNT; i++) {
        if (!strcmp(argv[0], commands[i].name)) {
            return commands[i].func(argc, argv);
        }
    }
    return -1;
}

int strcmp(const char *a, const char *b) {
    for (int i = 0; a[i] == b[i]; i++) {
        if (a[i] == 0) {
                return 0;
        }
    }
    return 1;
}

int help(int argc, const char **argv) {
    printf("You asked for help with:");
    for (int i = 0; i < argc; i++) {
        printf(" %s", argv[0]);
        argv++;
    }
    printf("\n");
    return 0;
}