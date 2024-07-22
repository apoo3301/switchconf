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

    ssh_options_set(session, SSH_OPTIONS_HOST, hostname);
    ssh_options_set(session, SSH_OPTIONS_USER, username);

    rc = ssh_connect(session);
    if (rc != SSH_OK) {
        fprintf(stderr, "Error connecting to %s: %s\n", hostname, ssh_get_error(session));
        ssh_free(session); //to keep your ram alive
        return NULL;
    }

    rc = ssh_userauth_password(session, NULL, password);
    if (rc != SSH_AUTH_SUCCESS) {
        fprintf(stderr, "Error authenticating with password: %s\n", ssh_get_error(session));
        ssh_disconnect(session);
        ssh_free(session);
        return NULL;
    }

    return session;
}