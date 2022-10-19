/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:51:02 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/19 17:20:01 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	init_struct_ambient(t_scene *scene)
{
	scene->ambient = (t_ambient *)malloc(sizeof(t_ambient));
	if (!(scene->ambient))
	{
		err_msg("Malloc error\n");
		free(scene);
		exit(1);
	}
	scene->ambient->cnt = 0;
	scene->ambient->err = 0;
	scene->ambient->lighting = 0.0;
	scene->ambient->r = 0;
	scene->ambient->g = 0;
	scene->ambient->b = 0;
}

void	init_struct_camera(t_scene *scene)
{
	scene->camera = (t_camera *)malloc(sizeof(t_camera));
	if (!(scene->camera))
	{
		err_msg("Malloc error\n");
		free(scene->ambient);
		free(scene);
		exit(1);
	}
	scene->camera->cnt = 0;
	scene->camera->err = 0;
	scene->camera->x_pos = 0.0;
	scene->camera->y_pos = 0.0;
	scene->camera->z_pos = 0.0;
	scene->camera->x_vec = 0;
	scene->camera->y_vec = 0;
	scene->camera->z_vec = 0;
	scene->camera->fov = 0.0;
}

void	init_struct_light(t_scene *scene)
{
	scene->light = (t_light *)malloc(sizeof(t_light));
	if (!(scene->light))
	{
		err_msg("Malloc error\n");
		free(scene->ambient);
		free(scene->camera);
		free(scene);
		exit(1);
	}
	scene->light->cnt = 0;
	scene->light->err = 0;
	scene->light->x_pos = 0.0;
	scene->light->y_pos = 0.0;
	scene->light->z_pos = 0.0;
	scene->light->brightness = 0.0;
	scene->light->r = 0;
	scene->light->g = 0;
	scene->light->b = 0;
}

void	init_struct(t_scene *scene)
{
	init_struct_ambient(scene);
	init_struct_camera(scene);
	init_struct_light(scene);
	init_struct_sphere(scene, 0);
	init_struct_plane(scene, 0);
	init_struct_cylinder(scene, 0);
}
