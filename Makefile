# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/26 22:57:40 by aaubin            #+#    #+#              #
#    Updated: 2013/12/18 22:25:31 by aaubin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang
LKFLAGS=-Wall -Wextra -pedantic #-Werror
CFLAGS=-Wall -Wextra -pedantic #-Werror
LDFLAGS=-g
NAME=fdf
SRC=fd_fdf.c\
	main.c\
	ft_gnl.c
	#ft_2d_coord.c\
	#ft_2d_utils.c\
	#ft_3d_utils.c\
	#ft_line.c\
	#fd_3d_coord.c\
	#ft_matrix.c

NOM=$(basename $(SRC))
OBJ=$(addsuffix .o, $(NOM))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	$(CC) $(LFLAGS) -g -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf $(OBJ)

fclean: clean mrproper

re: fclean all

.PHONY: clean mrproper

mrproper: clean
	@rm -rf $(NAME)
