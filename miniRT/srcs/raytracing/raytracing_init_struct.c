/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_init_struct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:04:46 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/24 12:46:15 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	put_value_obj_sp_pl(t_scene *scene, t_obj **obj)
{
	int	i;

	i = 0;
	while (i < scene->n_sphere)
	{
		obj[i]->obj_type = SPHERE;
		obj[i]->xyz_pos = scene->sphere[i]->xyz_pos;
		obj[i]->diameter = scene->sphere[i]->diameter;
		obj[i]->height = 0;
		obj[i]->rgb = scene->sphere[i]->rgb;
		i++;
	}
	i = 0;
	while (i < scene->n_plane)
	{
		obj[scene->n_sphere + i]->obj_type = PLANE;
		obj[scene->n_sphere + i]->xyz_pos = scene->plane[i]->xyz_pos;
		obj[scene->n_sphere + i]->xyz_vec = scene->plane[i]->xyz_vec;
		obj[scene->n_sphere + i]->rgb = scene->plane[i]->rgb;
		i++;
	}
}

void	put_value_obj_cy(t_scene *scene, t_obj **obj)
{
	int	i;

	i = 0;
	while (i < scene->n_cylinder)
	{
		obj[scene->n_sphere + scene->n_plane + i]->obj_type
			= CYLINDER;
		obj[scene->n_sphere + scene->n_plane + i]->xyz_pos
			= scene->cylinder[i]->xyz_pos;
		obj[scene->n_sphere + scene->n_plane + i]->xyz_vec
			= scene->cylinder[i]->xyz_vec;
		obj[scene->n_sphere + scene->n_plane + i]->diameter
			= scene->cylinder[i]->diameter;
		obj[scene->n_sphere + scene->n_plane + i]->height
			= scene->cylinder[i]->height;
		obj[scene->n_sphere + scene->n_plane + i]->rgb
			= scene->cylinder[i]->rgb;
		i++;
	}
}

void	norminette_init_obj(t_scene *scene, t_obj **obj)
{
	int	i;

	i = 0;
	while (i < scene->n_sphere + scene->n_plane + scene->n_cylinder)
	{
		obj[i] = (t_obj *)ft_calloc(sizeof(t_obj), 2);
		if (!obj[i])
		{
			err_msg("Malloc error\n");
			free_obj(obj);
			free_scene(scene);
			exit (1);
		}
		i++;
	}
}

t_obj	**init_obj(t_scene *scene)
{
	t_obj	**obj;

	obj = (t_obj **)ft_calloc(sizeof(t_obj *),
			scene->n_sphere + scene->n_plane + scene->n_cylinder + 1);
	if (!obj)
	{
		err_msg("Malloc error");
		free_scene(scene);
		exit (1);
	}
	norminette_init_obj(scene, obj);
	put_value_obj_sp_pl(scene, obj);
	put_value_obj_cy(scene, obj);
	return (obj);
}

void	init_rt(t_scene *scene, t_rt *rt)
{
	rt->focal_length = 1;
	rt->viewport_height
		= 2 * rt->focal_length * tan(scene->camera->fov * PI / 360);
	rt->viewport_width = rt->viewport_height * ASPECT_RATIO_W / ASPECT_RATIO_H;
	rt->vp_horizontal = vec3(rt->viewport_width, 0, -1 * (rt->focal_length));
	rt->vp_vertical
		= vec3(0, -1 * (rt->viewport_height), -1 * (rt->focal_length));
	rt->vp_low_left
		= vec3(-1 * (rt->vp_horizontal.x) / 2,
			-1 * (rt->vp_vertical.y) / 2, -1 * (rt->focal_length));
	rt->cam_xyz_pos = scene->camera->xyz_pos;
}
