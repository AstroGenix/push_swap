# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dberehov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 11:00:19 by dberehov          #+#    #+#              #
#    Updated: 2023/05/12 12:20:01 by dberehov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags.
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Colorize the output of the makefile
BGREEN = \033[0;42m
BCYAN = \033[0;46m
WHITE = \033[37m
NC = \033[0m

# Executable name.
TARGET = push_swap

# Soures to compile.
SOURCES = $(wildcard source/*.c) main.c
#BONUS_S = $(wildcard checker/*.c)

# Dir and object files to be created.
OBJ_DIR = objects
#BONUS_DIR = bonus
OBJECTS = $(patsubst source/%.c,$(OBJ_DIR)/%.o,$(SOURCES))
#BONUS_DIR = $(patsubst checker)

# Define these targets as "phony" so Make doesn't confuse them with files.
.PHONY: all clean fclean re

all: $(TARGET)

# Build the executable by linking all the files
$(TARGET): $(OBJECTS)
	@printf "$(BCYAN)$(WHITE) Compiling... $(NC)\n"
	$(CC) $(CFLAGS) $^ -o $@
	@printf "$(BGREEN)$(WHITE) Compilation complete! $(NC)\n"

# Build each object file
$(OBJ_DIR)/%.o: source/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the dir if it isn't there
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all
