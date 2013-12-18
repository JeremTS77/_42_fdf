/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 06:11:23 by aaubin            #+#    #+#             */
/*   Updated: 2013/11/21 06:28:48 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	counter;
	char			*found;
	char			*driver;

#if defined(VERBOSE)
	ft_putstr("ft_memchr");
#endif
	counter = 0;
	driver = (char *)s;
	found = NULL;
	while (found == NULL && counter < n)
	{
		if (driver[counter] == c)
		{
			found = &(driver[counter]);
		}
		counter++;
	}
	return (found);
}
