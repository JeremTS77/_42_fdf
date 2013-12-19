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

# define		LINE_COLOR	0xffffff
# define		INTERVAL		10

typedef struct		s_mesh
{
	int				w;
	int				h;
	int				**data;
}					t_mesh;

typedef struct		s_2d_p
{
	int				x;
	int				y;
}					t_2d_p;

typedef struct		s_3d_p
{
	float			x;
	float			y;
	float			z;
	float			zz;
}					t_3d_p;

typedef struct		s_mat4
{
	float			v[4][4];
}					t_mat4;

typedef struct		s_context
{
	void				*mlx;
	void				*win;
	char				*filename;
	int				width;
	int				height;
	t_3d_p			*scene;
	t_mesh			*mesh;
	t_mat4			*mat;
}					t_context;

void		ft_fdf_init(t_context *ct, char *file);
int		ft_fdf_key_hook(int keycode, t_context *ct);
int		ft_fdf_exit(t_context *ct);
int		ft_fdf_expose_hook(t_context *ct);
void		ft_translate(int x, int y, t_context *ct);

int		ft_count_rows(char *name);
int		ft_count_columns(char **elts);
t_mesh	*ft_parse_array(char *file);
int		*ft_convert_char_int(char **elts, int count);
t_mesh	*ft_add_readed_line(t_mesh *ret, char *buf, int index);

void		ft_print_data(t_context *ct);

t_mat4	ft_create_4d_matrix(void);
t_mat4	ft_get_translation_matrix(float x, float y, float z);
void		ft_print_matrix(t_mat4 mat);

t_3d_p	ft_create_3d_point(float x, float y, float z);
t_3d_p	ft_create_3d_point_from_2d(t_2d_p pdx, float z);
void		ft_print(t_3d_p p, unsigned int color, t_context *ct);
t_3d_p	ft_apply_matrix(t_mat4 m, t_3d_p p);
t_mat4	ft_multiply_matrix(t_mat4 ma, t_mat4 mb);
void		ft_copy_matrix(t_mat4 *dest, t_mat4 src);

t_3d_p	*ft_convert_int_array(t_mesh *array);
void		ft_clear_array(t_3d_p **ret, int size);

t_2d_p	*ft_create_2d_point(int x, int y);

char		**ft_fdf_strsplit(char const *s, char c);

#endif /* !FT_FDF_H */
