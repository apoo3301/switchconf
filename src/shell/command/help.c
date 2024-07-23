/*
** SWITCHCONF, 2024
** switchconf [WSL: Debian]
** File description:
** info
*/

#include "../../../include/shell.h"

void helpcmd() {
    printf("Available commands:\n");
    printf("  - help: Display this help message\n");
    printf("  - info: Display session information\n");
    printf("  - clear: Clear the terminal\n");
    printf("  - execute: Execute commands from a file\n");
    printf("  - exit: Exit the program\n");
    printf("\n");
}
