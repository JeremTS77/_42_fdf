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
	t_3d_p	pt;
	t_mat4	id;

	id = ft_create_4d_matrix ();
	pt = ft_create_3d_point (0, 0, 0);
	i = 0;
	while (i < (ct->mesh->w * ct->mesh->h))
	{
		ft_print (pt, 0xff6666, ct);
		pt = ft_apply_matrix (id, ct->scene[i]);
		ft_print (pt, LINE_COLOR, ct);
		i++;
	}
}
