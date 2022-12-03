/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder_5_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 05:05:29 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/03 05:42:48 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

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
		scene->cylinder[i]->texture_path = s[0][7];
	}
	return (0);
}

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
		scene->cylinder[i]->img_path = s[0][6];
	}
	return (0);
}
