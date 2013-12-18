# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 02:17:09 by aaubin            #+#    #+#              #
#    Updated: 2013/12/04 00:39:19 by aaubin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-I includes/ -Wall -Werror -Wextra
LDFLAGS=-g
NAME=libft.a
SRC=ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memccpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strlen.c\
	ft_strdup.c\
	ft_strcpy.c\
	ft_strncpy.c\
	ft_strcat.c\
	ft_strncat.c\
	ft_strlcat.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strstr.c\
	ft_strnstr.c\
	ft_strcmp.c\
	ft_strncmp.c\
	ft_atoi.c\
	ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_isupper.c\
	ft_islower.c\
	ft_memalloc.c\
	ft_memdel.c\
	ft_strnew.c\
	ft_strdel.c\
	ft_strclr.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strequ.c\
	ft_strnequ.c\
	ft_strsub.c\
	ft_strjoin.c\
	ft_isblank.c\
	ft_strtrim.c\
	ft_strsplit.c\
	ft_itoa.c\
	ft_putchar.c\
	ft_putstr.c\
	ft_putendl.c\
	ft_putnbr.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_lstnew.c\
	ft_lstdelone.c\
	ft_lstdel.c\
	ft_lstadd.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_count_char.c\
	ft_group_char.c\
	ft_memrealloc.c\
	ft_pow.c\
	ft_nbrlen.c\
	ft_strchartrim.c\
	ft_strpos.c\
	ft_realloc.c

NOM=$(basename $(SRC))
OBJ=$(addsuffix .o, $(NOM))

all: normal

normal: $(NAME)

verbose: clean all_debug

all_debug: CFLAGS += -DVERBOSE
all_debug: normal

$(NAME): $(OBJ)
	@ar rc $(NAME) $^
	@ranlib $(NAME)

%.o: %.c
	@$(CC) -g $(LFLAGS) -o $@ -c $< $(CFLAGS)

fclean: clean mrproper

re: fclean all

clean:
	@rm -rf $(OBJ)

mrproper: clean
	@rm -rf $(NAME)
