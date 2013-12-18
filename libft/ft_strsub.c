/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:19:30 by aaubin            #+#    #+#             */
/*   Updated: 2013/12/01 17:41:42 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Prototype
	char * ft_strsub(char const *s, unsigned int start, size_t len);
Description
	Alloue (avec malloc(3)) et retourne la copie “fraiche” d’un
	tronçon de la chaine de caractères passée en paramètre. Le
	tronçon commence à l’index start et à pour longueur len. Si
	start et len ne désignent pas un tronçon de chaine valide,
	le comportement est indéterminé. Si l’allocation échoue, la
	fonction renvoie NULL.
Param.
	#1 La chaine de caractères dans laquelle chercher le tronçon à copier.
	#2 L’index dans la chaine de caractères où débute le tronçon à copier.
	#3 La longueur du tronçon à copier.
Retour
	Le tronçon.
Fonctions
	libc malloc(3)
*/
char *	ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	counter;
	char			*dest;
	if ( s == NULL )
		return (NULL);
	dest = ft_strnew (len+1);
	counter = 0;
	if (dest == NULL)
		return (NULL);
	while (counter < len + start)
	{
		if (counter >= start)
		{
			dest[counter - start] = s[counter];
		}
		counter++;
	}
	return (dest);
}
