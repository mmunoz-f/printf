# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 10:46:13 by mmunoz-f          #+#    #+#              #
#    Updated: 2021/02/16 16:20:04 by mmunoz-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SOURCE = ft_printf.c
OBJS_SRC = $(SOURCE:.c=.o)
LIBFTPATH = ./libft
LIBFTA = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS_SRC) lm
	ar -cr $(NAME) $(OBJS_SRC)

lm:
	make -C $(LIBFTPATH)

p: $(OBJS_SRC) $(NAME) lm
	$(CC) $(CFLAGS) -o prueba main.c $(LIBFTA) $(NAME)

clean:
	rm -f *.o
	make fclean -C $(LIBFTPATH)

fclean: clean
	rm -f $(NAME) prueba

re: fclean all

.PHONY: all p lm clean fclean re
