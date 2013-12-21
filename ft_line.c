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

t_line	ft_get_line_ctx(t_2d_p p0, t_2d_p p1)
{
	t_line	ctx;

	ctx.done = 0;
	ctx.dx = ft_abs(p1.x - p0.x);
	ctx.sx = p0.x < p1.x ? 1 : -1;
	ctx.dy = ft_abs(p1.y - p0.y);
	ctx.sy = p0.y < p1.y ? 1 : -1;
	ctx.err = (ctx.dx > ctx.dy ? ctx.dx : -ctx.dy);
	ctx.err /= 2;
	return (ctx);
}

void		ft_draw_line(t_2d_p p0, t_2d_p p1, t_context *ct, int color)
{
	t_line	ctx;

	ctx = ft_get_line_ctx (p0, p1);
	while (!ctx.done)
	{
		ft_2d_print (p0, color, ct);
		if (p0.x == p1.x && p0.y == p1.y)
			ctx.done = 1;
		ctx.e2 = ctx.err;
		if (ctx.e2 > -ctx.dx)
		{
			ctx.err -= ctx.dy;
			p0.x += ctx.sx;
		}
		if (ctx.e2 < ctx.dy)
		{
			ctx.err += ctx.dx;
			p0.y += ctx.sy;
		}
	}
}
