/*
** SWITCHCONF, 2024
** switchconf [WSL: Debian]
** File description:
** main
*/

#include "../include/ssh.h"

int main() {
    const char *hostname = "172.21.51.89"; //ip or domain
    const char *username = "apoo"; //username
    const char *password = "root"; //password

    ssh_session session = ssh_connect_session(hostname, username, password);
    if (session == NULL) {
        fprintf(stderr, "Error connecting to %s\n", hostname);
        return -1;
    }

    printf("Connected to %s\n", hostname);

    ssh_disconnect(session);
    ssh_free(session); //to keep your ram alive bis

    return 0;
}