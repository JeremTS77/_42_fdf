# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/26 22:57:40 by aaubin            #+#    #+#              #
#    Updated: 2013/12/18 17:05:41 by aaubin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang
LKFLAGS=-Wall -Wextra -pedantic #-Werror
CFLAGS=-Wall -Wextra -pedantic #-Werror
LDFLAGS=-g
NAME=libftprintf.a
SRC=ft_printf.c\
	ft_printf_paddings.c\
	ft_printf_char_paddings.c\
	ft_printf_int_paddings.c\
	ft_printf_oct_paddings.c\
	ft_printf_hex_paddings.c\
	ft_printf_ptr_paddings.c\
	ft_printf_strings.c\
	ft_printf_int.c\
	ft_printf_int_modifiers.c\
	ft_printf_mem_utils.c\
	ft_printf_convert_utils.c\
	ft_printf_print_utils.c\
	ft_printf_print_utils_num.c\
	ft_printf_print_utils_base.c\
	ft_printf_dollar.c\
	ft_printf_aparam.c\
	ft_printf_aparam_parser.c\
	ft_printf_aparam_modifiers.c\
	ft_printf_str_utils_2.c\
	ft_printf_str_utils.c
#	ft_printf_float.c\
#	ft_printf_hexa.c\
#	ft_printf_numbers.c\
#	ft_printf_test.c\

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
