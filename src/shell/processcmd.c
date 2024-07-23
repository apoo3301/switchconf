/*
** SWITCHCONF, 2024
** switchconf [WSL: Debian]
** File description:
** processcmd
*/

#include "../../include/shell.h"

void process_cmd(ssh_session session) {
    char command[256];

    while (1) {
        printf("$ \033[1;34mssh> \033[0m");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            fprintf(stderr, "\033[1;31mError reading command.\033[0m\n");
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

        if (strcmp(command, "execute") == 0) {
            execute_commands_from_file(session);
            continue;
        }

        fprintf(stderr, "\033[1;31munknown command: %s\033[0m\n", command);
    }
}
