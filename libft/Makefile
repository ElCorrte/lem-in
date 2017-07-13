#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 11:02:22 by yzakharc          #+#    #+#              #
#    Updated: 2017/06/27 15:44:47 by yzakharc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ :=	$(patsubst %.c,%.o,$(wildcard *.c))					\
		$(patsubst %.c,%.o,$(wildcard get_next_line/*.c))	\
		$(patsubst %.c,%.o,$(wildcard ft_printf/*.c))		\

all : $(NAME)

$(NAME) : $(OBJ)
	ar -cru $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %c.
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -rf *.o
	rm -rf get_next_line/*.o
	rm -rf ft_printf/*.o

fclean: clean
	rm -rf $(NAME)

re : fclean  all