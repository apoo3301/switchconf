/*
** SWITCHCONF, 2024
** switchconf [WSL: Debian]
** File description:
** connect
*/

#include "../../include/ssh.h"

ssh_session connect(const char *hostname, const char *username, const char *password) {
    ssh_session session;
    int rc;

    session = ssh_new();
    if (session == NULL) {
        fprintf(stderr, "Error creating ssh session\n");
        return NULL;
    }
}