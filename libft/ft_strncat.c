/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 08:35:49 by aaubin            #+#    #+#             */
/*   Updated: 2013/12/01 17:40:37 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t s1_len;
	size_t i;

#if defined(VERBOSE)
	ft_putstr("ft_strncat");
#endif
	s1_len = ft_strlen(s1);
	i = 0;
	while (i < n && s2[i] != '\0')
	{
		s1[s1_len + i] = s2[i];
		i++;
	}
	s1[s1_len + i] = '\0';
	return (s1);
}
