/*
** EPITECH PROJECT, 2024
** switchconf [WSL: Debian]
** File description:
** shell
*/

#ifndef INCLUDED_SHELL_H
    #define INCLUDED_SHELL_H

    #include <libssh/libssh.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

    #define COMMAND_FILE "./config/command.txt"
    #define LOG_FILE "./logs/output.log"

    void clearcmd(void);
    void execute_commands_from_file(ssh_session session);
    void helpcmd(void);
    void infocmd(ssh_session session);
    int execute_command(ssh_session session, const char *command);
    void process_cmd(ssh_session session);

#endif

/* -------------------------------------------------------------------------- **
**                                                                            **
** MIT License                                                                **
** Copyright (c) 2024 Anonymous                                               **
**                                                                            **
** Permission is hereby granted, free of charge, to any person obtaining a    **
** copy of this software and associated documentation files (the "Software"), **
** to deal in the Software without restriction, including without limitation  **
** the rights to use, copy, modify, merge, publish, distribute, sublicense,   **
** and/or sell copies of the Software, and to permit persons to whom the      **
** Software is furnished to do so, subject to the following conditions:       **
**                                                                            **
** The above copyright notice and this permission notice shall be included in **
** all copies or substantial portions of the Software.                        **
**                                                                            **
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR **
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   **
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL    **
** THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER **
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING    **
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER        **
** DEALINGS IN THE SOFTWARE.                                                  **
**                                                                            **
** -------------------------------------------------------------------------- */
