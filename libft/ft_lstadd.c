/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:19:30 by aaubin            #+#    #+#             */
/*   Updated: 2013/11/22 01:28:57 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void		ft_lstadd(t_list **alst, t_list *new)
{
	if (new)
	{
		if (!(*alst))
		{
			*alst = new;
		}
		new->next = *alst;
		*alst = new;
	}
}
