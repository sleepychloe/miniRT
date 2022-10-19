/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0002/01/18 19:05:39 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/19 17:19:44 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	init_struct_sphere(t_scene *scene, int i)
{
	if (i == 0)
		scene->sphere = (t_sphere **)malloc(sizeof(t_sphere *));
	scene->sphere[i] = (t_sphere *)malloc(sizeof(t_sphere));
	if (!(scene->sphere[i]))
	{
		ft_free_struct(scene);
		err_msg("Malloc error\n");
		exit(1);
	}
	scene->sphere[i]->check = 0;
	scene->sphere[i]->err = 0;
	scene->sphere[i]->x_pos = 0.0;
	scene->sphere[i]->y_pos = 0.0;
	scene->sphere[i]->z_pos = 0.0;
	scene->sphere[i]->diameter = 0.0;
	scene->sphere[i]->r = 0;
	scene->sphere[i]->g = 0;
	scene->sphere[i]->b = 0;
}

void	init_struct_plane(t_scene *scene, int i)
{
	if (i == 0)
		scene->plane = (t_plane **)malloc(sizeof(t_plane *));
	scene->plane[i] = (t_plane *)malloc(sizeof(t_plane));
	if (!(scene->plane[i]))
	{
		ft_free_struct(scene);
		err_msg("Malloc error\n");
		exit(1);
	}
	scene->plane[i]->check = 0;
	scene->plane[i]->err = 0;
	scene->plane[i]->x_pos = 0.0;
	scene->plane[i]->y_pos = 0.0;
	scene->plane[i]->z_pos = 0.0;
	scene->plane[i]->x_vec = 0;
	scene->plane[i]->y_vec = 0;
	scene->plane[i]->z_vec = 0;
	scene->sphere[i]->r = 0;
	scene->sphere[i]->g = 0;
	scene->sphere[i]->b = 0;
}

void	init_struct_cylinder(t_scene *scene, int i)
{
	if (i == 0)
		scene->cylinder = (t_cylinder **)malloc(sizeof(t_cylinder *));
	scene->cylinder[i] = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!(scene->cylinder[i]))
	{
		ft_free_struct(scene);
		err_msg("Malloc error\n");
		exit(1);
	}
	scene->cylinder[i]->check = 0;
	scene->cylinder[i]->err = 0;
	scene->cylinder[i]->x_pos = 0.0;
	scene->cylinder[i]->y_pos = 0.0;
	scene->cylinder[i]->z_pos = 0.0;
	scene->cylinder[i]->x_vec = 0;
	scene->cylinder[i]->y_vec = 0;
	scene->cylinder[i]->z_vec = 0;
	scene->cylinder[i]->diameter = 0.0;
	scene->cylinder[i]->height = 0.0;
	scene->cylinder[i]->r = 0;
	scene->cylinder[i]->g = 0;
	scene->cylinder[i]->b = 0;
}
