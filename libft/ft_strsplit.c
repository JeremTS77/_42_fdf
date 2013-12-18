/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
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
	char ** ft_strsplit(char const *s, char c);
Description
	Alloue (avec malloc(3)) et retourne un tableau de chaines de
	caractères “fraiches” (toutes terminées par un ’\0’, le tableau
	également donc) résultant de la découpe de s selon le caractère
	c. Si l’allocation echoue, la fonction retourne NULL. Exemple :
	ft_strsplit("*salut*les***etudiants*", ’*’) renvoie
	le tableau ["salut", "les", "etudiants"].
Param.
	#1 La chaine de caractères à découper.
	#2 Le caractère selon lequel découper la chaine.
Retour
	Le tableau de chaines de caractères “fraiches” résultant de la
	découpe.
Fonctions
	libc malloc(3)
*/

static char **	ft_get_array(char const *s, char c)
{
	int		n;
	char	**final;

	n = ft_count_char (s, c) + 2;
	final = (char **) ft_memalloc (n * sizeof(char**));
	*final = ft_strdup("");
	return (final);
}

char **			ft_strsplit(char const *s, char c)
{
	int		n;
	int		sub_counter;
	int		counter;
	char	**final;
	char	*clone;

	counter = 0;
	sub_counter = 0;
	clone = ft_strchartrim( ft_group_char (s, c), c);
	final = ft_get_array(s, c);
	if ( final != NULL && s != NULL )
	{
		n = 0;
		while (clone[counter] != '\0')
		{
			if (clone[counter] == c)
			{
				final[n++] = ft_strsub (clone, sub_counter, counter - sub_counter);
				n++;
				sub_counter = counter + 1;
			}
			counter++;
		}
		final[n] = ft_strsub (clone, sub_counter, counter - sub_counter);
	}
	return (final);
}
