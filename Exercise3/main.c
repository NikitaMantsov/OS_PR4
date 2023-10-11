#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <environment_variable_name> <value>\n", argv[0]);
        return 1;
    }

    char *envVarName = argv[1];
    char *envVarValue = argv[2];

    if (setenv(envVarName, envVarValue, 1) == 0) {
        printf("Environment variable %s set to %s\n", envVarName, envVarValue);
    } else {
        printf("Error setting environment variable.\n");
        return 1;
    }

    char *newEnvVarValue = getenv(envVarName);
    if (newEnvVarValue != NULL) {
        printf("New value of environment variable %s is: %s\n", envVarName, newEnvVarValue);
    } else {
        printf("Environment variable %s not found.\n", envVarName);
    }

    return 0;
}

