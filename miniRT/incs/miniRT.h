/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:15:19 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/24 18:50:55 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define ERR_ATOI	-9999
# define ERR_ATOD	-9999.0

# define ERR_MALLOC		1
# define ERR_IDENTIFIER		2
# define ERR_LINE_TOKEN		3

# define ERR_LIGHTING_VALUE	4
# define ERR_FOV_VALUE		5
# define ERR_BRIGHTNESS_VALUE	6
# define ERR_DIAMETER_VALUE	7
# define ERR_HEIGHT_VALUE	8

# define ERR_RGB_TOKEN		9
# define ERR_RGB_VALUE		10
# define ERR_XYZ_POS_TOKEN	11
# define ERR_XYZ_POS_VALUE	12
# define ERR_XYZ_VEC_TOKEN	13
# define ERR_XYZ_VEC_VALUE	14

# include "../libft/incs/libft.h"
# include "../libft/incs/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_ambient
{
	int		check;
	int		err;
	double	lighting;
	int		r;
	int		g;
	int		b;
}	t_ambient;

typedef struct s_camera
{
	int		check;
	int		err;
	double	x_pos;
	double	y_pos;
	double	z_pos;
	int		x_vec;
	int		y_vec;
	int		z_vec;
	int		fov;
}	t_camera;

typedef struct s_light
{
	int		check;
	int		err;
	double	x_pos;
	double	y_pos;
	double	z_pos;
	double	brightness;
	int		r;
	int		g;
	int		b;
}	t_light;

typedef struct s_sphere
{
	int		err;
	double	x_pos;
	double	y_pos;
	double	z_pos;
	double	diameter;
	int		r;
	int		g;
	int		b;
}	t_sphere;

typedef struct s_plane
{
	int		err;
	double	x_pos;
	double	y_pos;
	double	z_pos;
	int		x_vec;
	int		y_vec;
	int		z_vec;
	int		r;
	int		g;
	int		b;
}	t_plane;

typedef struct s_cylinder
{
	int		err;
	double	x_pos;
	double	y_pos;
	double	z_pos;
	int		x_vec;
	int		y_vec;
	int		z_vec;
	double	diameter;
	double	height;
	int		r;
	int		g;
	int		b;
}	t_cylinder;

typedef struct s_scene
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;
	t_sphere	**sphere;
	t_plane		**plane;
	t_cylinder	**cylinder;
	int			n_sphere;
	int			n_plane;
	int			n_cylinder;
}	t_scene;

// init_struct_1
void	init_struct_a(t_scene *scene);
void	init_struct_c(t_scene *scene);
void	init_struct_l(t_scene *scene);
void	init_struct(t_scene *scene);

// init_struct_2
void	init_struct_sp(t_scene *scene, int i);
void	init_struct_pl(t_scene *scene, int i);
void	init_struct_cy(t_scene *scene, int i);

// parse_arg
int		check_extention(char *str);
void	parse_arg(t_scene *scene, char *argv);

// parse_map
void	finish_gnl(t_scene *scene, char **line, int fd, int err);
char	**check_line(char **line);
int		check_id(t_scene *scene, char **line);
void	parse_map(t_scene *scene, char *argv);

// parse_ambient_1
int		parse_a_norminette(t_scene *scene, char ***s);
int		parse_a(t_scene *scene, char **line);

// parse_ambient_2
int		parse_a_token(t_scene *scene, char ***s);
int		parse_a_lighting(t_scene *scene, char ***s);
int		check_value_a_rgb(t_scene *scene, char **rgb);
int		parse_a_rgb(t_scene *scene, char ***s);

// parse_camera_1
int		parse_c_token(t_scene *scene, char ***s);
int		check_value_c_xyz_pos(t_scene *scene, char **xyz_pos);
int		parse_c_xyz_pos(t_scene *scene, char ***s);
int		parse_c_norminette(t_scene *scene, char ***s);
int		parse_c(t_scene *scene, char **line);

