/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:19:30 by aaubin            #+#    #+#             */
/*   Updated: 2013/11/21 06:32:39 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Description
	Alloue (avec malloc(3)) et retourne une chaine de caractère
	“fraiche” terminée par un ’\0’. Chaque caractère de la chaine
	est initialisé à ’\0’. Si l’allocation echoue, la fonction renvoie
	NULL.

Param.
	#1 La taille de la chaine de caractères à allouer.

Retour
	La chaine de caractères allouée et initialisée à 0.

Fonctions
	libc malloc(3)
*/
char	*ft_strnew(size_t size)
{
	void	*str;

	str = ft_memalloc (size + 1);
	if (str == NULL)
		return (NULL);
	else
		return (char *)(str);
}
