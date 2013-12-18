/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
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
	int ft_strequ(char const *s1, char const *s2);
Description
	Compare lexicographiquement s1 et s2. Si les deux chaines
	sont égales, la fonction retourne 1, ou 0 sinon.
Param.
	#1 La première des deux chaines à comparer.
	#2 La seconde des deux chaines à comparer.
Retour
	1 ou 0 selon que les deux chaines sont égales ou non.
Fonctions
	libc Aucune.
*/
int		ft_strequ(char const *s1, char const *s2)
{
	int	eq;

	eq = (ft_strcmp(s1, s2) == 0 ? 1 : 0);
	return (eq);
}
