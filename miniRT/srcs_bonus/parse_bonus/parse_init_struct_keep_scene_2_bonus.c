/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init_struct_keep_scene_2_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:45:41 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/16 05:16:29 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	put_value_keep_scene_sp(t_scene *keep_scene, t_scene *scene)
{
	int	i;

	i = 0;
	while (i < scene->n_sphere)
	{
		keep_scene->sphere[i]->err = scene->sphere[i]->err;
		keep_scene->sphere[i]->xyz_pos = scene->sphere[i]->xyz_pos;
		keep_scene->sphere[i]->diameter = scene->sphere[i]->diameter;
		keep_scene->sphere[i]->surface = scene->sphere[i]->surface;
		keep_scene->sphere[i]->fuzz = scene->sphere[i]->fuzz;
		keep_scene->sphere[i]->rgb1 = scene->sphere[i]->rgb1;
		keep_scene->sphere[i]->rgb2 = scene->sphere[i]->rgb2;
		keep_scene->sphere[i]->img_path
			= realloc_img_texture_path(keep_scene->sphere[i]->img_path,
				scene->sphere[i]->img_path);
		keep_scene->sphere[i]->texture_path
			= realloc_img_texture_path(keep_scene->sphere[i]->texture_path,
				scene->sphere[i]->texture_path);
		i++;
	}
}

void	init_struct_keep_scene_sp(t_scene *keep_scene, t_scene *scene)
{
	int	i;

	i = 0;
	keep_scene->sphere = (t_sphere **)ft_calloc(sizeof(t_sphere *),
			scene->n_sphere + 1);
	if (!(keep_scene->sphere))
	{
		err_msg("Malloc error");
		free_scene(keep_scene);
		free_scene(scene);
		exit(1);
	}
	while (i < scene->n_sphere)
	{
		keep_scene->sphere[i] = (t_sphere *)ft_calloc(sizeof(t_sphere), 2);
		if (!(keep_scene->sphere[i]))
		{
			err_msg("Malloc error");
			free_scene(keep_scene);
			free_scene(scene);
			exit(1);
		}
		i++;
	}
	put_value_keep_scene_sp(keep_scene, scene);
}

void	put_value_keep_scene_pl(t_scene *keep_scene, t_scene *scene)
{
	int	i;

	i = 0;
	while (i < scene->n_plane)
	{
		keep_scene->plane[i]->err = scene->plane[i]->err;
		keep_scene->plane[i]->xyz_pos = scene->plane[i]->xyz_pos;
		keep_scene->plane[i]->xyz_vec = scene->plane[i]->xyz_vec;
		keep_scene->plane[i]->surface = scene->plane[i]->surface;
		keep_scene->plane[i]->fuzz = scene->plane[i]->fuzz;
		keep_scene->plane[i]->rgb1 = scene->plane[i]->rgb1;
		keep_scene->plane[i]->rgb2 = scene->plane[i]->rgb2;
		keep_scene->plane[i]->img_path
			= realloc_img_texture_path(keep_scene->plane[i]->img_path,
				scene->plane[i]->img_path);
		keep_scene->plane[i]->texture_path
			= realloc_img_texture_path(keep_scene->plane[i]->texture_path,
				scene->plane[i]->texture_path);
		i++;
	}
}

void	init_struct_keep_scene_pl(t_scene *keep_scene, t_scene *scene)
{
	int	i;

	i = 0;
	keep_scene->plane = (t_plane **)ft_calloc(sizeof(t_plane *),
			scene->n_plane + 1);
	if (!(keep_scene->plane))
	{
		err_msg("Malloc error");
		free_scene(keep_scene);
		free_scene(scene);
		exit(1);
	}
	while (i < scene->n_plane)
	{
		keep_scene->plane[i] = (t_plane *)ft_calloc(sizeof(t_plane), 2);
		if (!(keep_scene->plane[i]))
		{
			err_msg("Malloc error");
			free_scene(keep_scene);
			free_scene(scene);
			exit(1);
		}
		i++;
	}
	put_value_keep_scene_pl(keep_scene, scene);
}
