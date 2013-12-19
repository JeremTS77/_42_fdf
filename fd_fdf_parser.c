/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_fdf_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 22:21:01 by aaubin            #+#    #+#             */
/*   Updated: 2013/12/18 22:21:06 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_fdf_init(t_context *ct)
{
	ct->win = NULL;
	ct->mlx = mlx_init ();
	if (ct->mlx != NULL)
	{
		ct->win = mlx_new_window (ct->mlx, 600, 300, "fdf");
		mlx_key_hook (ct->win, ft_fdf_key_hook, ct);
		mlx_expose_hook (ct->win, ft_fdf_expose_hook, ct);
		mlx_loop (ct->mlx);
	}
}

int		ft_fdf_key_hook(int keycode, t_context *ct)
{
	if (ct)
	{
		printf("pressed : %d\n", keycode);
		if (keycode == 65307)
			exit(0);
	}
	return (0);
}


int		ft_fdf_expose_hook(t_context *ct)
{
	if (ct)
	{
		return (0);
	}
	return (0);
}
