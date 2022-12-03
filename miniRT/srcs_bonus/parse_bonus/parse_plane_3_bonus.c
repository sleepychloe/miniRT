/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane_3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 04:20:37 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/03 04:48:23 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

int	parse_pl_surface_metal_fuzz(t_scene *scene, int i, char ***s)
{
	if (ft_strlen(s[4][0]) != 1)
	{
		return (1);
	}
	if (ft_atod(s[4][1]) == ERR_ATOD)
	{
		return (1);
	}
	if (!(0.0 <= ft_atod(s[4][1]) && ft_atod(s[4][1]) <= 1.0))
	{
		return (1);
	}
	scene->plane[i]->surface = SURFACE_M;
	scene->plane[i]->fuzz = ft_atod(s[4][1]);
	return (0);
}

int	parse_pl_surface_1(t_scene *scene, int i, char ***s)
{
	if (!((ft_strncmp(s[0][3], "L", 1) == 0 && ft_strlen(s[0][3]) == 1)
		|| (ft_strncmp(s[0][3], "C", 1) == 0 && ft_strlen(s[0][3]) == 1)
		|| (ft_strncmp(s[0][3], "T", 1) == 0 && ft_strlen(s[0][3]) == 1)
		|| (ft_strncmp(s[0][3], "I", 1) == 0 && ft_strlen(s[0][3]) == 1)
		|| (ft_strncmp(s[0][3], "D", 1) == 0 && ft_strlen(s[0][3]) == 1)
		|| (ft_strncmp(s[0][3], "M,", 2) == 0)
		|| (ft_strncmp(s[0][3], "G", 2) == 0 && ft_strlen(s[0][3]) == 1)))
	{
		scene->plane[i]->err = ERR_SURFACE_FLAG;
		ft_free_3d(s);
		return (1);
	}
	if (ft_strncmp(s[0][3], "L", 1) == 0)
	{
		scene->plane[i]->surface = SRUFACE_L;
	}
	else if (ft_strncmp(s[0][3], "C", 1) == 0)
		scene->plane[i]->surface = SURFACE_C;
	else if (ft_strncmp(s[0][3], "T", 1) == 0)
		scene->plane[i]->surface = SURFACE_T;
	else if (ft_strncmp(s[0][3], "I", 1) == 0)
		scene->plane[i]->surface = SURFACE_I;
	else if (ft_strncmp(s[0][3], "D", 1) == 0)
		scene->plane[i]->surface = SURFACE_D;
	return (0);
}

int	parse_pl_surface_2(t_scene *scene, int i, char ***s)
{
	if (ft_strncmp(s[0][3], "M,", 2) == 0)
	{
		if (!s[4] || !s[4][0] || !s[4][1])
		{
			scene->plane[i]->err = ERR_LINE_TOKEN;
			ft_free_3d(s);
			return (1);
		}
		if (token_count(s[4], 2) || check_comma_surface_flag(s[0][3]))
		{
			scene->plane[i]->err = ERR_SURFACE_FLAG;
			ft_free_3d(s);
			return (1);
		}
		if (parse_pl_surface_metal_fuzz(scene, i, s))
		{
			scene->plane[i]->err = ERR_FUZZ_VALUE;
			ft_free_3d(s);
			return (1);
		}
	}
	else if (ft_strncmp(s[0][3], "G", 2) == 0)
		scene->plane[i]->surface = SURFACE_G;
	return (0);
}

int	parse_pl_texture_path(t_scene *scene, int i, char ***s)
{
	int	fd_texture;

	if (ft_strncmp(s[0][3], "T", 1) == 0 || ft_strncmp(s[0][3], "D", 1) == 0)
	{
		fd_texture = open(s[0][5], O_RDONLY);
		if (!fd_texture || fd_texture < 0)
		{
			scene->plane[i]->err = ERR_TEXTURE_PATH;
			ft_free_3d(s);
			return (1);
		}
		close(fd_texture);
		scene->plane[i]->texture_path = s[0][5];
	}
	return (0);
}

int	parse_pl_img_path(t_scene *scene, int i, char ***s)
{
	int	fd_img;

	if (ft_strncmp(s[0][3], "I", 1) == 0 || ft_strncmp(s[0][3], "D", 1) == 0)
	{
		fd_img = open(s[0][4], O_RDONLY);
		if (!fd_img || fd_img < 0)
		{
			scene->plane[i]->err = ERR_IMAGE_PATH;
			ft_free_3d(s);
			return (1);
		}
		close(fd_img);
		scene->plane[i]->img_path = s[0][4];
	}
	return (0);
}
