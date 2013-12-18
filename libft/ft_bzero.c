/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 02:48:32 by aaubin            #+#    #+#             */
/*   Updated: 2013/11/20 03:05:11 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*t;

#if defined(VERBOSE)
	ft_putstr("ft_bzero\n");
#endif
	if ( n )
	{
		t = s;
		while ( n )
		{
			*t ++ = 0;
			n --;
		}
	}
}
