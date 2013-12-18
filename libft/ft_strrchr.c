/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:53:39 by aaubin            #+#    #+#             */
/*   Updated: 2013/11/20 20:53:41 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	to_find;
	char	*found;
	int		count;

	to_find = c;
	found = NULL;
	count = 0;
#if defined(VERBOSE)
	ft_putstr("ft_strrchr");
#endif
	while (s[count] != '\0')
	{
		if (s[count] == to_find)
			found = (char *)(s + count);
		count++;
	}
	if (s[count] == to_find)
		found = (char *)(s + count);
	return (found);
}
