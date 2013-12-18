/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:19:30 by aaubin            #+#    #+#             */
/*   Updated: 2013/12/01 17:50:58 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list * 	ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*ctnt;

	ctnt = (void *) ft_memalloc(content_size + 1);
	if ( content == NULL )
	{
		ctnt = NULL;
		content_size = 0;
	}
	else
		ctnt = ft_memcpy (ctnt, content, content_size);
	list = ft_memalloc (sizeof(t_list));
	if ( list != (t_list *) NULL)
	{
		list->content_size = content_size;
		list->next = NULL;
		list->content = ctnt;
	}
	return (list);
}
