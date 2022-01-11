# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 14:51:49 by mmunoz-f          #+#    #+#              #
#    Updated: 2022/01/11 16:37:53 by mmunoz-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

M =
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
NAME = libft.a
SOURCE = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
	ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_tolower.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_calloc.c ft_strdup.c ft_get_next_line.c \
	ft_strcmp.c ft_atod.c ft_lstfirst.c ft_lstnew.c ft_lstadd_front.c \
	ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS_SOURCE = $(SOURCE:.c=.o)
LIBS = libft.h

all: $(NAME)

$(NAME): $(OBJS_SOURCE)
	ar -cr $(NAME) $(OBJS_SOURCE)

clean:
	rm -f $(OBJS_SOURCE) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

update: fclean
	git add .
	git commit -am "$(M)"
	git push origin master
