/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 01:24:05 by aaubin            #+#    #+#             */
/*   Updated: 2013/11/21 01:36:02 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_toupper(int c)
{
#if defined(VERBOSE)
	ft_putstr("ft_toupper");
#endif
	if (ft_islower(c))
	{
		return (c - 32);
	}
	else
	{
		return (c);
	}
}
