/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init_struct_keep_scene_4_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 00:10:54 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/03 06:28:21 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	put_value_keep_scene_co(t_scene *keep_scene, t_scene *scene)
{
	int	i;

	i = 0;
	while (i < scene->n_cone)
	{
		keep_scene->cone[i]->err = scene->cone[i]->err;
		keep_scene->cone[i]->xyz_pos = scene->cone[i]->xyz_pos;
		keep_scene->cone[i]->xyz_vec = scene->cone[i]->xyz_vec;
		keep_scene->cone[i]->diameter = scene->cone[i]->diameter;
		keep_scene->cone[i]->height = scene->cone[i]->height;
		keep_scene->cone[i]->surface = scene->cone[i]->surface;
		keep_scene->cone[i]->fuzz = scene->cone[i]->fuzz;
		keep_scene->cone[i]->rgb1 = scene->cone[i]->rgb1;
		keep_scene->cone[i]->rgb2 = scene->cone[i]->rgb2;
		keep_scene->cone[i]->img_path = scene->cone[i]->img_path;
		keep_scene->cone[i]->texture_path = scene->cone[i]->texture_path;
		i++;
	}
}

void	init_struct_keep_scene_co_norminette(t_scene *keep_scene,
				t_scene *scene)
{
	err_msg("Malloc error");
	free_scene(keep_scene);
	free_scene(scene);
}

void	init_struct_keep_scene_co(t_scene *keep_scene, t_scene *scene)
{
	int	i;

	i = 0;
	keep_scene->cone = (t_cone **)ft_calloc(sizeof(t_cone *),
			scene->n_cone + 1);
	if (!(keep_scene->cone))
	{
		err_msg("Malloc error");
		free_scene(keep_scene);
		free_scene(scene);
		exit(1);
	}
	while (i < scene->n_cone)
	{
		keep_scene->cone[i]
			= (t_cone *)ft_calloc(sizeof(t_cone), 2);
		if (!(keep_scene->cone[i]))
		{
			init_struct_keep_scene_co_norminette(keep_scene, scene);
			exit(1);
		}
		i++;
	}
	put_value_keep_scene_co(keep_scene, scene);
}
