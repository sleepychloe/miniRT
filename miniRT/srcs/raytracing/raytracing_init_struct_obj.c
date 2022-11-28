/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_init_struct_obj.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 07:42:51 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/28 07:43:41 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	put_value_obj_sp(t_scene *scene, t_obj **obj)
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
}

void	put_value_obj_pl(t_scene *scene, t_obj **obj)
{
	int	i;

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
	put_value_obj_sp(scene, obj);
	put_value_obj_pl(scene, obj);
	put_value_obj_cy(scene, obj);
	return (obj);
}
