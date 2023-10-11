#include <stdio.h>
#include <pwd.h>
#include <unistd.h>

int main() {
    struct passwd *currentUser = getpwuid(getuid());

    if (currentUser != NULL) {
        printf("Information about the current user:\n");
        printf("User Name: %s\n", currentUser->pw_name);
        printf("User ID (UID): %d\n", currentUser->pw_uid);
        printf("Group ID (GID): %d\n", currentUser->pw_gid);
        printf("Home Directory: %s\n", currentUser->pw_dir);
        printf("User's Full Name: %s\n", currentUser->pw_gecos);
    } else {
        perror("Error retrieving information about the current user");
    }

    struct passwd *rootUser = getpwnam("root");

    if (rootUser != NULL) {
        printf("\nInformation about the 'root' user:\n");
        printf("User Name: %s\n", rootUser->pw_name);
        printf("User ID (UID): %d\n", rootUser->pw_uid);
        printf("Group ID (GID): %d\n", rootUser->pw_gid);
        printf("Home Directory: %s\n", rootUser->pw_dir);
        printf("User's Full Name: %s\n", rootUser->pw_gecos);
    } else {
        perror("Error retrieving information about the 'root' user");
    }

    return 0;
}
