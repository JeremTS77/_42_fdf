/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 01:31:50 by aaubin            #+#    #+#             */
/*   Updated: 2013/11/21 01:36:16 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int c)
{
#if defined(VERBOSE)
	ft_putstr("ft_tolower");
#endif
	if (ft_isupper(c))
	{
		return (c + 32);
	}
	else
	{
		return (c);
	}
}
