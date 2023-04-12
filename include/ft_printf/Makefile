# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dberehov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 17:26:46 by dberehov          #+#    #+#              #
#    Updated: 2022/12/02 17:26:47 by dberehov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIBFT = libft

SOURCES = ft_printf.c srcs/ft_print_hexa.c srcs/ft_print_nums.c \
					  srcs/ft_print_pntr.c srcs/ft_print_text.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIBFT)
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar rc $(NAME) $(OBJECTS)

clean:
	make clean -C $(LIBFT)
	rm -rf srcs/*.o *.o

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all