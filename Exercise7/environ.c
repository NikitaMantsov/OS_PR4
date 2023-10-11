#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printEnvironment() {
    extern char** environ;
    char** env = environ;

    while (*env != NULL) {
        printf("%s\n", *env);
        env++;
    }
}

void printHelp() {
    printf("Usage: environ [OPTIONS]\n");
    printf("Options:\n");
    printf("  -h, --help                Print help message\n");
    printf("  -i, --info <variable>     Print the value of a specified environment variable\n");
    printf("  -s, --set <variable=value> Set the value of a specified environment variable\n");
    printf("  -a, --assign <variable>   Assign a new value to an environment variable\n");
    printf("  -v, --value <value>       The value to assign (use with -a)\n");
    printf("  -d, --del <variable>      Delete a specified environment variable\n");
    printf("  -c, --clear               Clear the entire environment\n");
}

char* getEnvironmentVariable(char* variable) {
    return getenv(variable);
}

void setEnvironmentVariable(char* variable, char* value) {
    if (value != NULL) {
        setenv(variable, value, 1);
    } else {
        setenv(variable, "", 1);
    }
    printf("%s=%s\n", variable, getenv(variable));
}

void deleteEnvironmentVariable(char* variable) {
    unsetenv(variable);
    printf("Deleted: %s\n", variable);
}

void clearEnvironment() {
    clearenv();
    printf("Environment cleared\n");
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        printEnvironment();
    } else if (argc > 1) {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            printHelp();
        } else if (strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "--info") == 0) {
            if (argc < 3) {
                printf("Usage: environ -i <variable>\n");
            } else {
                char* variable = argv[2];
                char* value = getEnvironmentVariable(variable);
                if (value != NULL) {
                    printf("%s=%s\n", variable, value);
                } else {
                    printf("Variable not found: %s\n", variable);
                }
            }
        } else if (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "--set") == 0) {
            if (argc < 3) {
                printf("Usage: environ -s <variable=value>\n");
            } else {
                char* variable = strtok(argv[2], "=");
                char* value = strtok(NULL, "=");
                setEnvironmentVariable(variable, value);
            }
        } else if (strcmp(argv[1], "-a") == 0 || strcmp(argv[1], "--assign") == 0) {
            if (argc < 3) {
                printf("Usage: environ -a <variable> -v <value>\n");
            } else {
                char* variable = argv[2];
                char* value = NULL;
                if (argc > 3 && (strcmp(argv[3], "-v") == 0 || strcmp(argv[3], "--value") == 0)) {
                    value = argv[4];
                }
                setEnvironmentVariable(variable, value);
            }
        } else if (strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--del") == 0) {
            if (argc < 3) {
                printf("Usage: environ -d <variable>\n");
            } else {
                char* variable = argv[2];
                deleteEnvironmentVariable(variable);
            }
        } else if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "--clear") == 0) {
            clearEnvironment();
        }
    }

    return 0;
}
