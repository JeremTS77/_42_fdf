# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/26 22:57:40 by aaubin            #+#    #+#              #
#    Updated: 2013/12/18 22:26:29 by aaubin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
LKFLAGS=-Wall -Wextra -pedantic -I./libft/includes -Werror \
	-L/usr/X11/lib -lmlx -lXext -lX11 -L./libft -lft
CFLAGS=-Wall -Wextra -pedantic -I./libft/includes -Werror
LDFLAGS=-g
NAME=fdf
SRC=fd_fdf.c\
	main.c\
	get_next_line.c
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
	$(CC) -o $(NAME) $(INC_PATH) $^ $(LKFLAGS)

%.o: %.c
	$(CC) $(LFLAGS) -g -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf $(OBJ)

fclean: clean mrproper

re: fclean all

.PHONY: clean mrproper

mrproper: clean
	@rm -rf $(NAME)
