#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

int main() {
    char hostname[256]; // Максимальна довжина імені мережі (256 символів)
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        printf("Hostname: %s\n", hostname);
    } else {
        perror("Error retrieving hostname");
    }

    struct utsname systemInfo;
    if (uname(&systemInfo) == 0) {
        printf("System Information:\n");
        printf("System Name: %s\n", systemInfo.sysname);
        printf("Node Name: %s\n", systemInfo.nodename);
        printf("Release: %s\n", systemInfo.release);
        printf("Version: %s\n", systemInfo.version);
        printf("Machine: %s\n", systemInfo.machine);
    } else {
        perror("Error retrieving system information");
    }

    return 0;
}
