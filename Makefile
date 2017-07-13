#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/26 20:58:13 by yzakharc          #+#    #+#              #
#    Updated: 2017/07/12 19:35:55 by yzakharc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	lem-in
CC		=	gcc
FLAG	=	-Wall -Wextra -Werror
LIBFT	=	./libft/libft.a
OBJ     =	$(patsubst %.c,%.o,$(wildcard *.c))	\

.PHONY: libft

all : $(NAME)

$(NAME) : $(OBJ) libft
	$(CC) $(FLAG) -o $(NAME) $(OBJ) $(LIBFT)

libft:
	make -C ./libft

%.o : %.c
	$(CC) $(FLAG) -o $@ -c $<

clean:
	rm -rf $(OBJ)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re: fclean all
