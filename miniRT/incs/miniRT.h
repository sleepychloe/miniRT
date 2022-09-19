/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sucho <sucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 08:13:03 by sucho             #+#    #+#             */
/*   Updated: 2022/09/15 16:36:31 by sucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/incs/libft.h"
# include "../libft/incs/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>



typedef struct s_ambient
{
	char	*ratio;
	int		r;
	int		g;
	int		b;
}	t_ambient;

typedef struct s_camera
{
	char	*x_coord;
	char	*y_coord;
	char	*z_coord;
	int		x_vec;
	int		y_vec;
	int		z_vec;
	int		fov;
}	t_camera;

typedef struct s_light
{
	char	*x_coord;
	char	*y_coord;
	char	*z_coord;
	char	*ratio;
	int		r;
	int		g;
	int		b;
}	t_light;

typedef struct s_sphere
{
	char	*x_coord;
	char	*y_coord;
	char	*z_coord;
	char	*diameter;
	int		r;
	int		g;
	int		b;
}	t_sphere;

typedef struct s_plane
{
	char	*x_coord;
	char	*y_coord;
	char	*z_coord;
	int		x_vec;
	int		y_vec;
	int		z_vec;
	int		r;
	int		g;
	int		b;
}	t_plane;

typedef struct s_cylinder
{
	char	*x_coord;
	char	*y_coord;
	char	*z_coord;
	int		x_vec;
	int		y_vec;
	int		z_vec;
	char	*diameter;
	char	*height;
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


/*
**	main.c
*/


/*
**	scene_parse.c
*/

/*
**	utils.c
*/

void	print_error_and_exit(char *str);
int		check_file_extention(char *str);
int	check_identifier(char *str, char *head);

/*
**	parse_utils.c
*/

int	check_token_counter(char *str, char delim, int count);
void	free_2d(char **str);

/*
**	parse_ambient.c
*/

int parse_ambient_ratio(t_scene *scene, char *s);
int	parse_ambient_rgb(t_scene *scene, char *s);
void	parse_ambient(t_scene *scene, char *s);

/*
**	parse_camera.c
*/

int parse_camera_norm_vec(t_scene *scene, char *s);
int parse_camera_xyz(t_scene *scene, char *s);
int parse_camera_fov(t_scene *scene, char *s);
void    parse_camera(t_scene *scene, char *s);

/*
**	parse_light.c
*/

int parse_light_xyz(t_scene *scene, char *s);
int parse_light_ratio(t_scene *scene, char *s);
int	parse_light_rgb(t_scene *scene, char *s);
void    parse_light(t_scene *scene, char *s);

/*
**	parse_sphere.c
*/

int parse_sphere_xyz(t_scene *scene, char *s, int i);
int parse_sphere_diameter(t_scene *scene, char *s, int i);
int	parse_sphere_rgb(t_scene *scene, char *s, int i);
void    parse_sphere(t_scene *scene, char *s);

/*
**	parse_plane.c
*/

int parse_plane_xyz(t_scene *scene, char *s, int i);
int parse_plane_norm_vec(t_scene *scene, char *s, int i);
int	parse_plane_rgb(t_scene *scene, char *s, int i);
void    parse_plane(t_scene *scene, char *s);

/*
**	parse_cylinder.c
*/

int parse_cylinder_xyz(t_scene *scene, char *s, int i);
int parse_cylinder_norm_vec(t_scene *scene, char *s, int i);
int parse_cylinder_diameter(t_scene *scene, char *s, int i);
int parse_cylinder_height(t_scene *scene, char *s, int i);
int	parse_cylinder_rgb(t_scene *scene, char *s, int i);
void    parse_cylinder(t_scene *scene, char *s);

#endif
