# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dberehov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 11:00:19 by dberehov          #+#    #+#              #
#    Updated: 2023/03/14 11:00:33 by dberehov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC     = cc
CFLAGS = -Wall -Werror -Wextra
NAME   = push_swap.a

SOURCES  = main.c source/input_check.c source/utils.c source/push.c            \
			source/rotate.c source/swap.c source/reverse_rotate.c              \
			source/stack_utils.c source/stack_create.c source/sort.c

OBJECTS = $(SOURCES:.c=.o) 

all: $(NAME)

$(NAME): $(OBJECTS) 
		$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all