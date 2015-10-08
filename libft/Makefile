# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 12:50:41 by tpayet            #+#    #+#              #
#    Updated: 2015/02/25 16:26:04 by tpayet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Wpedantic -O2

SRCS = ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putendl.c \
	   ft_putnbr.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_strlen.c \
	   ft_strdup.c \
	   ft_strcpy.c \
	   ft_strncpy.c \
	   ft_strcat.c \
	   ft_strncat.c \
	   ft_strlcat.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strstr.c \
	   ft_strnstr.c \
	   ft_strcmp.c \
	   ft_strncmp.c \
	   ft_atoi.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_memalloc.c \
	   ft_memdel.c \
	   ft_strnew.c \
	   ft_strdel.c \
	   ft_strclr.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strequ.c \
	   ft_strnequ.c \
	   ft_strjoin.c \
	   ft_itoa.c \
	   ft_strsplit.c \
	   ft_strsub.c \
	   ft_strtrim.c \
	   ft_isspace.c \
	   get_next_line.c \
	   get_line.c \
	   ft_realloc.c \
	   ft_tablen.c

SRCO = $(SRCS:.c=.o)

#shell colors#
RESET = \033[00m
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m

.PHONY: clean fclean re

all: $(NAME)
	@echo "$(NAME) is up to date. $(GREEN)✔$(RESET)"

$(NAME) : $(SRCO)
	@echo -n Linking:
	@ar rc $(NAME) $(SRCO)
	@ranlib $(NAME)
	@echo "$(GREEN) done$(RESET)"

%.o: %.c
	@echo -n Compilation of $< :
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo "$(GREEN) done$(RESET)"

clean:
	@echo -n Removing objects:
	@rm -f $(SRCO)
	@echo "$(GREEN) done$(RESET)"

fclean: clean
	@echo -n Removing binary:
	@rm -f $(NAME)
	@echo "$(GREEN) done$(RESET)"

re: fclean all