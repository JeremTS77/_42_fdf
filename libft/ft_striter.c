/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
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
	Applique la fonction f à chaque caractère de la chaine de
	caractères passée en paramètre. Chaque caractère est passé
	par adresse à la fonction f aﬁn de pouvoir être modiﬁé si
	nécéssaire.
Param.
	#1 La chaine de caractères sur laquelle itérer.
	#2 La fonction à appeler sur chaque caractère de s.
Retour
	Rien.
Fonctions
	libc Aucune
*/
void	ft_striter(char *s, void (*f)(char *))
{
	int	len;
	int	counter;

	if ( s != NULL && f != NULL )
	{
		len = ft_strlen (s);
		counter = 0;
		while ( counter < len )
		{
			(*f)(s);
			s++;
			counter++;
		}
	}
}
