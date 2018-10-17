# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoodley <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 13:05:34 by amoodley          #+#    #+#              #
#    Updated: 2017/11/23 17:23:28 by amoodley         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem-in 
CFLAGS	= -Wall -Werror -Wextra
SRC		= main.c lem_in.c pathfinding.c loops.c moves.c free.c
INC		= -L libft -lft

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(CFLAGS) $(SRC) $(INC) -o $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean:
	make -C libft clean
	rm -f $(NAME)

re: fclean all
