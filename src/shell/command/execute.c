/*
** EPITECH PROJECT, 2024
** switchconf [WSL: Debian]
** File description:
** execute
*/

#include "../../../include/shell.h"

void execute_commands_from_file(ssh_session session) {
    FILE *cmd_file = fopen(COMMAND_FILE, "r");
    FILE *log_file = fopen(LOG_FILE, "w");

    if (!cmd_file) {
        fprintf(stderr, "Error opening command file: %s\n", COMMAND_FILE);
        return;
    }

    if (!log_file) {
        fprintf(stderr, "Error opening log file: %s\n", LOG_FILE);
        fclose(cmd_file);
        return;
    }

    char command[256];
    int all_success = 1;
    while (fgets(command, sizeof(command), cmd_file) != NULL) {
        size_t len = strlen(command);
        if (len > 0 && command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }

        if (strlen(command) == 0) {
            continue;
        }

        ssh_channel channel = ssh_channel_new(session);
        if (channel == NULL) {
            fprintf(stderr, "Error creating channel.\n");
            all_success = 0;
            break;
        }

        if (ssh_channel_open_session(channel) != SSH_OK) {
            fprintf(stderr, "Error opening channel.\n");
            ssh_channel_free(channel);
            all_success = 0;
            break;
        }

        if (ssh_channel_request_exec(channel, command) != SSH_OK) {
            fprintf(stderr, "Error executing command: %s\n", command);
            ssh_channel_close(channel);
            ssh_channel_free(channel);
            all_success = 0;
            continue;
        }

        char buffer[256];
        int nbytes;
        while ((nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0)) > 0) {
            fwrite(buffer, 1, nbytes, log_file);
            fwrite(buffer, 1, nbytes, stdout);
        }

        if (nbytes < 0) {
            fprintf(stderr, "Error reading channel.\n");
            all_success = 0;
        }

        ssh_channel_send_eof(channel);
        ssh_channel_close(channel);
        ssh_channel_free(channel);
    }

    fclose(cmd_file);
    fclose(log_file);

    if (all_success) {
        printf("All commands executed successfully.\n");
    } else {
        printf("Some commands failed to execute.\n");
    }
}
