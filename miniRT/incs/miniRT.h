/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:15:19 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/22 23:00:33 by yhwang           ###   ########.fr       */
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
	int		check;
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
	int		check;
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
	int		check;
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
void	init_struct_ambient(t_scene *scene);
void	init_struct_camera(t_scene *scene);
void	init_struct_light(t_scene *scene);
void	init_struct(t_scene *scene);

// init_struct_2
void	init_struct_sphere(t_scene *scene, int i);
void	init_struct_plane(t_scene *scene, int i);
void	init_struct_cylinder(t_scene *scene, int i);

// parse_arg
int		check_extention(char *str);
void	parse_arg(t_scene *scene, char *argv);

// parse_map
void	finish_gnl(t_scene *scene, char **line, int fd, int err);
void	check_id(t_scene *scene, char **line, int fd);
void	parse_map(t_scene *scene, char *argv);

// parse_ambient
int		parse_ambient_token(t_scene *scene, char ***s);
int		parse_ambient_lighting(t_scene *scene, char ***s);
int		check_value_ambient_rgb(t_scene *scene, char **rgb);
int		parse_ambient_rgb(t_scene *scene, char ***s);
void	parse_ambient(t_scene *scene, char **line);

// parse_camera_1
int		parse_camera_token(t_scene *scene, char ***s);
int		check_value_camera_xyz_pos(t_scene *scene, char **xyz_pos);
int		parse_camera_xyz_pos(t_scene *scene, char ***s);
void	parse_camera(t_scene *scene, char **line);

// parse_camera_2
int		check_value_camera_xyz_vec(t_scene *scene, char **xyz_vec);
int		parse_camera_xyz_vec(t_scene *scene, char ***s);
int		parse_camera_fov(t_scene *scene, char ***s);

// parse_light_1
int		parse_light_token(t_scene *scene, char ***s);
int		check_value_light_xyz_pos(t_scene *scene, char **xyz_pos);
int		parse_light_xyz_pos(t_scene *scene, char ***s);
int		parse_light_brightness(t_scene *scene, char ***s);
void	parse_light(t_scene *scene, char **line);

// parse_light_2
int		check_value_light_rgb(t_scene *scene, char **rgb);
int		parse_light_rgb(t_scene *scene, char ***s);

// parse_sphere_1
int		parse_sphere_token(t_scene *scene, int i, char ***s);
int		check_value_sphere_xyz_pos(t_scene *scene, int i, char **xyz_pos);
int		parse_sphere_xyz_pos(t_scene *scene, int i, char ***s);
int		parse_sphere_diameter(t_scene *scene, int i, char ***s);
void	parse_sphere(t_scene *scene, char **line);

// parse_sphere_2
int		check_value_sphere_rgb(t_scene *scene, int i, char **rgb);
int		parse_sphere_rgb(t_scene *scene, int i, char ***s);

// parse_plane_1
int		parse_plane_token(t_scene *scene, int i, char ***s);
int		check_value_plane_xyz_pos(t_scene *scene, int i, char **xyz_pos);
int		parse_plane_xyz_pos(t_scene *scene, int i, char ***s);
void	parse_plane(t_scene *scene, char **line);

// parse_plane_2
int		check_value_plane_xyz_vec(t_scene *scene, int i, char **xyz_vec);
int		parse_plane_xyz_vec(t_scene *scene, int i, char ***s);
int		check_value_plane_rgb(t_scene *scene, int i, char **rgb);
int		parse_plane_rgb(t_scene *scene, int i, char ***s);

// parse_cylinder_1
int		parse_cylinder_token(t_scene *scene, int i, char ***s);
int		check_value_cylinder_xyz_pos(t_scene *scene, int i, char **xyz_pos);
int		parse_cylinder_xyz_pos(t_scene *scene, int i, char ***s);
int		parse_cylinder_diameter(t_scene *scene, int i, char ***s);
void	parse_cylinder(t_scene *scene, char **line);

// parse_cylinder_2
int		parse_cylinder_height(t_scene *scene, int i, char ***s);
int		check_value_cylinder_xyz_vec(t_scene *scene, int i, char **xyz_vec);
int		parse_cylinder_xyz_vec(t_scene *scene, int i, char ***s);
int		check_value_cylinder_rgb(t_scene *scene, int i, char **rgb);
int		parse_cylinder_rgb(t_scene *scene, int i, char ***s);

// parse_err_1
int		err_check_ambient(t_scene *scene);
int		err_check_camera(t_scene *scene);
int		err_check_light(t_scene *scene);
int		check_parse_error(t_scene *scene);

// parse_err_2
int		err_check_sphere(t_scene *scene);
int		err_check_plane(t_scene *scene);
int		err_check_cylinder(t_scene *scene);

// utils
void	err_msg(char *str);
int		token_count(char **token, int cnt);

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