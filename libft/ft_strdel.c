/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
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
	Prend en paramètre l’adresse d’une chaine de caractères qui
	doit être libérée avec free(3) et son pointeur mis à NULL.
Param.
	#1 L’adresse de la chaine de caractère dont il faut libérer la mé-
	moire et mettre le pointeur à NULL.
Retour
	Rien.
Fonctions
	libc Free(3)
*/
void	ft_strdel(char **as)
{
	ft_memdel ((void **) as);
}
