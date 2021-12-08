#include <stdio.h>
#include <string.h>
#include "commands.h"

#define COMMAND_COUNT 2

struct cmd {
    const char *name;
    int (*func)(int, const char**);
    const char **usage;
};

int help(int argc, const char **argv);

static struct cmd commands[COMMAND_COUNT] = {
        {"help", help, (const char*[]){NULL}},
        {"version", version, (const char*[]){NULL}},
};

int execute(int argc, const char **argv) {
    for (int i = 0; i < COMMAND_COUNT; i++) {
        if (!strcmp(argv[0], commands[i].name)) {
            return commands[i].func(argc, argv);
        }
    }
    return -1;
}

int help(int argc, const char **argv) {
    printf("wmc usage:\n");
    for (int i = 0, j = 0; i < COMMAND_COUNT; i++, j = 0) {
        printf("%s", commands[i].name);
        while (commands[i].usage[j] != NULL) {
            printf(" %s", commands[i].usage[j++]);
        }
        printf("\n");
    }
    return 0;
}
