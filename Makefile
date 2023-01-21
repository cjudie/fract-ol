# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 14:24:37 by cjudie            #+#    #+#              #
#    Updated: 2022/06/17 15:35:32 by cjudie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc

CFLAGS = -Wall -Wextra -Werror -Imlx

bXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRC = $(patsubst %.c, %.o, $(wildcard *.c))

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: 		$(NAME)

$(NAME): $(SRC)
	$(CC) -I /usr/locl/include $(SRC) -L /usr/locl/lib/ $(bXFLAGS) -o $(NAME)

clean:
	-rm -f *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all bonus clean fclean re
