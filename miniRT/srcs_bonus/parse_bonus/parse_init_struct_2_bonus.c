/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init_struct_2_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0002/01/18 19:05:39 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/16 02:17:08 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	init_struct_scene_sp(t_scene *scene, int i)
{
	if (i == 0)
		scene->sphere = (t_sphere **)ft_calloc(sizeof(t_sphere *), 2);
	if (i > 0)
		scene->sphere = (t_sphere **)ft_realloc(scene->sphere,
				sizeof(t_sphere *) * (i + 1), sizeof(t_sphere *) * (i + 2));
	if (!(scene->sphere))
	{
		err_msg("Malloc error");
		free_scene(scene);
		exit(1);
	}
	scene->sphere[i] = (t_sphere *)ft_calloc(sizeof(t_sphere), 2);
	if (!(scene->sphere[i]))
	{
		err_msg("Malloc error");
		free_scene(scene);
		exit(1);
	}
}

void	init_struct_scene_pl(t_scene *scene, int i)
{
	if (i == 0)
		scene->plane = (t_plane **)ft_calloc(sizeof(t_plane *), 2);
	if (i > 0)
		scene->plane = (t_plane **)ft_realloc(scene->plane,
				sizeof(t_plane *) * (i + 1), sizeof(t_plane *) * (i + 2));
	if (!(scene->plane))
	{
		err_msg("Malloc error");
		free_scene(scene);
		exit(1);
	}
	scene->plane[i] = (t_plane *)ft_calloc(sizeof(t_plane), 2);
	if (!(scene->plane[i]))
	{
		err_msg("Malloc error");
		free_scene(scene);
		exit(1);
	}
}

void	init_struct_scene_cy(t_scene *scene, int i)
{
	if (i == 0)
		scene->cylinder = (t_cylinder **)ft_calloc(sizeof(t_cylinder *), 2);
	if (i > 0)
		scene->cylinder = (t_cylinder **)ft_realloc(scene->cylinder,
				sizeof(t_cylinder *) * (i + 1), sizeof(t_cylinder *) * (i + 2));
	if (!(scene->cylinder))
	{
		err_msg("Malloc error");
		free_scene(scene);
		exit(1);
	}
	scene->cylinder[i] = (t_cylinder *)ft_calloc(sizeof(t_cylinder), 2);
	if (!(scene->cylinder[i]))
	{
		err_msg("Malloc error");
		free_scene(scene);
		exit(1);
	}
}

void	init_struct_scene_co(t_scene *scene, int i)
{
	if (i == 0)
		scene->cone = (t_cone **)ft_calloc(sizeof(t_cone *), 2);
	if (i > 0)
		scene->cone = (t_cone **)ft_realloc(scene->cone,
				sizeof(t_cone *) * (i + 1), sizeof(t_cone *) * (i + 2));
	if (!(scene->cone))
	{
		err_msg("Malloc error");
		free_scene(scene);
		exit(1);
	}
	scene->cone[i] = (t_cone *)ft_calloc(sizeof(t_cone), 2);
	if (!(scene->cone[i]))
	{
		err_msg("Malloc error");
		free_scene(scene);
		exit(1);
	}
}
