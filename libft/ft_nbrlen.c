/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 17:24:18 by aaubin            #+#    #+#             */
/*   Updated: 2013/11/29 17:51:35 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

int	ft_nbrlen(int nombre)
{
	int	counter;

	counter = 0;
	if ( nombre == 0 )
		return (1);
	while ( nombre > 0 )
	{
		nombre = nombre / 10;
		counter++;
	}
	return (counter);
}
