# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/22 16:12:17 by pibenoit          #+#    #+#              #
#    Updated: 2015/12/23 22:46:32 by pibenoit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit

SRC= main.c ft_erreur.c ft_treatment.c ft_init.c ft_exit.c ft_place.c\
	ft_oned.c ft_search.c ft_bzero.c ft_save.c ft_search_other.c\
	ft_place2.c

OBJ= main.o ft_erreur.o ft_treatment.o ft_init.o ft_exit.o ft_place.o\
	ft_oned.o ft_search.o ft_bzero.o ft_save.o ft_search_other.o\
	ft_place2.o

CC= gcc

FLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)

%.o: %.c
	@$(CC) -o $@ -c $< $(FLAGS)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
