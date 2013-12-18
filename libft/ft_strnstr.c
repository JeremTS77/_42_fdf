/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 23:28:23 by aaubin            #+#    #+#             */
/*   Updated: 2013/11/21 06:56:34 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	c;
	char	sc;
	size_t	len;
	int		go;

	go = 0;
#if defined(VERBOSE)
	ft_putstr("ft_strnstr");
#endif
	if ((c = *s2++) != '\0')
	{
		len = ft_strlen(s2);
		while (!go || ft_strncmp(s1, s2, len) != 0)
		{
			go = 1;
			if ((sc = *s1++) == '\0' || n-- < 1)
				return (NULL);
			while (sc != c)
			{
				if ((sc = *s1++) == '\0' || n-- < 1)
					return (NULL);
			}
			if (len > n)
				return (NULL);
		}
		s1--;
	}
	return ((char *)s1);
}
