#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 18:11:30 by ohesheli          #+#    #+#              #
#    Updated: 2017/04/12 18:26:33 by ohesheli         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = ants.c check.c helper1.c helper2.c lem_in.c parse.c pathfinder.c read.c

OBJ = $(SRC:.c=.o)

HEADER = lem_in.h

all: lib $(OBJ) exec
	
lib:
	cd libft && $(MAKE)

exec:
	gcc -o lem_in $(OBJ) -Llibft -lft

%.0: %.c $(HEADER)
	gcc -Wall -Wextra -Werror -c $<

clean:
	cd libft && $(MAKE) clean
	rm -f $(OBJ)

fclean: clean
	cd libft && $(MAKE) fclean
	rm -f lem_in

re: relib fclean all

relib:
	cd libft && $(MAKE) re