// parse_camera_2
int		check_value_c_xyz_vec(t_scene *scene, char **xyz_vec);
int		parse_c_xyz_vec(t_scene *scene, char ***s);
int		parse_c_fov(t_scene *scene, char ***s);

// parse_light_1
int		parse_l_token(t_scene *scene, char ***s);
int		check_value_l_xyz_pos(t_scene *scene, char **xyz_pos);
int		parse_l_xyz_pos(t_scene *scene, char ***s);
int		parse_l_norminette(t_scene *scene, char ***s);
int		parse_l(t_scene *scene, char **line);

// parse_light_2
int		parse_l_brightness(t_scene *scene, char ***s);
int		check_value_l_rgb(t_scene *scene, char **rgb);
int		parse_l_rgb(t_scene *scene, char ***s);

// parse_sphere_1
int		parse_sp_token(t_scene *scene, int i, char ***s);
int		check_value_sp_xyz_pos(t_scene *scene, int i, char **xyz_pos);
int		parse_sp_xyz_pos(t_scene *scene, int i, char ***s);
int		parse_sp_norminette(t_scene *scene, int i, char ***s);
int		parse_sp(t_scene *scene, char **line);

// parse_sphere_2
int		parse_sp_diameter(t_scene *scene, int i, char ***s);
int		check_value_sp_rgb(t_scene *scene, int i, char **rgb);
int		parse_sp_rgb(t_scene *scene, int i, char ***s);

// parse_plane_1
int		parse_pl_token(t_scene *scene, int i, char ***s);
int		check_value_pl_xyz_pos(t_scene *scene, int i, char **xyz_pos);
int		parse_pl_xyz_pos(t_scene *scene, int i, char ***s);
int		parse_pl_norminette(t_scene *scene, int i, char ***s);
int		parse_pl(t_scene *scene, char **line);

// parse_plane_2
int		check_value_pl_xyz_vec(t_scene *scene, int i, char **xyz_vec);
int		parse_pl_xyz_vec(t_scene *scene, int i, char ***s);
int		check_value_pl_rgb(t_scene *scene, int i, char **rgb);
int		parse_pl_rgb(t_scene *scene, int i, char ***s);

// parse_cylinder_1
int		parse_cy_token(t_scene *scene, int i, char ***s);
int		check_value_cy_xyz_pos(t_scene *scene, int i, char **xyz_pos);
int		parse_cy_xyz_pos(t_scene *scene, int i, char ***s);
int		parse_cy_norminette(t_scene *scene, int i, char ***s);
int		parse_cy(t_scene *scene, char **line);

// parse_cylinder_2
int		parse_cy_diameter(t_scene *scene, int i, char ***s);
int		parse_cy_height(t_scene *scene, int i, char ***s);
int		check_value_cy_xyz_vec(t_scene *scene, int i, char **xyz_vec);
int		parse_cy_xyz_vec(t_scene *scene, int i, char ***s);

// parse_cylinder_3
int		check_value_cy_rgb(t_scene *scene, int i, char **rgb);
int		parse_cy_rgb(t_scene *scene, int i, char ***s);

// parse_err_1
void	err_check_a(t_scene *scene);
void	err_check_c(t_scene *scene);
void	err_check_l(t_scene *scene);
int		check_parse_error(t_scene *scene);

// parse_err_2
void	err_check_sp(t_scene *scene, int i);
void	err_check_pl(t_scene *scene, int i);
void	err_check_cy(t_scene *scene, int i);

// utils
void	err_msg(char *str);
void	map_err_i(int i, char *id, char *str);
int		token_count(char **token, int cnt);

// utils_split
char	**ft_split_comma(char const *s, char c);

// utils_free
void	*ft_realloc(void *old_ptr, size_t old_len, size_t new_len);
void	ft_free_2d(char **str);
void	ft_free_3d(char ***str);
void	ft_free_struct(t_scene *scene);

// main
int		check_err_in_struct(t_scene *scene);
int		minirt_main(char **argv);
int		main(int argc, char **argv);

#endif