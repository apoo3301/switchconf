## ----------------------------------------------------------------------------------- ##
##                                                                                     ##
## IGYMARINA SCRIPT - Tue, Jul, 2024                                                    ##
## Title            - switchconf [WSL: Debian]                                          ##
## Description      -                                                                   ##
##     Makefile                                                                        ##
##                                                                                     ##
## ----------------------------------------------------------------------------------- ##
##                                                                                     ##
##       ▄▀▀█▄▄▄▄  ▄▀▀▄▀▀▀▄  ▄▀▀█▀▄    ▄▀▀▀█▀▀▄  ▄▀▀█▄▄▄▄  ▄▀▄▄▄▄   ▄▀▀▄ ▄▄            ##
##      ▐  ▄▀   ▐ █   █   █ █   █  █  █    █  ▐ ▐  ▄▀   ▐ █ █    ▌ █  █   ▄▀           ##
##        █▄▄▄▄▄  ▐  █▀▀▀▀  ▐   █  ▐  ▐   █       █▄▄▄▄▄  ▐ █      ▐  █▄▄▄█            ##
##        █    ▌     █          █        █        █    ▌    █         █   █            ##
##       ▄▀▄▄▄▄    ▄▀        ▄▀▀▀▀▀▄   ▄▀        ▄▀▄▄▄▄    ▄▀▄▄▄▄▀   ▄▀  ▄▀            ##
##       █    ▐   █         █       █ █          █    ▐   █     ▐   █   █              ##
##       ▐        ▐         ▐       ▐ ▐          ▐        ▐         ▐   ▐              ##
##                                                                                     ##
## ----------------------------------------------------------------------------------- ##

CC = gcc
CFLAGS = -g3 -Iinclude
LDFLAGS = -lssh

SRC_DIR = src
OBJ_DIR = obj
BIN = switchconff

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/ssh/auth.c $(SRC_DIR)/ssh/connect.c $(SRC_DIR)/shell/execmd.c $(SRC_DIR)/shell/command/info.c
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/ssh/auth.o $(OBJ_DIR)/ssh/connect.o $(SRC_DIR)/shell/execmd.o $(SRC_DIR)/shell/command/info.c

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(OBJS) -o $(BIN) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN)
