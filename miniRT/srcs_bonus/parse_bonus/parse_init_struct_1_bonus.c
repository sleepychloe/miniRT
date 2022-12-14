/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init_struct_1_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:51:02 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/02 00:32:51 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	init_struct_scene_a(t_scene *scene)
{
	scene->ambient = (t_ambient *)ft_calloc(sizeof(t_ambient), 2);
	if (!(scene->ambient))
	{
		err_msg("Malloc error");
		free(scene);
		exit(1);
	}
}

void	init_struct_scene_c(t_scene *scene)
{
	scene->camera = (t_camera *)ft_calloc(sizeof(t_camera), 2);
	if (!(scene->camera))
	{
		err_msg("Malloc error");
		free(scene->ambient);
		free(scene);
		exit(1);
	}
}

void	init_struct_scene_l(t_scene *scene, int i)
{
	if (i == 0)
		scene->light = (t_light **)ft_calloc(sizeof(t_light *), 2);
	if (i > 0)
		scene->light = (t_light **)ft_realloc(scene->light,
				sizeof(t_light *) * (i + 1), sizeof(t_light *) * (i + 2));
	if (!(scene->light))
	{
		err_msg("Malloc error");
		free_scene(scene);
		exit(1);
	}
	scene->light[i] = (t_light *)ft_calloc(sizeof(t_light), 2);
	if (!(scene->light[i]))
	{
		err_msg("Malloc error");
		free_scene(scene);
		exit(1);
	}
}

void	init_struct_scene(t_scene *scene)
{
	init_struct_scene_a(scene);
	init_struct_scene_c(scene);
	init_struct_scene_l(scene, 0);
	init_struct_scene_sp(scene, 0);
	init_struct_scene_pl(scene, 0);
	init_struct_scene_cy(scene, 0);
	init_struct_scene_co(scene, 0);
}
