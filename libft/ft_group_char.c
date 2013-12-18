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

char	*	ft_group_char(char const *s, char c)
{
	char	*clone;
	int		counter;
	int		c_counter;

	if ( s == NULL )
		return (NULL);
	counter = 0;
	c_counter = 0;
	clone = ft_strnew (ft_strlen(s) + 1);
	while (s[counter] != '\0')
	{
		clone[c_counter] = s[counter];
		while(s[counter] == c && s[counter + 1] == c)
			counter++;
		counter++;
		c_counter++;
	}
	return (clone);
}
