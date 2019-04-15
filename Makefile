# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojessi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 18:31:03 by ojessi            #+#    #+#              #
#    Updated: 2019/04/15 13:58:40 by ojessi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl
SRC = get_next_line.c main.c \
	  libft/*.c
HEAD = get_next_line.h
FLAGS = -Wextra -Wall -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -I $(HEAD) $(SRC) -o $(NAME)
	./$(NAME)

clean:
	/bin/rm -f $(NAME)

re: clean all
