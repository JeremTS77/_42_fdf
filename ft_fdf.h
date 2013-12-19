/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 22:21:01 by aaubin            #+#    #+#             */
/*   Updated: 2013/12/18 22:21:06 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h> /* !!! */
# include "get_next_line.h"

typedef struct		s_context
{
	void	*mlx;
	void	*win;
}					t_context;

void	ft_fdf_init(t_context *ct);
int		ft_fdf_key_hook(int keycode, t_context *ct);
int		ft_fdf_exit(t_context *ct);
int		ft_fdf_expose_hook(t_context *ct);

#endif /* !FT_FDF_H */
