/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3d_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 22:21:01 by aaubin            #+#    #+#             */
/*   Updated: 2013/12/18 22:21:06 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_3d_p	ft_create_3d_point(int x, int y, int z)
{
	t_3d_p	p;

	p.x = x;
	p.y = y;
	p.z = z;
	p.zz = 1;
	return (p);
}

t_3d_p	ft_create_3d_point_from_2d(t_2d_p pdx, int z)
{
	t_3d_p	p;

	p.x = pdx.x;
	p.y = pdx.y;
	p.z = z;
	p.zz = 1;
	return (p);
}

t_3d_p	*ft_convert_int_array(t_mesh *array)
{
	int		x;
	int		y;
	t_3d_p	*ret;
	int		pos;

	x = 0;
	y = 0;
	pos = 0;
	ret = ft_memalloc(sizeof(t_3d_p *) * (array->h * array->w + 1));
	while (y < (array->h))
	{
		x = 0;
		while (x < (array->w))
		{
			ret[pos] = ft_create_3d_point (
					((WIN_W - (array->w * INTERVAL)) / 2) + x * INTERVAL,
					((WIN_H - (array->h * INTERVAL)) / 2) + y * INTERVAL,
					array->data[y][x]);
			x++;
			pos++;
		}
		y++;
	}
	return (ret);
}

void		ft_clear_array(t_3d_p **ret, int size)
{
	int	counter;

	counter = size;
	free(*ret);
	*ret = NULL;
}

void		ft_3d_print(t_3d_p p, unsigned int color, t_context *ct)
{
	if (p.x > 0 && p.x < ct->width && p.y > 0 && p.y < ct->height)
	{
		mlx_pixel_put(ct->mlx, ct->win, p.x, p.y, color);
	}
}
