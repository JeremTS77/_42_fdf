/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 05:26:34 by aaubin            #+#    #+#             */
/*   Updated: 2013/12/01 17:47:17 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

#if defined(VERBOSE)
	ft_putstr("ft_strdup");
#endif
	len = ft_strlen(s1);
	s2 = (char *) malloc(sizeof(char *) * len);
	if ( s2 == NULL )
		return (s2);
	len = 0;
	while ('\0' != s1[len])
	{
		s2[len] = s1[len];
		len++;
	}
	s2[len] = '\0';
	return (s2);
}
