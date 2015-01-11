# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/11 09:30:28 by hhismans          #+#    #+#              #
#    Updated: 2015/01/11 10:50:13 by hhismans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = sh1

SRC =	src/ft_cd.c \
		src/ft_env.c \
		src/ft_setenv.c \
		src/ft_unsetenv.c\
		src/sh1.c\
		src/buitlin.c

DEL = rm -f

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -o $@ $(OBJ) libft.a
	@echo
	@echo "make -> $@ created"
	@echo

%.o: %.c
	@gcc -o $@ -c $< -I./includes
	@echo [36mCompilation of[1m $< [0m[32m done [37m
clean:
	@$(DEL) $(OBJ)
	@echo
	@echo "clean -> .o deleted"
	@echo

fclean: clean
	@$(DEL) $(NAME)
	@echo
	@echo "fclean -> ... and $(NAME) deleted"
	@echo

re: fclean all
	@echo
	@echo "re -> $(NAME) reloaded"
	@echo

.PHONY: all clean fclean re

