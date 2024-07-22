/*
** SWITCHCONF, 2024
** switchconf [WSL: Debian]
** File description:
** main
*/

#include "../include/ssh.h"

int main() {
    const char *hostname = ""; //ip or domain
    const char *username = ""; //username
    const char *password = ""; //password

    ssh_session session = connect(hostname, username, password);
    if (session == NULL) {
        fprintf(stderr, "Error connecting to %s\n", hostname);
        return -1;
    }

    printf("Connected to %s\n", hostname);

    ssh_disconnect(session);
    ssh_free(session); //to keep your ram alive bis

    return 0;
}