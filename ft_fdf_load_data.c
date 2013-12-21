/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_load_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 22:21:01 by aaubin            #+#    #+#             */
/*   Updated: 2013/12/18 22:21:06 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_print_grid(t_context *ct)
{
	int		i;
	int		xi;
	int		yi;
	t_2d_p	pt;
	t_2d_p	pt2;

	i = 0;
	xi = 0;
	yi = 0;
	while (i < ct->mesh->w * ct->mesh->h - 1)
	{
		xi = i % ct->mesh->w;
		yi = i / ct->mesh->w;
		pt = ft_2d_from_3d (ct->scene[i]);
		pt2 = ft_2d_from_3d (ct->scene[i + 1]);
		if (i == 0 || (i + 1) % (ct->mesh->w) != 0)
			ft_draw_line (pt, pt2, ct, LINE_COLOR);
		if (yi < ct->mesh->h - 1)
		{
			pt2 = ft_2d_from_3d (ct->scene[i + ct->mesh->w]);
			ft_draw_line (pt, pt2, ct, LINE_COLOR);
		}
		i++;
	}
}

void		ft_print_data(t_context *ct)
{
	int		i;
	t_2d_p	pt;

	i = 0;
	while (i < (ct->mesh->w * ct->mesh->h))
	{
		pt = ft_2d_from_3d (ct->scene[i]);
		ft_2d_print (pt, LINE_COLOR, ct);
		i++;
	}
	ft_print_grid (ct);
}
