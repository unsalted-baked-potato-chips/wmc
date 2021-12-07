#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "parse.h"

#define LINE_MAX 100
#define COMMAND_MAX 10
#define WORD_MAX LINE_MAX / COMMAND_MAX

int parse_file(char *filename) {
    FILE* in;
    if (!strcmp(filename, "-")) {
        in = stdin;
    } else {
        in = fopen(filename, "r");
        if (in == NULL) {
            fprintf(stderr, "Could not open file: %s\n", filename);
            return -1;
        }
    }
    char* argv[COMMAND_MAX + 1];
    char* line = malloc(sizeof(char) * LINE_MAX);
    int argc = 0;
    while (fgets(line, LINE_MAX, in)) {
        argc = 0;
        argv[argc] = strtok(line, " ");
        while (argv[argc] != NULL) {
            argv[++argc] = strtok(NULL, " ");
        }
        parse_line(argc, argv);
    }
    free(line);
    return 0;
}

int parse_line(int argc, char **argv) {
    printf("command: %s\nargs:", argv[0]);
    for (int i = 1; i < argc; i++) {
        printf(" %s", argv[i]);
    }
    printf("\n");
    return 0;
}
