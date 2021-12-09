#include <stdio.h>
#include "commands.h"

typedef struct cmd {
    const char *name;
    int (*func)(const int, const char  **);
} CMD;

int help(const int argc, const char **  argv);

int strcmp(const char *a, const char *b);

static const CMD commands[] = {
        {"help", help},
        {NULL, NULL}
};

int execute(int argc, const char **argv) {
    for (int i = 0; commands[i].name != NULL; i++) {
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

int help(const int argc, const char **  argv) {
    printf("You asked for help with:");
    for (int i = 0; i < argc; i++) {
        printf(" %s", argv[0]);
        argv++;
    }
    printf("\n");
    return 0;
}
