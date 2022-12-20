/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_init_struct_obj_2_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:50:12 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/20 19:42:18 by yhwang           ###   ########.fr       */
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
		obj[i]->xyz_vec = vec3(0, 0, 0);
		obj[i]->diameter = scene->sphere[i]->diameter;
		obj[i]->height = 0;
		obj[i]->surface = scene->sphere[i]->surface;
		obj[i]->fuzz = scene->sphere[i]->fuzz;
		obj[i]->rgb1 = scene->sphere[i]->rgb1;
		obj[i]->rgb2 = scene->sphere[i]->rgb2;
		obj[i]->img_path
			= realloc_img_texture_path(obj[i]->img_path,
				scene->sphere[i]->img_path);
		obj[i]->texture_path
			= realloc_img_texture_path(obj[i]->texture_path,
				scene->sphere[i]->texture_path);
		i++;
	}
}

void	put_value_obj_pl(t_scene *scene, t_obj **obj)
{
	int	i;
	int	n;

	i = 0;
	n = scene->n_sphere;
	while (i < scene->n_plane)
	{
		obj[n + i]->obj_type = PLANE;
		obj[n + i]->xyz_pos = scene->plane[i]->xyz_pos;
		obj[n + i]->xyz_vec = scene->plane[i]->xyz_vec;
		obj[n + i]->diameter = 0;
		obj[n + i]->height = 0;
		obj[n + i]->surface = scene->plane[i]->surface;
		obj[n + i]->fuzz = scene->plane[i]->fuzz;
		obj[n + i]->rgb1 = scene->plane[i]->rgb1;
		obj[n + i]->rgb2 = scene->plane[i]->rgb2;
		obj[n + i]->img_path
			= realloc_img_texture_path(obj[n + i]->img_path,
				scene->plane[i]->img_path);
		obj[n + i]->texture_path
			= realloc_img_texture_path(obj[n + i]->texture_path,
				scene->plane[i]->texture_path);
		i++;
	}
}

void	put_value_obj_cy(t_scene *scene, t_obj **obj)
{
	int	i;
	int	n;

	i = 0;
	n = scene->n_sphere + scene->n_plane;
	while (i < scene->n_cylinder)
	{
		obj[n + i]->obj_type = CYLINDER;
		obj[n + i]->xyz_pos = scene->cylinder[i]->xyz_pos;
		obj[n + i]->xyz_vec = scene->cylinder[i]->xyz_vec;
		obj[n + i]->diameter = scene->cylinder[i]->diameter;
		obj[n + i]->height = scene->cylinder[i]->height;
		obj[n + i]->surface = scene->cylinder[i]->surface;
		obj[n + i]->fuzz = scene->cylinder[i]->fuzz;
		obj[n + i]->rgb1 = scene->cylinder[i]->rgb1;
		obj[n + i]->rgb2 = scene->cylinder[i]->rgb2;
		obj[n + i]->img_path
			= realloc_img_texture_path(obj[n + i]->img_path,
				scene->cylinder[i]->img_path);
		obj[n + i]->texture_path
			= realloc_img_texture_path(obj[n + i]->texture_path,
				scene->cylinder[i]->texture_path);
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
		obj[n + i]->surface = scene->cone[i]->surface;
		obj[n + i]->fuzz = scene->cone[i]->fuzz;
		obj[n + i]->rgb1 = scene->cone[i]->rgb1;
		obj[n + i]->rgb2 = scene->cone[i]->rgb2;
		obj[n + i]->img_path
			= realloc_img_texture_path(obj[n + i]->img_path,
				scene->cone[i]->img_path);
		obj[n + i]->texture_path
			= realloc_img_texture_path(obj[n + i]->texture_path,
				scene->cone[i]->texture_path);
		i++;
	}
}
