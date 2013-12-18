/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 03:22:01 by aaubin            #+#    #+#             */
/*   Updated: 2013/11/21 04:54:38 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*dp;
	const char	*sp;

#if defined(VERBOSE)
	ft_putstr("ft_memcpy");
#endif
	sp = s2;
	dp = s1;
	while (n--)
		*dp++ = *sp++;
	return (s1);
}
