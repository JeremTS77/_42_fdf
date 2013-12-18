/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:19:30 by aaubin            #+#    #+#             */
/*   Updated: 2013/12/01 14:43:27 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define false        0
# define true        1

typedef		unsigned char		uc;
typedef		unsigned int		ui;
typedef		unsigned long		ul;


/* ------------------------------ List structure -----------------------------*/

typedef struct		s_list
{
	void *			content;
	size_t 			content_size;
	struct s_list *	next;
}					t_list;

/* -------------------------------- First part -------------------------------*/

void *		ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void *		ft_memcpy(void *s1, const void *s2, size_t n); /* (fix 096d2cd1f62c) */
void *		ft_memccpy(void *s1, const void *s2, int c, size_t n);
void *		ft_memmove(void *s1, const void *s2, size_t n);
void *		ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

size_t		ft_strlen(const char *s);
char *		ft_strdup(const char *s1);
char *		ft_strcpy(char *s1, const char *s2);
char *		ft_strncpy(char *s1, const char *s2, size_t n);
char *		ft_strcat(char *s1, const char *s2);
char *		ft_strncat(char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char *		ft_strchr(const char *s, int c);
char *		ft_strrchr(const char *s, int c);
char *		ft_strstr(const char *s1, const char *s2); /* Requires strncmp > ok */
char *		ft_strnstr(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

int			ft_atoi(const char *str);

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

/* -------------------------------- Second part ------------------------------*/

void *		ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char *		ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char *		ft_strmap(char const *s, char (*f)(char));
char *		ft_strmapi(char const *s, char(*f)(unsigned int, char));
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char *		ft_strsub(char const *s, unsigned int start, size_t len);
char *		ft_strjoin(char const *s1, char const *s2);
char *		ft_strtrim(char const *s);
char **		ft_strsplit(char const *s, char c);
char *		ft_itoa(int n);

void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		ft_putendl(char const *s);
void		ft_putnbr(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);

t_list * 	ft_lstnew(void const *content, size_t content_size);
void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void		ft_lstadd(t_list **alst, t_list *new);
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list *	ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem));


/* --------------------------- User specific functions -----------------------*/

int			ft_islower(int c); /* user */
int			ft_isupper(int c); /* user */
int			ft_isblank(int c); /* user */

/*
 * Regroupe tous les caracteres 'c' (en parametre) adjacents et renvoie
 * une chaine 'fraiche' netoyee de tout les doublons.
 * Ex : ft_group_char ("Je suis fatigue...",'.') => "Je suis fatigue."
 */
char *		ft_group_char(char const *s, char c);

/*
 * Compte le nombre d'occurences du caractere c dans la chaine.
 */
int			ft_count_char(char const *s, char c);

/*
 * Effectue un trim sur la chaine s avec le char ch specifie
 */
char *		ft_strchartrim(char const *s, char ch);

/*
 * Effectue une reallocation de la memoire de [buf] en taille [new_size]
 */
void *		ft_memrealloc(void *buf, size_t old_size, size_t new_size);

/*
 * Renvoie la puissance BASE de exp
 */
int	ft_pow(int base, int exp);

/*
 * Renvoie la longueur d'un nombre (ex : 1000 = 4)
 */
int	ft_nbrlen(int nombre);

int ft_strpos(const char *s1, const char *s2);

void	*ft_realloc(void *ptr, size_t old, size_t size);
#endif /* !LIBFT_H */
