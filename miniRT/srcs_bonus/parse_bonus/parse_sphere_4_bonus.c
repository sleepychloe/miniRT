/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere_4_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 00:14:13 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/16 05:24:02 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

int	parse_sp_img_path(t_scene *scene, int i, char ***s)
{
	int	fd_img;

	if (ft_strncmp(s[0][3], "I", 1) == 0 || ft_strncmp(s[0][3], "D", 1) == 0)
	{
		fd_img = open(s[0][4], O_RDONLY);
		if (!fd_img || fd_img < 0)
		{
			scene->sphere[i]->err = ERR_IMAGE_PATH;
			ft_free_3d(s);
			return (1);
		}
		close(fd_img);
		if (check_texture_img_extention(s[0][4]))
		{
			scene->sphere[i]->err = ERR_IMAGE_PATH;
			ft_free_3d(s);
			return (1);
		}
		scene->sphere[i]->img_path
			= realloc_img_texture_path(scene->sphere[i]->img_path, s[0][4]);
	}
	else
		scene->sphere[i]->img_path
			= realloc_img_texture_path(scene->sphere[i]->img_path, "none");
	return (0);
}

int	parse_sp_texture_path(t_scene *scene, int i, char ***s)
{
	int	fd_texture;

	if (ft_strncmp(s[0][3], "T", 1) == 0 || ft_strncmp(s[0][3], "D", 1) == 0)
	{
		fd_texture = open(s[0][5], O_RDONLY);
		if (!fd_texture || fd_texture < 0)
		{
			scene->sphere[i]->err = ERR_TEXTURE_PATH;
			ft_free_3d(s);
			return (1);
		}
		close(fd_texture);
		if (check_texture_img_extention(s[0][5]))
		{
			scene->sphere[i]->err = ERR_TEXTURE_PATH;
			ft_free_3d(s);
			return (1);
		}
		scene->sphere[i]->texture_path
			= realloc_img_texture_path(scene->sphere[i]->texture_path, s[0][5]);
	}
	else
		scene->sphere[i]->texture_path
			= realloc_img_texture_path(scene->sphere[i]->texture_path, "none");
	return (0);
}
