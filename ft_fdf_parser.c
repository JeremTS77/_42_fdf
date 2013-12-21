/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 22:21:01 by aaubin            #+#    #+#             */
/*   Updated: 2013/12/18 22:21:06 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		ft_count_rows(char *name)
{
	char		**ret;
	int		res;
	int		f;

	res = 0;
	ret = ft_memalloc (sizeof(char **) * 2);
	f = open(name, O_RDONLY, 0644);
	while (get_next_line (f, ret) > 0)
		res++;
	free (ret);
	close(f);
	return (res);
}

int		ft_count_columns(char **elts)
{
	int	c;

	c = 0;
	while (elts[c] != NULL)
		c++;
	return (c);
}

int		*ft_convert_char_int(char **elts, int count)
{
	int		*line;
	int		tmp;
	int		c;

	c = 0;
	tmp = 0;
	line = ft_memalloc(sizeof(int *) * (count + 1));
	while (c < count)
	{
		tmp = ft_atoi(elts[c]);
		line[c] = tmp;
		c++;
	}
	return (line);
}

t_mesh	*ft_add_readed_line(t_mesh *ret, char *buf, int index)
{
	char		**elts;
	int		c;

	c = 0;
	elts = ft_fdf_strsplit(buf, ' ');
	while (elts[c] != NULL)
		c++;
	ret->w = ft_count_columns (elts);
	ret->data[index] = ft_convert_char_int (elts, ret->w);
	return (ret);
}

t_mesh	*ft_parse_array(char *file)
{
	t_mesh		*mesh;
	char			*buf;
	int			c;
	int			f;

	c = 0;
	mesh = ft_memalloc(sizeof(t_mesh *));
	mesh->h = ft_count_rows (file);
	mesh->data = (int **)ft_memalloc(sizeof(int **) * (mesh->h + 1));
	f = open(file, O_RDONLY, 0644);
	while (get_next_line (f, &buf) > 0)
	{
		mesh = ft_add_readed_line (mesh, buf, c);
		c++;
		ft_putendl (buf);
	}
	return (mesh);
}
