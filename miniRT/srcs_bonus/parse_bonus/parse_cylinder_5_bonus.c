/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder_5_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 05:05:29 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/16 05:21:22 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

int	parse_cy_img_path(t_scene *scene, int i, char ***s)
{
	int	fd_img;

	if (ft_strncmp(s[0][5], "I", 1) == 0 || ft_strncmp(s[0][5], "D", 1) == 0)
	{
		fd_img = open(s[0][6], O_RDONLY);
		if (!fd_img || fd_img < 0)
		{
			scene->cylinder[i]->err = ERR_IMAGE_PATH;
			ft_free_3d(s);
			return (1);
		}
		close(fd_img);
		if (check_texture_img_extention(s[0][6]))
		{
			scene->cylinder[i]->err = ERR_IMAGE_PATH;
			ft_free_3d(s);
			return (1);
		}
		scene->cylinder[i]->img_path
			= realloc_img_texture_path(scene->cylinder[i]->img_path, s[0][6]);
	}
	else
		scene->cylinder[i]->img_path
			= realloc_img_texture_path(scene->cylinder[i]->img_path, "none");
	return (0);
}

int	parse_cy_texture_path_norminette(t_scene *scene, int i, char ***s)
{
	if (ft_strncmp(s[0][5], "T", 1) == 0 || ft_strncmp(s[0][5], "D", 1) == 0)
	{
		if (check_texture_img_extention(s[0][7]))
		{
			scene->cylinder[i]->err = ERR_TEXTURE_PATH;
			ft_free_3d(s);
			return (1);
		}
	}
	return (0);
}

int	parse_cy_texture_path(t_scene *scene, int i, char ***s)
{
	int	fd_texture;

	if (ft_strncmp(s[0][5], "T", 1) == 0 || ft_strncmp(s[0][5], "D", 1) == 0)
	{
		fd_texture = open(s[0][7], O_RDONLY);
		if (!fd_texture || fd_texture < 0)
		{
			scene->cylinder[i]->err = ERR_TEXTURE_PATH;
			ft_free_3d(s);
			return (1);
		}
		close(fd_texture);
		if (parse_cy_texture_path_norminette(scene, i, s))
			return (1);
		scene->cylinder[i]->texture_path
			= realloc_img_texture_path(scene->cylinder[i]->texture_path,
				s[0][7]);
	}
	else
		scene->cylinder[i]->texture_path
			= realloc_img_texture_path(scene->cylinder[i]->texture_path,
				"none");
	return (0);
}
