/*
** SWICHTCONF, 2024
** switchconf [WSL: Debian]
** File description:
** ssh
*/

#ifndef INCLUDED_SSH_H
    #define INCLUDED_SSH_H

    #include <libssh/libssh.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

    #define CONFIG_FILE "ssh.txt"

    int authentification_password(ssh_session session, const char *password);
    ssh_session ssh_connect_session(const char *hostname, const char *username, const char *password);
    void load_config(const char *filename, char *username, size_t username_size, char *password, size_t password_size);


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
