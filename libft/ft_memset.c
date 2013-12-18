/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:46:55 by aaubin            #+#    #+#             */
/*   Updated: 2013/11/20 01:16:00 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void*	ft_memset(void *b, int c, size_t len)
{
	char	*s;

#if defined(VERBOSE)
	ft_putstr("ft_memset");
#endif
	if ( len )
	{
		s = b;
		while ( len )
		{
			*s ++ = c;
			len --;
		}
	}
	return ( b );
}
