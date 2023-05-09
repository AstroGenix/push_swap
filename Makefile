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

SOURCES  = main.c source/cost_utils.c source/cost.c source/input_check.c         \
			source/position.c source/push.c source/reverse_rotate.c              \
			source/rotate.c source/sort_utils.c source/sort.c                    \
			source/stack_create.c source/stack_utils.c source/swap.c             \
			source/utils.c

OBJECTS = $(SOURCES:.c=.o) 

all: $(NAME)

$(NAME): $(OBJECTS) 
		$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
		rm -f $(OBJECTS) *.a

fclean: clean
		rm -f $(NAME)

re: fclean all