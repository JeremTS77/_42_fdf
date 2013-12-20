/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 22:21:01 by aaubin            #+#    #+#             */
/*   Updated: 2013/12/18 22:21:06 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_2d_p	*ft_create_2d_point(int x, int y)
{
	t_2d_p	*p;

	p = ft_memalloc(sizeof(t_2d_p *));
	if (p)
	{
		p->x = x;
		p->y = y;
	}
	return (p);
}

t_2d_p	ft_2d_from_3d(t_3d_p p)
{
	t_2d_p	pp;

	pp.x = 	p.x;
	pp.y = 	p.y;
	return (pp);
}

void		ft_2d_print(t_2d_p p, unsigned int color, t_context *ct)
{
		if (p.x > 0 && p.x < ct->width && p.y > 0 && p.y < ct->height)
		{
			mlx_pixel_put(ct->mlx, ct->win, p.x, p.y, color);
		}
}
