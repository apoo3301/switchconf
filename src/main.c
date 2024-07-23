/*
** SWITCHCONF, 2024
** switchconf [WSL: Debian]
** File description:
** main
*/

#include "../include/ssh.h"
#include "../include/shell.h"

int main() {
    const char *hostname = "172.21.51.89";
    const char *username = "apoo";
    const char *password = "root";

    ssh_session session = ssh_connect_session(hostname, username, password);
    if (session == NULL) {
        fprintf(stderr, "Failed to connect and authenticate.\n");
        return -1;
    }

    printf("Successfully connected and authenticated.\n");

    process_cmd(session);

    ssh_disconnect(session);
    ssh_free(session);

    return 0;
}
