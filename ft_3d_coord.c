/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_3d_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 22:21:01 by aaubin            #+#    #+#             */
/*   Updated: 2013/12/18 22:21:06 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_3d_p	ft_create_3d_point(float x, float y, float z)
{
	t_3d_p	p;

	p.x = x;
	p.y = y;
	p.z = z;
	p.zz = 1;
	return (p);
}

t_3d_p	ft_create_3d_point_from_2d(t_2d_p pdx, float z)
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
	printf("Waouh ! On a un tableau de (h)%d x (W)%d!\n", array->h, array->w);
	ret = ft_memalloc(sizeof(t_3d_p *) * (array->h * array->w + 1));
	while (y < (array->h - 1))
	{
		x = 0;
		while (x < (array->w - 1))
		{
			pos = ((y + 1) * array->w) - (array->w - x);
			printf("[c=%d]> creating point[%d, %d, %d]\n", pos, x, y, array->data[y][x]);
			ret[pos] = ft_create_3d_point (
					x * INTERVAL, y * INTERVAL, array->data[y][x]);
			ret[pos] = ft_apply_matrix (ft_get_translation_matrix (200, 150, 1), ret[pos]);
			x++;
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

void		ft_print(t_3d_p p, unsigned int color, t_context *ct)
{
		/*if (p.x > 0 && p.x < ct->width && p.y > 0 && p.y < ct->height)
		{*/
			mlx_pixel_put(ct->mlx, ct->win,
						  (int)p.x, (int)p.y, color);
		/*}*/
}

t_3d_p ft_apply_matrix(t_mat4 m, t_3d_p p)
{
	t_3d_p	pn;

	pn.zz = 1;
	pn.x = (m.v[0][0] * p.x) + (m.v[0][1] * p.y)
			+ (m.v[0][2] * p.z) + (m.v[0][3] * p.zz);
	pn.y = (m.v[1][0] * p.x) + (m.v[1][1] * p.y)
			+ (m.v[1][2] * p.z) + (m.v[1][3] * p.zz);
	pn.z = (m.v[2][0] * p.x) + (m.v[2][1] * p.y)
			+ (m.v[2][2] * p.z) + (m.v[2][3] * p.zz);
	pn.zz = (m.v[3][0] * p.x) + (m.v[3][1] * p.y)
			+ (m.v[3][2] * p.z) + (m.v[0][3] * p.zz);
	return (pn);
}



