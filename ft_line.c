/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 22:21:01 by aaubin            #+#    #+#             */
/*   Updated: 2013/12/18 22:21:06 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void ft_draw_line(t_2d_p p0, t_2d_p p1, t_context *ct, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
	int	done;

	done = 0;
	dx = ft_abs(p1.x - p0.x);
	sx = p0.x < p1.x ? 1 : -1;
	dy = ft_abs(p1.y - p0.y);
	sy = p0.y < p1.y ? 1 : -1;
	err = (dx > dy ? dx : -dy);
	err /= 2;
	while (!done)
	{
		ft_2d_print (p0, color, ct);
		if (p0.x == p1.x && p0.y == p1.y)
			done = 1;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			p0.x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			p0.y += sy;
		}
	}
}
