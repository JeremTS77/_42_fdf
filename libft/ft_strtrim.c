/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:19:30 by aaubin            #+#    #+#             */
/*   Updated: 2013/11/21 06:32:39 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Prototype
	char * ft_strtrim(char const *s);
Description
	Alloue (avec malloc(3)) et retourne une copie de la chaine
	passée en paramètre sans les espaces blancs au debut et à la
	ﬁn de cette chaine. On considère comme espaces blancs les
	caractères ’ ’, ’\n’ et ’\t’. Si s ne contient pas d’espaces
	blancs au début ou à la ﬁn, la fonction renvoie une copie de
	s. Si l’allocation echoue, la fonction renvoie NULL.
Param.
	#1 La chaine de caractères à trimmer.
Retour
	La chaine de caractère “fraiche” trimmée ou bien une copie
	de s sinon.
Fonctions
	libc malloc(3)
*/
char *	ft_strtrim(char const *s)
{
	int				d;
	int				trim_start;
	unsigned int	c;
	char			*new_str;

	d = 0;
	c = 0;
	trim_start = 0;
	new_str = ft_strnew (ft_strlen (s));
	while ( c < ft_strlen (s))
	{
		if ( !trim_start && ft_isblank (s[c]))
			c++;
		else
		{
			trim_start = 1;
			new_str[d++] = s[c++];
		}
	}
	while (ft_isblank (new_str[--d]))
		new_str[d] = '\0';
	return (new_str);
}
