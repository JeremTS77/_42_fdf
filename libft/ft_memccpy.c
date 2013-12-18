/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 03:52:22 by aaubin            #+#    #+#             */
/*   Updated: 2013/11/21 05:43:05 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char *dp;
	const char *sp;

	sp = s2;
	dp = s1;
#if defined(VERBOSE)
	ft_putstr("ft_memccpy");
#endif
	while (n--)
	{
		if ( *sp == c )
		{
			*dp++ = *sp++;
			return (dp);
		}
		*dp++ = *sp++;
	}
	return (NULL);
}
