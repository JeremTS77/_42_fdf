/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 22:21:01 by aaubin            #+#    #+#             */
/*   Updated: 2013/12/18 22:21:06 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	main(int ac, char **av)
{
	char		**ret;
	t_context	ct;
	int			f;

	if ( ac > 1 )
	{
		ret = ft_memalloc ( 2 );
		ft_fdf_init(&ct);

		f = open(av[1], O_RDONLY, 0644);
		while (get_next_line (f, ret) > 0)
		{
			ft_putendl(*ret);
		}
		free ( ret );
		close(f);
	}
	return (0);
}
