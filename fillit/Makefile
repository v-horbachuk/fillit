#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/05 13:11:34 by vhorbach          #+#    #+#              #
#    Updated: 2017/02/10 16:59:51 by vhorbach         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRCS = ./main.c ./ft_strdup.c ./struct.c ./solve.c ./grid.c ./validate.c ./ft_strlen.c

OBJ = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror

INCL = ./

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o fillit

%.o: %.c
	gcc $(FLAG) -I $(INCL) -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all