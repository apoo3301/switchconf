/*
** SWITCHCONF, 2024
** switchconf [WSL: Debian]
** File description:
** gethost
*/

#include "../../include/cli.h"

void get_ip_from_user(char *ip, size_t size) {
    printf("Please enter the IP address: ");
    if (fgets(ip, size, stdin) == NULL) {
        fprintf(stderr, "Error reading IP address.\n");
        exit(EXIT_FAILURE);
    }

    size_t len = strlen(ip);
    if (len > 0 && ip[len - 1] == '\n') {
        ip[len - 1] = '\0';
    }

    FILE *file = fopen("config/ip.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "ip: %s\n", ip);
    fclose(file);
}