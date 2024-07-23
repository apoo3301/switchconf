/*
** SWITCHCONF, 2024
** switchconf [WSL: Debian]
** File description:
** info
*/

#include "../../../include/shell.h"

void helpcmd() {
    const char *green = "\033[1;32m";  // Vert clair
    const char *purple = "\033[1;35m"; // Violet clair
    const char *reset = "\033[0m";     // Réinitialiser la couleur

    printf("╭───┬───────────────────┬────────────────────────────────────────╮\n");
    printf("│ %s#%s │ %sname%s              │ %sdescription%s                            │\n", green, reset, green, reset, purple, reset);
    printf("├───┼───────────────────┼────────────────────────────────────────┤\n");
    printf("│ %s0%s │ %shelp%s              │ %sDisplay this help message%s              │\n", green, reset, green, reset, purple, reset);
    printf("│ %s1%s │ %sinfo%s              │ %sDisplay session information%s            │\n", green, reset, green, reset, purple, reset);
    printf("│ %s2%s │ %sclear%s             │ %sClear the terminal%s                     │\n", green, reset, green, reset, purple, reset);
    printf("│ %s3%s │ %sexecute%s           │ %sExecute command from a file%s            │\n", green, reset, green, reset, purple, reset);
    printf("│ %s4%s │ %sexit%s              │ %sExit the program%s                       │\n", green, reset, green, reset, purple, reset);
    printf("╰───┴───────────────────┴────────────────────────────────────────╯\n");
}