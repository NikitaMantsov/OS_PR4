#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc == 1) {
        if (clearenv() == 0) {
            printf("All environment variables have been cleared.\n");
        } else {
            printf("Error clearing environment variables.\n");
            return 1;
        }
    } else if (argc == 2) {

        char *envVarName = argv[1];
        if (unsetenv(envVarName) == 0) {
            printf("Environment variable %s has been removed.\n", envVarName);
        } else {
            printf("Error removing environment variable.\n");
            return 1;
        }
    } else {
        printf("Usage: %s [<environment_variable_name>]\n", argv[0]);
        return 1;
    }

    extern char **environ;
    int i = 0;
    while (environ[i] != NULL) {
        printf("%s\n", environ[i]);
        i++;
    }

    return 0;
}
