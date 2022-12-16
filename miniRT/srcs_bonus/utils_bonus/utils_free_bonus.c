/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:58:07 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/16 05:04:43 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	ft_free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_free_3d(char ***str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (*str[i])
			ft_free_2d(str[i++]);
	}
	free(str);
}

void	free_scene_norminette(t_scene *scene)
{
	int	i;

	i = 0;
	while (scene->cylinder[i])
	{
		free(scene->cylinder[i]->img_path);
		free(scene->cylinder[i]->texture_path);
		free(scene->cylinder[i++]);
	}
	free(scene->cylinder);
	i = 0;
	while (scene->cone[i])
	{
		free(scene->cone[i]->img_path);
		free(scene->cone[i]->texture_path);
		free(scene->cone[i++]);
	}
	free(scene->cone);
	free(scene);
}

void	free_scene(t_scene *scene)
{
	int	i;

	free(scene->ambient);
	free(scene->camera);
	i = 0;
	while (scene->light[i])
		free(scene->light[i++]);
	free(scene->light);
	i = 0;
	while (scene->sphere[i])
	{
		free(scene->sphere[i]->img_path);
		free(scene->sphere[i]->texture_path);
		free(scene->sphere[i++]);
	}
	free(scene->sphere);
	i = 0;
	while (scene->plane[i])
	{
		free(scene->plane[i]->img_path);
		free(scene->plane[i]->texture_path);
		free(scene->plane[i++]);
	}
	free(scene->plane);
	free_scene_norminette(scene);
}

void	free_obj(t_obj **obj)
{
	int	i;

	i = 0;
	while (obj[i])
	{
		free(obj[i]->img_path);
		free(obj[i]->texture_path);
		free(obj[i]->img_addr);
		free(obj[i]->texture_addr);
		free(obj[i++]);
	}
	free(obj);
}
