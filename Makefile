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
BONUS_T = checker

# Soures to compile.
SOURCES = $(wildcard source/*.c) main.c
BONUS_S = $(wildcard my_checker/*.c) $(wildcard source/*.c)

# Dir and object files to be created.
OBJ_DIR = objects
BONUS_DIR = bonus
OBJECTS = $(patsubst source/%.c,$(OBJ_DIR)/%.o,$(SOURCES))
BONUS_OBJECTS = $(patsubst checker/%.c,$(BONUS_DIR)/%.o,$(BONUS_S))

# Define these targets as "phony" so Make doesn't confuse them with files.
.PHONY: all clean fclean re

all: $(TARGET) $(BONUS_T)

# Build the executable by linking all the files
$(TARGET): $(OBJECTS)
	@printf "$(BCYAN)$(WHITE) Compiling... $(NC)\n"
	$(CC) $(CFLAGS) $^ -o $@
	@printf "$(BGREEN)$(WHITE) Compilation complete! $(NC)\n"

# Build the executable for checker by linking all the files
$(BONUS_T): $(BONUS_OBJECTS)
	@printf "$(BCYAN)$(WHITE) Compiling checker... $(NC)\n"
	$(CC) $(CFLAGS) $^ -o $@
	@printf "$(BGREEN)$(WHITE) Compilation of checker complete! $(NC)\n"

# Build each object file
$(OBJ_DIR)/%.o: source/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Build each object file for checker
$(BONUS_DIR)/%.o: checker/%.c | $(BONUS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the dir if it isn't there
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(BONUS_DIR):
	mkdir -p $(BONUS_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BONUS_DIR)

fclean: clean
	rm -f $(TARGET) $(BONUS_T)

re: fclean all
