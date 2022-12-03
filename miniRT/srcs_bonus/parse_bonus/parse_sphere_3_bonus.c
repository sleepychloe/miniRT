/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere_3_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:53:28 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/03 07:34:41 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

int	parse_sp_surface_metal_fuzz(t_scene *scene, int i, char ***s)
{
	if (ft_strlen(s[3][0]) != 1)
	{
		return (1);
	}
	if (ft_atod(s[3][1]) == ERR_ATOD)
	{
		return (1);
	}
	if (!(0.0 <= ft_atod(s[3][1]) && ft_atod(s[3][1]) <= 1.0))
	{
		return (1);
	}
	scene->sphere[i]->surface = SURFACE_M;
	scene->sphere[i]->fuzz = ft_atod(s[3][1]);
	return (0);
}

void	put_value_sp_rgb1_rgb2(t_scene *scene, int i, char ***s, char **rgb)
{
	scene->sphere[i]->rgb1.r = ft_atoi(rgb[0]);
	scene->sphere[i]->rgb1.g = ft_atoi(rgb[1]);
	scene->sphere[i]->rgb1.b = ft_atoi(rgb[2]);
	if (ft_strncmp(s[0][3], "C", 1) == 0)
	{
		scene->sphere[i]->rgb2.r = 255 - ft_atoi(rgb[0]);
		scene->sphere[i]->rgb2.g = 255 - ft_atoi(rgb[1]);
		scene->sphere[i]->rgb2.b = 255 - ft_atoi(rgb[2]);
	}
}

int	check_value_sp_rgb(t_scene *scene, int i, char ***s, char **rgb)
{
	if (ft_atoi(rgb[0]) == ERR_ATOI || ft_atoi(rgb[1]) == ERR_ATOI
		|| ft_atoi(rgb[2]) == ERR_ATOI)
	{
		scene->sphere[i]->err = ERR_RGB_VALUE;
		return (1);
	}
	if (!(0 <= ft_atoi(rgb[0]) && ft_atoi(rgb[0]) <= 255)
		|| !(0 <= ft_atoi(rgb[1]) && ft_atoi(rgb[1]) <= 255)
		|| !(0 <= ft_atoi(rgb[2]) && ft_atoi(rgb[2]) <= 255))
	{
		scene->sphere[i]->err = ERR_RGB_VALUE;
		return (1);
	}
	put_value_sp_rgb1_rgb2(scene, i, s, s[2]);
	return (0);
}

int	parse_sp_rgb_1(t_scene *scene, int i, char ***s)
{
	if (ft_strncmp(s[0][3], "L", 1) == 0 || ft_strncmp(s[0][3], "C", 1) == 0
		|| ft_strncmp(s[0][3], "M,", 2) == 0
		|| ft_strncmp(s[0][3], "T", 1) == 0)
	{
		if (!s[2])
		{
			scene->sphere[i]->err = ERR_LINE_TOKEN;
			ft_free_3d(s);
			return (1);
		}
		if ((ft_strncmp(s[0][3], "L", 1) == 0
			&& (token_count(s[2], 3) || check_comma(s[0][4])))
			|| (ft_strncmp(s[0][3], "C", 1) == 0
			&& (token_count(s[2], 3) || check_comma(s[0][4])))
			|| (ft_strncmp(s[0][3], "M,", 2) == 0
			&& (token_count(s[2], 3) || check_comma(s[0][4])))
			|| (ft_strncmp(s[0][3], "T", 1) == 0
			&& (token_count(s[2], 3) || check_comma(s[0][4]))))
		{
			scene->sphere[i]->err = ERR_RGB_TOKEN;
			ft_free_3d(s);
			return (1);
		}
	}
	return (0);
}

int	parse_sp_rgb_2(t_scene *scene, int i, char ***s)
{
	if (ft_strncmp(s[0][3], "L", 1) == 0
		|| ft_strncmp(s[0][3], "C", 1) == 0
		|| ft_strncmp(s[0][3], "M,", 2) == 0
		|| ft_strncmp(s[0][3], "T", 1) == 0)
	{
		if (check_value_sp_rgb(scene, i, s, s[2]))
		{
			scene->sphere[i]->err = ERR_RGB_VALUE;
			ft_free_3d(s);
			return (1);
		}
	}
	if (ft_strncmp(s[0][3], "G", 1) == 0)
	{
		if (!(ft_strncmp(s[0][4], "none", 4) == 0
			&& ft_strlen(s[0][4]) == 4))
		{
			scene->sphere[i]->err = ERR_RGB_VALUE;
			ft_free_3d(s);
			return (1);
		}
	}
	return (0);
}
