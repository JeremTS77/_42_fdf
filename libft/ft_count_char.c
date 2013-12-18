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

int		ft_count_char(char const *s, char c)
{
	int	len;
	int	counter;
	int	count;

	if ( s == NULL )
		return (0);
	count = 0;
	counter = 0;
	len = ft_strlen(s);

	while (counter < len)
	{
		if (s[counter] == c && s[counter + 1] != c)
		{
			count++;
		}
		counter++;
	}
	return (count);
}
