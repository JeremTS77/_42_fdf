/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:19:30 by aaubin            #+#    #+#             */
/*   Updated: 2013/11/22 01:28:57 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if ( *alst )
		(*del)((*alst)->content, (*alst)->content_size);
	ft_memdel ((void **) alst);
}
