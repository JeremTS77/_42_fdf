/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 22:21:01 by aaubin            #+#    #+#             */
/*   Updated: 2013/12/18 22:21:06 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_mat4	ft_create_4d_matrix(void)
{
	t_mat4	m = {
		{
			{1.0, 0.0, 0.0, 0.0},
			{0.0, 1.0, 0.0, 0.0},
			{0.0, 0.0, 1.0, 0.0},
			{0.0, 0.0, 0.0, 1.0}
		}
	};
	t_mat4	a = {
		{
			{1, 3, 2, 6},
			{2, 1, 2, 0},
			{5, 0, 1, 3},
			{1, 2, 3, 2}
		}
	};
	t_mat4	b = {
		{
			{2, 3, 2, 0},
			{4, 1, 2, 3},
			{3, 0, 1, 3},
			{1, 3, 0, 2}
		}
	};
	t_mat4	c;

	c = ft_multiply_matrix (a, b);
	ft_print_matrix (a);
	ft_print_matrix (b);
	ft_print_matrix (c);
	return (m);
}

t_mat4	ft_get_translation_matrix(float x, float y, float z)
{
	t_mat4	m;

	m = ft_create_4d_matrix ();
	m.v[0][3] = x;
	m.v[1][3] = y;
	m.v[2][3] = z;
	return (m);
}

t_mat4	ft_multiply_matrix(t_mat4 ma, t_mat4 mb)
{
	t_mat4	mc;
	int i;
	int j;
	int z;

	/* aaah ! une boucle for !
	mc = ft_create_4d_matrix ();*/
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			mc.v[i][j] = 0;
			for (z = 0; z < 4; z++)
			{
				mc.v[i][j] += ma.v[i][z] * mb.v[z][j];
			}
		}
	}
	return (mc);
}

void		ft_copy_matrix(t_mat4 *dest, t_mat4 src)
{
	int	c;
	int	cc;

	c = 0;
	while (c < 4)
	{
		cc = 0;
		while (cc < 4)
		{
			dest->v[c][cc] = src.v[c][cc];
			cc++;
		}
		c++;
	}
}

void		ft_print_matrix(t_mat4 mat)
{
	int	c;
	int	cc;

	c = 0;
	while (c < 4)
	{
		cc = 0;
		while (cc < 4)
		{
			printf(" %5.2f ", mat.v[c][cc]);
			cc++;
		}
		printf("\n");
		c++;
	}
	printf("\n");
}
