/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
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
	Assigne la valeur ’\0’ à tous les caractères de la chaine passée
	en paramètre.
Param.
	#1 La chaine de caractères à clearer.
Retour
	Rien.
Fonctions
	libc Aucune.
*/
void	ft_strclr(char *s)
{
	int	length;
	int	counter;

#if defined(VERBOSE)
	ft_putstr("ft_strclr");
#endif
	counter = 0;
	length = ft_strlen (s);
	while (counter < length)
	{
		*s = '\0';
		s++;
		counter++;
	}
}
