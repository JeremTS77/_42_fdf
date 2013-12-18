/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 22:22:57 by aaubin            #+#    #+#             */
/*   Updated: 2013/11/20 22:33:16 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	len1;
	unsigned int	len2;

	if ( s1 == NULL && s2 == NULL )
		return (0);
	if ( s1 == NULL )
		return (-1);
	if ( s2 == NULL )
		return (1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ( n > len1 )
		n = len1 + 1;
	if ( n > len2 )
		n = len2 + 1;

	return (ft_memcmp(s1, s2, n));
}
