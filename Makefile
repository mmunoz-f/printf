# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 10:46:13 by mmunoz-f          #+#    #+#              #
#    Updated: 2021/02/22 18:27:25 by mmunoz-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SOURCE = ft_printf.c ft_setformat.c ft_printf_utils.c ft_printf_string.c \
	ft_printf_char.c ft_printf_number.c ft_printf_pointer.c
OBJS_SRC = $(SOURCE:.c=.o)
LIBFTPATH = ./libft
LIBFTA = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS_SRC) lm
	ar -cr $(NAME) $(OBJS_SRC) libft/*.o

lm:
	make -C $(LIBFTPATH)

p: $(NAME) $(OBJS_SRC)
	$(CC) $(CFLAGS) -o prueba main.c $(LIBFTA) $(NAME)

clean:
	rm -f *.o
	make fclean -C $(LIBFTPATH)

fclean: clean
	rm -f $(NAME) prueba

re: fclean all

.PHONY: all p lm clean fclean re
