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
		printf("converting [%s] to [%i]...\n", elts[c], tmp);
		line[c] = tmp;
		c++;
	}
	return (line);
}

t_mesh	*ft_add_readed_line(t_mesh *ret, char *buf, int index)
{
	char	**elts;
	int		c;

	c = 0;
	elts = ft_fdf_strsplit(buf, ' ');
	printf("split : {");
	while (elts[c] != NULL)
	{
		printf("%s,", elts[c]);
		c++;
	}
	printf("}\n");
	ret->w = ft_count_columns (elts);
	printf("[MESH] [LARGEUR=%3d] [HAUTEUR=%3d]\n", ret->w, ret->h);
	ret->data[index] = ft_convert_char_int (elts, ret->w);
	return (ret);
}

t_mesh	*ft_parse_array(char *file)
{
	t_mesh		*mesh;
	char			*buf;
	int			c;
	int			f;
	int		x;
	int		y;

	x = 0;
	y = 0;
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
	printf("final data :\n\n");

	while (y < (mesh->h))
	{
		x = 0;
		while (x < (mesh->w))
		{
			printf("[%2d %2d](%2d) ", x, y, mesh->data[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n\n");

	return (mesh);
}
