/*
** SWITCHCONF, 2024
** switchconf [WSL: Debian]
** File description:
** main
*/

#include "../include/ssh.h"


int main() {
    const char *hostname = "172.21.51.89";
    const char *username = "apoo";
    const char *password = "root";
    char command[256];

    ssh_session session = ssh_connect_session(hostname, username, password);
    if (session == NULL) {
        fprintf(stderr, "Failed to connect and authenticate.\n");
        return -1;
    }

    printf("succes swith connected and authenticated.\n");

    while (1) {
        printf("ssh> ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            fprintf(stderr, "Error reading command.\n");
            break;
        }

        size_t len = strlen(command);
        if (len > 0 && command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }

        if (strcmp(command, "exit") == 0) {
            break;
        }

        if (strcmp(command, "clear") == 0) {
            clearcmd();
            continue;
        }

        if (strcmp(command, "info") == 0) {
            infocmd(session);
            continue;
        }

        if (strcmp(command, "help") == 0) {
            helpcmd();
            continue;
        }

        if (execute_command(session, command) != SSH_OK) {
            fprintf(stderr, "Error executing command.\n");
        }
    }

    ssh_disconnect(session);
    ssh_free(session);

    return 0;
}