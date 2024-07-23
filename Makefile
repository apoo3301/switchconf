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

# Liste des fichiers sources
SRCS = $(SRC_DIR)/main.c \
	$(SRC_DIR)/cli/gethost.c \
       $(SRC_DIR)/ssh/auth.c \
       $(SRC_DIR)/ssh/connect.c \
       $(SRC_DIR)/ssh/loadconf.c \
       $(SRC_DIR)/shell/execmd.c \
	$(SRC_DIR)/shell/processcmd.c \
       $(SRC_DIR)/shell/command/info.c \
       $(SRC_DIR)/shell/command/clear.c \
       $(SRC_DIR)/shell/command/help.c \
       $(SRC_DIR)/shell/command/execute.c

# Liste des fichiers objets
OBJS = $(OBJ_DIR)/main.o \
	$(OBJ_DIR)/cli/gethost.o \
       $(OBJ_DIR)/ssh/auth.o \
       $(OBJ_DIR)/ssh/connect.o \
       $(OBJ_DIR)/ssh/loadconf.o \
       $(OBJ_DIR)/shell/execmd.o \
	$(OBJ_DIR)/shell/processcmd.o \
       $(OBJ_DIR)/shell/command/info.o \
       $(OBJ_DIR)/shell/command/clear.o \
       $(OBJ_DIR)/shell/command/help.o \
       $(OBJ_DIR)/shell/command/execute.o

# Règle principale
all: $(BIN)

# Règle pour construire l'exécutable
$(BIN): $(OBJS)
	$(CC) $(OBJS) -o $(BIN) $(LDFLAGS)

# Règle pour compiler les fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)  # Assurez-vous que le répertoire existe
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJ_DIR)/*.o $(BIN)
