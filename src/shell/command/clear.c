/*
** EPITECH PROJECT, 2024
** switchconf [WSL: Debian]
** File description:
** clear
*/

#include "../../../include/shell.h"

void clearcmd() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
