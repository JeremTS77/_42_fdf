/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 21:44:57 by aaubin            #+#    #+#             */
/*   Updated: 2013/11/20 22:21:17 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		diff;
	int		counter;

	if ( s1 == NULL && s2 == NULL )
		return (0);
	if ( s1 == NULL )
		return (-1);
	if ( s2 == NULL )
		return (1);
	diff = 0;
	counter = 0;
	while (s1[counter] == s2[counter] && s1[counter] != '\0')
		counter++;
	return ((s1[counter] - s2[counter]));
}
