/*
** SWITCHCONF, 2024
** switchconf [WSL: Debian]
** File description:
** auth
*/

#include "../../include/ssh.h" 

int authentification_password(ssh_session session, const char *password) {
    int rc = ssh_userauth_password(session, NULL, password);
    if (rc == SSH_AUTH_SUCCESS) {
        printf("Authentification success\n");
        return 0;
    } else {
        printf("Authentification failed\n");
        return 1;
    }
}
