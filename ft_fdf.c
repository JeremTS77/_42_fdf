/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_fdf.c                                           :+:      :+:    :+:   */
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
	ct->width = 600;
	ct->height = 300;
	ct->win = NULL;
	ct->mlx = mlx_init ();
	ct->mesh = ft_parse_array (ct->filename);
	ct->scene = ft_convert_int_array (ct->mesh);
	if (ct->mlx != NULL)
	{
		ct->win = mlx_new_window (ct->mlx, ct->width, ct->height, "fdf");
		mlx_key_hook (ct->win, ft_fdf_key_hook, ct);
		mlx_expose_hook (ct->win, ft_fdf_expose_hook, ct);
		mlx_loop (ct->mlx);
	}
}

void		ft_translate(int x, int y, t_context *ct)
{
	t_mat4	mat;
	int		i;

	mat = ft_get_translation_matrix (x, y, 0);
	/*mlx_clear_window (ct->mlx, ct->win);*/
	i = 0;

	printf("====== matrice de translation =======\n");
	ft_print_matrix (mat);
	while (i < (ct->mesh->w * ct->mesh->h))
	{
		ct->scene[i] = ft_apply_matrix (mat, ct->scene[i]);
		printf("[%3.1f:%3.1f:%3.1f] ", ct->scene[i].x, ct->scene[i].y, ct->scene[i].z);
		if ((i+1) % ct->mesh->w == 0)
			printf("\n");
		/*ft_print (ct->scene[i], 0xff00ff, ct);*/
		i++;
	}
	printf("\nEND\n");
	/*
	while (ct->scene[i] != NULL && i < (ct->mesh->w * ct->mesh->h))
	{
		printf("[U] printed : [%f, %f]\n", ct->scene[i].x, ct->scene[i].y);
		ct->scene[i] = ft_apply_matrix (mat, ct->scene[i]);
		ft_print (ct->scene[i], 0xff00ff, ct);
		i++;
	}
	*/
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
		printf("pressed : %d\n", keycode);
		if (keycode == 65307)
		{
			ft_exit (ct);
		}
		else if (keycode == 65362)
			ft_translate (0, 15, ct);
		else if (keycode == 65363)
			ft_translate (15, 0, ct);
		else if (keycode == 65364)
			ft_translate (0, -15, ct);
		else if (keycode == 65361)
			ft_translate (-15, 0, ct);
	}
	return (0);
}


int		ft_fdf_expose_hook(t_context *ct)
{
	ft_print_data (ct);
	return (0);
}
