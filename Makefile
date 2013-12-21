# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/26 22:57:40 by aaubin            #+#    #+#              #
#    Updated: 2013/12/20 16:34:05 by aaubin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang
LKFLAGS=-Wall -Wextra -pedantic -I./libft/includes -Wuninitialized \
	-L/usr/X11/lib -lmlx -lXext -lX11 -L./libft -lft
CFLAGS=-Wall -Wextra -pedantic -I./libft/includes
LDFLAGS=-g
NAME=fdf
SRC=ft_fdf.c\
	main.c\
	ft_fdf_load_data.c\
	ft_str_utils.c\
	ft_fdf_parser.c\
	ft_2d_coord.c\
	ft_3d_coord.c\
	ft_math_utils.c\
	ft_line.c\
	get_next_line.c
	#ft_2d_utils.c\
	#ft_3d_utils.c\

NOM=$(basename $(SRC))
OBJ=$(addsuffix .o, $(NOM))

all: makelib normal

normal: $(NAME)

makelib:
	@make -f Makefile -C libft

cleanlib:
	@make -f Makefile -C libft clean

fcleanlib:
	@make -f Makefile -C libft fclean

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(INC_PATH) $^ $(LKFLAGS)

%.o: %.c
	$(CC) $(LFLAGS) -g -o $@ -c $< $(CFLAGS)

clean: cleanlib
	@rm -rf $(OBJ)

fclean: clean fcleanlib mrproper

re: fclean fcleanlib all

.PHONY: clean mrproper

mrproper: clean
	@rm -rf $(NAME)
