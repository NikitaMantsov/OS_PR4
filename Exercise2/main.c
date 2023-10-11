#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <environment_variable_name>\n", argv[0]);
        return 1;
    }

    char *envVarName = argv[1];
    char *envVarValue = getenv(envVarName);

    if (envVarValue != NULL) {
        printf("The environment variable %s has the value: %s\n", envVarName, envVarValue);
    } else {
        printf("The environment variable %s was not found.\n", envVarName);
    }

    return 0;
}
