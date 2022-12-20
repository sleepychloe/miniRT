/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_init_struct_obj_2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:50:12 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/20 09:23:06 by yhwang           ###   ########.fr       */
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

void	put_value_obj_pl_dup(t_scene *scene, t_obj **obj, int n_obj)
{
	int	i;

	i = 0;
	while (i < scene->n_plane)
	{
		obj[n_obj + i]->obj_type = PLANE;
		obj[n_obj + i]->xyz_pos = scene->plane[i]->xyz_pos;
		obj[n_obj + i]->xyz_vec = scene->plane[i]->xyz_vec;
		obj[n_obj + i]->rgb = scene->plane[i]->rgb;
		obj[n_obj + i]->xyz_pos = vec3_sub_vec3(scene->plane[i]->xyz_pos,
				vec3_mul_rn(scene->plane[i]->xyz_vec, DELTA));
		obj[n_obj + i]->xyz_vec.x *= -1;
		obj[n_obj + i]->xyz_vec.y *= -1;
		obj[n_obj + i]->xyz_vec.z *= -1;
		i++;
	}
}
