/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:51:02 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/23 00:44:51 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	init_struct_a(t_scene *scene)
{
	scene->ambient = (t_ambient *)ft_calloc(sizeof(t_ambient), 2);
	if (!(scene->ambient))
	{
		err_msg("Malloc error\n");
		free(scene);
		exit(1);
	}
}

void	init_struct_c(t_scene *scene)
{
	scene->camera = (t_camera *)ft_calloc(sizeof(t_camera), 2);
	if (!(scene->camera))
	{
		err_msg("Malloc error\n");
		free(scene->ambient);
		free(scene);
		exit(1);
	}
}

void	init_struct_l(t_scene *scene)
{
	scene->light = (t_light *)ft_calloc(sizeof(t_light), 2);
	if (!(scene->light))
	{
		err_msg("Malloc error\n");
		free(scene->ambient);
		free(scene->camera);
		free(scene);
		exit(1);
	}
}

void	init_struct(t_scene *scene)
{
	init_struct_a(scene);
	init_struct_c(scene);
	init_struct_l(scene);
	init_struct_sp(scene, 0);
	init_struct_pl(scene, 0);
	init_struct_cy(scene, 0);
}
