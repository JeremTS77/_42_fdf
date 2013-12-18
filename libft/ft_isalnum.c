/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 01:12:17 by aaubin            #+#    #+#             */
/*   Updated: 2013/11/21 01:35:25 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{

#if defined(VERBOSE)
	ft_putstr("ft_isalnum");
#endif
	if (ft_isalpha(c) || ft_isdigit(c))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
