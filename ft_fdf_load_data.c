/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_fdf_load_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 22:21:01 by aaubin            #+#    #+#             */
/*   Updated: 2013/12/18 22:21:06 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_print_data(t_context *ct)
{
	int		i;

	i = 0;
	printf("======== initial ========\n");
	while (i < (ct->mesh->w * ct->mesh->h))
	{
		printf("[%3.1f:%3.1f:%3.1f] ", ct->scene[i].x, ct->scene[i].y, ct->scene[i].z);
		if ((i+1) % ct->mesh->w == 0)
			printf("\n");
		ft_print (ct->scene[i], LINE_COLOR, ct);
		i++;
	}
}
