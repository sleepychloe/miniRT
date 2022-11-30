/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_struct_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:00:17 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/30 22:16:37 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_BONUS_H
# define MINIRT_STRUCT_BONUS_H

# include "./miniRT_bonus.h"

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_rgb3
{
	double	r;
	double	g;
	double	b;
}	t_rgb3;

typedef struct s_ambient
{
	int			check;
	int			err;
	double		lighting;
	t_rgb3		rgb;
}	t_ambient;

typedef struct s_camera
{
	int			check;
	int			err;
	t_vec3		xyz_pos;
	t_vec3		xyz_vec;
	int			fov;
}	t_camera;

typedef struct s_light
{
	int			check;
	int			err;
	t_vec3		xyz_pos;
	double		brightness;
	t_rgb3		rgb;
}	t_light;

typedef struct s_sphere
{
	int			err;
	t_vec3		xyz_pos;
	double		diameter;
	t_rgb3		rgb;
}	t_sphere;

typedef struct s_plane
{
	int			err;
	t_vec3		xyz_pos;
	t_vec3		xyz_vec;
	t_rgb3		rgb;
}	t_plane;

typedef struct s_cylinder
{
	int			err;
	t_vec3		xyz_pos;
	t_vec3		xyz_vec;
	double		diameter;
	double		height;
	t_rgb3		rgb;
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

typedef struct s_obj
{
	int			obj_type;
	t_vec3		xyz_pos;
	t_vec3		xyz_vec;
	double		diameter;
	double		height;
	t_rgb3		rgb;
}	t_obj;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
	void		*img_ptr;
	char		*addr;
	int			line_length;
	int			bits_per_pixel;
	int			endian;
}	t_mlx;

typedef struct s_rt
{
	double		focal_length;
	double		viewport_width;
	double		viewport_height;
	t_vec3		vp_horizontal;
	t_vec3		vp_vertical;
	t_vec3		vp_low_left;
	t_vec3		cam_xyz_pos;
}	t_rt;

typedef struct s_ray
{
	t_vec3		point;
	t_vec3		direc;
}	t_ray;

typedef struct s_hit
{
	double		t;
	t_vec3		hit_point;
	t_vec3		normal_vec;
	int			front;
	t_rgb3		color;
}	t_hit;

typedef struct s_data
{
	t_scene		*keep_scene;
	t_scene		*scene;
	t_obj		**obj;
	t_mlx		*mlx;
	t_rt		*rt;
	t_ray		*ray;
	t_hit		*hit;
	int			n_obj;
	int			sp;
	int			pl;
	int			cy;
	t_vec3		x_normal;
	t_vec3		y_normal;
	t_vec3		z_normal;
}	t_data;

#endif