#include <string.h>
#include <stdio.h>
#include "commands.h"
#include "parse.h"

#define LINE_MAX 100
#define COMMAND_MAX 10

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
    char line[LINE_MAX];
    for (int argc = 0; fgets(line, LINE_MAX, in); argc = 0) {
        if (line[0] == '#') {
            continue;
        }
        argv[argc] = strtok(line, " \n");
        while (argv[argc] != NULL) {
            argv[++argc] = strtok(NULL, " \n");
        }
        if (parse_line(argc, argv) < 0) {
            fprintf(stderr, "Error on line: %s\n", line);
            return -1;
        }
    }
    return 0;
}

int parse_line(int argc, const char **argv) {
    if (argc == 0) {
        fprintf(stderr, "No command given\n");
    } else if (execute(argc, argv) < 0) {
        fprintf(stderr, "Invalid command: %s\n", argv[0]);
        return -1;
    } else {
       return 0;
    }
}
