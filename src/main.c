/*
** SWITCHCONF, 2024
** switchconf [WSL: Debian]
** File description:
** main
*/

#include "../include/shell.h"
#include "../include/ssh.h"
#include "../include/cli.h"

int main() {
    char ip[256];
    const char *username = "apoo";
    const char *password = "root";

    get_ip_from_user(ip, sizeof(ip));

    ssh_session session = ssh_connect_session(ip, username, password);
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
