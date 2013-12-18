/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchartrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:19:30 by aaubin            #+#    #+#             */
/*   Updated: 2013/11/21 06:32:39 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *	ft_strchartrim(char const *s, char ch)
{
	int				d;
	int				trim_start;
	unsigned int	c;
	char			*new_str;

	d = 0;
	c = 0;
	trim_start = 0;
	new_str = ft_strnew (ft_strlen (s) + 1);
	while ( c < ft_strlen (s))
	{
		if ( !trim_start && s[c] == ch)
			c++;
		else
		{
			trim_start = 1;
			new_str[d++] = s[c++];
		}
	}
	while (new_str[--d] == ch)
		new_str[d] = '\0';
	return (new_str);
}
