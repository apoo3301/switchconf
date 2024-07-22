/*
** SWITCHCONF, 2024
** switchconf [WSL: Debian]
** File description:
** info
*/

#include "../../../include/shell.h"
#include "../../../include/ssh.h"

void infocmd(ssh_session session) {
    const char *hostname;
    const char *username;

    if (ssh_options_get(session, SSH_OPTIONS_HOST, &hostname) != SSH_OK) {
        hostname = "N/A";
    }
    if (ssh_options_get(session, SSH_OPTIONS_USER, &username) != SSH_OK) {
        username = "N/A";
    }

    printf("Session Info:\n");
    printf("  Hostname: %s\n", hostname ? hostname : "N/A");
    printf("  Username: %s\n", username ? username : "N/A");
    printf("  Status: Connected\n");
}