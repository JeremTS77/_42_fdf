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
	t_mat4	m = {{{1, 0, 0, 0},{0, 1, 0, 0},{0, 0, 1, 0},{0, 0, 0, 1}}};
	return (m);
}

t_mat4	ft_get_translation_matrix(double x, double y, double z)
{
	t_mat4	m;

	m = ft_create_4d_matrix ();
	m.v[0][3] = x;
	m.v[1][3] = y;
	m.v[2][3] = z;
	return (m);
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
			printf("%2.0f ", mat.v[c][cc]);
			cc++;
		}
		printf("\n");
		c++;
	}
}
