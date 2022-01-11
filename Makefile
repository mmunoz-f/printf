# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 10:46:13 by mmunoz-f          #+#    #+#              #
#    Updated: 2022/01/11 19:14:09 by mmunoz-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SOURCE = ft_printf.c ft_setformat.c ft_printf_utils.c ft_printf_string.c \
	ft_printf_char.c ft_printf_number.c ft_printf_pointer.c
OBJS_SRC = $(SOURCE:.c=.o)
LIBFT_OBJ = libft/*.o
LIBFTPATH = ./libft
LIBFTA = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS_SRC) lm
	ar -cr $(NAME) $(OBJS_SRC) $(LIBFT_OBJ)

lm:
	make -C $(LIBFTPATH)

clean:
	rm -f *.o
	make fclean -C $(LIBFTPATH)

fclean: clean
	rm -f $(NAME) prueba

re: fclean all

.PHONY: all lm clean fclean re
