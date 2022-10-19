/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:15:19 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/19 23:13:22 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/incs/libft.h"
# include "../libft/incs/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

/*
lighting range [0.0,1.0]
rgb range [0-255]
err code	1: identifier error
		2: line token error
		3: lighting value error
		4: rbg token error
		5: rgb value error
*/
typedef struct s_ambient
{
	int		cnt;
	int		err;
	double	lighting;
	int		r;
	int		g;
	int		b;
}	t_ambient;

/*
x,y,z_pos should be double
x,y,z_vec range [-1.0,1.0]
fov range[0,180]
err code	1: identifier error
		2: line token error
		3: xyz position token error
		4: xyz position value error
		5: xyz normalized vector token error
		6: xyz normalized vector value error
		7: fov value error
*/
typedef struct s_camera
{
	int		cnt;
	int		err;
	double	x_pos;
	double	y_pos;
	double	z_pos;
	int		x_vec;
	int		y_vec;
	int		z_vec;
	int		fov;
}	t_camera;

/*
x,y,z_pos should be double
brightness range [0.0,1.0]
rgb range [0-255]
err code	1: identifier error
		2: line token error
		3: xyz position token error
		4: xyz position value error
		5: brightness value error
		6: rbg token error
		7: rgb value error
*/
typedef struct s_light
{
	int		cnt;
	int		err;
	double	x_pos;
	double	y_pos;
	double	z_pos;
	double	brightness;
	int		r;
	int		g;
	int		b;
}	t_light;

/*
x,y,z_pos should be double
diameter should be double
rgb range [0-255]
err code	1:
		2:
		3:
		4:
		5:
		6:
*/
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

/*
x,y,z_pos should be double
x,y,z_vec range [-1.0,1.0]
rgb range [0-255]
*/
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

/*
x,y,z_pos should be double
x,y,z_vec range [-1.0,1.0]
diameter should be double
height should be double
rgb range [0-255]
*/
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
int	parse_ambient_token(t_scene *scene, char **token);
int	parse_ambient_lighting(t_scene *scene, char **token);
int	put_ambient_rgb(t_scene *scene, char **rgb);
int	parse_ambient_rgb(t_scene *scene, char **token, char **rgb);
void	parse_ambient(t_scene *scene, char **line);

// parse_camera
int	parse_camera_token(t_scene *scene, char **token);
int	put_camera_xyz_pos(t_scene *scene, char **xyz_pos);
int	parse_camera_xyz_pos(t_scene *scene, char **token, char **xyz_pos);
int	put_camera_xyz_vec(t_scene *scene, char **xyz_vec);
int	parse_camera_xyz_vec(t_scene *scene, char **token, char **xyz_pos,
		char **xyz_vec);
int	parse_camera_fov(t_scene *scene, char **token, char **xyz_pos,
		char **xyz_vec);
void	parse_camera(t_scene *scene, char **line);

/*
// parse_light
int		parse_light_xyz(t_scene *scene, char *s);
int		parse_light_brightness(t_scene *scene, char *s);
int		parse_light_rgb(t_scene *scene, char *s);
void	parse_light(t_scene *scene, char **line);
*/

// parse_err_1
int		err_check_ambient(t_scene *scene);
int		err_check_camera(t_scene *scene);
int		err_check_light(t_scene *scene);
int		check_parse_error(t_scene *scene);

// utils
int		token_count(char **token, int cnt);
void	err_msg(char *str);
void	ft_free_2d(char **str);
void	ft_free_struct(t_scene *scene);

// main
int		check_err_in_struct(t_scene *scene);
int		minirt_main(char **argv);
int		main(int argc, char **argv);

#endif