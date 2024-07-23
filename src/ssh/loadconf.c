/*
** EPITECH PROJECT, 2024
** switchconf [WSL: Debian]
** File description:
** loadconf
*/

#include "../../include/ssh.h"

void load_config(const char *filename, char *username, size_t username_size, char *password, size_t password_size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strncmp(line, "username", 9) == 0) {
            strncpy(username, line + 9, username_size - 1);
            username[strcspn(username, "\n")] = '\0';
        } else if (strncmp(line, "password=", 9) == 0) {
            strncpy(password, line + 9, password_size - 1);
            password[strcspn(password, "\n")] = '\0';
        }
    }

    fclose(file);
}