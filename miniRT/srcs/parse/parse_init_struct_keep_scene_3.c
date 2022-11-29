/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init_struct_keep_scene_3.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:58:02 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/29 11:00:47 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	put_value_keep_scene_cy(t_scene *keep_scene, t_scene *scene)
{
	int	i;

	i = 0;
	while (i < scene->n_cylinder)
	{
		keep_scene->cylinder[i]->err = scene->cylinder[i]->err;
		keep_scene->cylinder[i]->xyz_pos = scene->cylinder[i]->xyz_pos;
		keep_scene->cylinder[i]->xyz_vec = scene->cylinder[i]->xyz_vec;
		keep_scene->cylinder[i]->diameter = scene->cylinder[i]->diameter;
		keep_scene->cylinder[i]->height = scene->cylinder[i]->height;
		keep_scene->cylinder[i]->rgb = scene->cylinder[i]->rgb;
		i++;
	}
}

void	init_struct_keep_scene_cy_norminette(t_scene *keep_scene,
				t_scene *scene)
{
	err_msg("Malloc error\n");
	free_scene(keep_scene);
	free_scene(scene);
}

void	init_struct_keep_scene_cy(t_scene *keep_scene, t_scene *scene)
{
	int	i;

	i = 0;
	keep_scene->cylinder = (t_cylinder **)ft_calloc(sizeof(t_cylinder *),
			scene->n_cylinder + 1);
	if (!(keep_scene->cylinder))
	{
		err_msg("Malloc error\n");
		free_scene(keep_scene);
		free_scene(scene);
		exit(1);
	}
	while (i < scene->n_cylinder)
	{
		keep_scene->cylinder[i]
			= (t_cylinder *)ft_calloc(sizeof(t_cylinder), 2);
		if (!(keep_scene->cylinder[i]))
		{
			init_struct_keep_scene_cy_norminette(keep_scene, scene);
			exit(1);
		}
		i++;
	}
	put_value_keep_scene_cy(keep_scene, scene);
}
