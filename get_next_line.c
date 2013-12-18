/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 19:57:05 by aaubin            #+#    #+#             */
/*   Updated: 2013/12/04 01:40:50 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_add_line(char **line, char **bubu, long len)
{
	char		*tmp;
	long		o_len;

	if ( line == NULL )
		line = (char **)ft_memalloc (sizeof(char **));

	o_len = ft_strlen (*line);
	*line = (char *)ft_realloc(*line, o_len,  o_len + len + 1);

	if ( *line )
	{
		(*line)[o_len + len] = '\0';
		ft_strncat (*line, *bubu, len);
		tmp = ft_strnew ( sizeof(char*) * BUFF_SIZE );

		if ( tmp )
		{
			ft_strncat(tmp, (*bubu) + len + 1, BUFF_SIZE - len - 1);
			free(*bubu);
			*bubu = tmp;
		}
	}
}

void	ft_loop(int const *fd, char **line, char **bubu, long *res)
{
	int		stop;

	stop = 0;

	if ( *bubu == NULL )
	{
		*bubu = ft_strnew ( sizeof(char*) * BUFF_SIZE );
		*res = read( *fd, *bubu, BUFF_SIZE );
	}

	*line = ft_strnew ( sizeof(char*) * BUFF_SIZE );

	while ( *line != NULL && *res == BUFF_SIZE && !stop )
	{
		if ( ft_strchr (*bubu, '\n') != 0 )
		{
			ft_add_line (line, bubu, ft_strpos(*bubu, "\n"));
			stop = 1;
		}
		else
		{
			ft_add_line (line, bubu, BUFF_SIZE);
			*res = read( *fd, *bubu, BUFF_SIZE );
		}
	}
}

int		get_next_line(int const fd, char ** line)
{
	long		res;
	static char	*courant;
	int		stop;

	if (fd < 0 || line == NULL)
		return (-1);

	stop = 0;
	res = BUFF_SIZE;

	ft_loop (&fd, line, &courant, &res);

	if ( res != BUFF_SIZE && res > 0 )
		ft_add_line (line, &courant, res - 1);

	if ( res <= 0 )
	{
		free(*line);
		free(courant);
		courant = NULL;
		return (res);
	}

	return (1);
}
