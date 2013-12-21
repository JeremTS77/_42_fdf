/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 22:21:01 by aaubin            #+#    #+#             */
/*   Updated: 2013/12/18 22:21:06 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_fdf_init(t_context *ct, char *file)
{
	ct->filename = file;
	ct->width = WIN_W;
	ct->height = WIN_H;
	ct->win = NULL;
	ct->mlx = mlx_init ();
	ct->mesh = ft_parse_array (ct->filename);
	ct->scene = ft_convert_int_array (ct->mesh);
	if (ct->mlx != NULL)
	{
		ct->win = mlx_new_window (ct->mlx, ct->width, ct->height, "fdf");
		mlx_expose_hook (ct->win, ft_fdf_expose_hook, ct);
		mlx_key_hook (ct->win, ft_fdf_key_hook, ct);
		mlx_loop (ct->mlx);
	}
}

void		ft_exit(t_context *ct)
{
	ft_clear_array(&(ct->scene), (ct->mesh->w * ct->mesh->h));
	free(ct->mesh->data);
	free(ct->mesh);
	exit(0);
}

int		ft_fdf_key_hook(int keycode, t_context *ct)
{
	if (ct)
	{
		if (keycode == 65307)
			ft_exit (ct);
	}
	return (0);
}


int		ft_fdf_expose_hook(t_context *ct)
{
	ft_print_data (ct);
	return (0);
}
