/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init_struct_keep_scene_1_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:35:44 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/30 21:43:38 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	init_struct_keep_scene_a(t_scene *keep_scene, t_scene *scene)
{
	keep_scene->ambient = (t_ambient *)ft_calloc(sizeof(t_ambient), 2);
	if (!(keep_scene->ambient))
	{
		err_msg("Malloc error\n");
		free(keep_scene);
		free_scene(scene);
		exit(1);
	}
	keep_scene->ambient->check = scene->ambient->check;
	keep_scene->ambient->err = scene->ambient->err;
	keep_scene->ambient->lighting = scene->ambient->lighting;
	keep_scene->ambient->rgb = scene->ambient->rgb;
}

void	init_struct_keep_scene_c(t_scene *keep_scene, t_scene *scene)
{
	keep_scene->camera = (t_camera *)ft_calloc(sizeof(t_camera), 2);
	if (!(keep_scene->camera))
	{
		err_msg("Malloc error\n");
		free(keep_scene->ambient);
		free(keep_scene);
		free_scene(scene);
		exit(1);
	}
	keep_scene->camera->check = scene->camera->check;
	keep_scene->camera->err = scene->camera->err;
	keep_scene->camera->xyz_pos = scene->camera->xyz_pos;
	keep_scene->camera->xyz_vec = scene->camera->xyz_vec;
	keep_scene->camera->fov = scene->camera->fov;
}

void	init_struct_keep_scene_l(t_scene *keep_scene, t_scene *scene)
{
	keep_scene->light = (t_light *)ft_calloc(sizeof(t_light), 2);
	if (!(keep_scene->light))
	{
		err_msg("Malloc error\n");
		free(keep_scene->ambient);
		free(keep_scene->camera);
		free(keep_scene);
		free_scene(scene);
		exit(1);
	}
	keep_scene->light->check = scene->light->check;
	keep_scene->light->err = scene->light->err;
	keep_scene->light->xyz_pos = scene->light->xyz_pos;
	keep_scene->light->brightness = scene->light->brightness;
	keep_scene->light->rgb = scene->light->rgb;
}

void	init_struct_keep_scene(t_scene *keep_scene, t_scene *scene)
{
	init_struct_keep_scene_a(keep_scene, scene);
	init_struct_keep_scene_c(keep_scene, scene);
	init_struct_keep_scene_l(keep_scene, scene);
	init_struct_keep_scene_sp(keep_scene, scene);
	init_struct_keep_scene_pl(keep_scene, scene);
	init_struct_keep_scene_cy(keep_scene, scene);
}
