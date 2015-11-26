# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpayet <tpayet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/08 19:08:14 by tpayet            #+#    #+#              #
#    Updated: 2015/10/09 12:38:57 by tpayet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC = clang

CFLAGS = -Wall -Wextra -Werror -Wpedantic -O2

LIBFT = ./libft/

SRCS = main.c \


#shell colors#
RESET = \033[00m
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m

SRCO = $(SRCS:.c=.o)

.PHONY: clean fclean all

all: $(NAME)
	@echo "$(NAME) is up to date. $(GREEN)✔$(RESET)"

$(NAME) : $(SRCO) lib
	@echo -n Linking:
	@$(CC) -o $(NAME) $(SRCO) libft/libft.a
	@echo "$(GREEN) done$(RESET)"

%.o: %.c
	@echo -n Compilation of $< with $(CFLAGS):
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo "$(GREEN) done$(RESET)"

lib:
	@make -C $(LIBFT)
#@echo "$(GREEN)libft is up to date.$(RESET)"

clean :
	@echo -n Removing objects:
	@rm -f $(SRCO)
	@echo "$(GREEN) done$(RESET)"

fclean : clean
	@echo -n Removing binary:
	@rm -f $(NAME)
	@echo "$(GREEN) done$(RESET)"

re : fclean all
