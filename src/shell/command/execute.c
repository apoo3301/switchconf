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
        fprintf(stderr, "Error opening command file.\n");
        return;
    }

    if (!log_file) {
        fprintf(stderr, "Error opening log file.\n");
        return;
    }

    char command[256];
}