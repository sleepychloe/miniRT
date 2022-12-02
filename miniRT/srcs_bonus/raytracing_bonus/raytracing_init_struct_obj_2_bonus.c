/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_init_struct_obj_2_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:50:12 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/02 00:52:34 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

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

void	put_value_obj_co(t_scene *scene, t_obj **obj)
{
	int	i;
	int	n;

	i = 0;
	n = scene->n_sphere + scene->n_plane + scene->n_cylinder;
	while (i < scene->n_cone)
	{
		obj[n + i]->obj_type = CONE;
		obj[n + i]->xyz_pos = scene->cone[i]->xyz_pos;
		obj[n + i]->xyz_vec = scene->cone[i]->xyz_vec;
		obj[n + i]->diameter = scene->cone[i]->diameter;
		obj[n + i]->height = scene->cone[i]->height;
		obj[n + i]->rgb = scene->cone[i]->rgb;
		i++;
	}
}
