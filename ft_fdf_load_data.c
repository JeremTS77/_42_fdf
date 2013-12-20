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
	t_2d_p	pt;

	pt = ft_create_3d_point (0, 0, 0);
	i = 0;
	while (i < (ct->mesh->w * ct->mesh->h))
	{
		pt = ft_2d_from_3d (ct->scene[i]);
		ft_2d_print (pt, LINE_COLOR, ct);
		i++;
	}
}
