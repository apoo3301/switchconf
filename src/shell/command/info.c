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

    const char *green = "\033[1;32m";  // vert clair
    const char *purple = "\033[1;35m"; // violet clair
    const char *reset = "\033[0m";     // reset la couleur

    printf("╭───┬───────────────────┬──────────────────────────────────────────────╮\n");
    printf("│ %s#%s │ %sField%s             │ %sValue%s                                        │\n", green, reset, green, reset, purple, reset);
    printf("├───┼───────────────────┼──────────────────────────────────────────────┤\n");
    printf("│ %s1%s │ %sHostname%s          │ %s                                 │\n", green, reset, green, reset, hostname ? hostname : "N/A", reset);
    printf("│ %s2%s │ %sUsername%s          │ %s                                         │\n", green, reset, green, reset, username ? username : "N/A", reset);
    printf("│ %s3%s │ %sStatus%s            │ %sConnected%s                                    │\n", green, reset, green, reset, green, reset);
    printf("╰───┴───────────────────┴──────────────────────────────────────────────╯\n");
}