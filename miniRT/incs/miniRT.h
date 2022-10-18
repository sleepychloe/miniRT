/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:15:19 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/18 20:43:54 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/incs/libft.h"
# include "../libft/incs/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct  s_ambient
{
    int     cnt;
    int     err;
    double  ratio;
    int     r;
    int     g;
    int     b;
}   t_ambient;

//x,y,z_pos should be double
//x,y,z_vec range [-1.0,1.0]
//fov range[0,180]
typedef struct s_camera
{
    int     cnt;
    int     err;
	double  x_pos;
	double  y_pos;
    double  z_pos;
	int		x_vec;
	int		y_vec;
	int		z_vec;
	int		fov;
}	t_camera;

//x,y,z_pos should be double
//ratio range [0.0,1.0]
//rgb range [0-255]
typedef struct s_light
{
    int     cnt;
	double  x_pos;
	double  y_pos;
    double  z_pos;
	double  ratio;
	int		r;
	int		g;
	int		b;
}	t_light;

//x,y,z_pos should be double
//diameter should be double
//rgb range [0-255]
typedef struct s_sphere
{
    int     cnt;
	double  x_pos;
	double  y_pos;
    double  z_pos;
	double  diameter;
	int		r;
	int		g;
	int		b;
}	t_sphere;

//x,y,z_pos should be double
//x,y,z_vec range [-1.0,1.0]
//rgb range [0-255]
typedef struct s_plane
{
    int     cnt;
	double  x_pos;
	double  y_pos;
    double  z_pos;
	int		x_vec;
	int		y_vec;
	int		z_vec;
	int		r;
	int		g;
	int		b;
}	t_plane;

//x,y,z_pos should be double
//x,y,z_vec range [-1.0,1.0]
//diameter should be double
//height should be double
//rgb range [0-255]
typedef struct s_cylinder
{
    int     cnt;
	double  x_pos;
	double  y_pos;
    double  z_pos;
	int		x_vec;
	int		y_vec;
	int		z_vec;
	double  diameter;
	double  height;
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

//parse_arg
int     check_extention(char *str);
void    parse_arg(char *argv);

//parse_map
int     check_id(t_scene *scene, char **line);
void    parse_map(t_scene *scene, char *argv);

//init_struct_1
void    init_struct_ambient(t_scene *scene);
void    init_struct_camera(t_scene *scene);
void    init_struct_light(t_scene *scene);
void    init_struct(t_scene *scene);

//init_struct_2
void    init_struct_sphere(t_scene *scene);
void    init_struct_plane(t_scene *scene);
void    init_struct_cylinder(t_scene *scene);

//parse_ambient
int     parse_ambient_ratio(t_scene *scene, char *s);
int     parse_ambient_rgb(t_scene *scene, char *s);
void    parse_ambient(t_scene *scene, char **line);

//parse_camera
int     parse_camera_xyz(t_scene *scene, char *s);
int     parse_camera_norm_vec(t_scene *scene, char *s);
int     parse_camera_fov(t_scene *scene, char *s);
void    parse_camera(t_scene *scene, char **line);

//parse_utils
int     check_line_token(char **line, int cnt);
int     check_small_token(char *token);

//utils
void    err_msg(char *str);
void    ft_free_2d(char **str);
void    ft_free_struct(t_scene *scene);


//main
/**/
int     check_err_in_struct(t_scene *scene);
int     minirt_main(char **argv);
int     main(int argc, char **argv);

#endif