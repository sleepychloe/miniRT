/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane_4_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 04:21:01 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/22 01:50:54 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	put_value_pl_rgb1_rgb2(t_scene *scene, int i, char ***s, char **rgb)
{
	scene->plane[i]->rgb1.r = ft_atoi(rgb[0]);
	scene->plane[i]->rgb1.g = ft_atoi(rgb[1]);
	scene->plane[i]->rgb1.b = ft_atoi(rgb[2]);
	if (ft_strncmp(s[0][3], "C", 1) == 0)
	{
		scene->plane[i]->rgb2.r = 255 - ft_atoi(rgb[0]);
		scene->plane[i]->rgb2.g = 255 - ft_atoi(rgb[1]);
		scene->plane[i]->rgb2.b = 255 - ft_atoi(rgb[2]);
	}
}

int	check_value_pl_rgb(t_scene *scene, int i, char ***s, char **rgb)
{
	if (ft_atoi(rgb[0]) == ERR_ATOI || ft_atoi(rgb[1]) == ERR_ATOI
		|| ft_atoi(rgb[2]) == ERR_ATOI)
	{
		scene->plane[i]->err = ERR_RGB_VALUE;
		return (1);
	}
	if (!(0 <= ft_atoi(rgb[0]) && ft_atoi(rgb[0]) <= 255)
		|| !(0 <= ft_atoi(rgb[1]) && ft_atoi(rgb[1]) <= 255)
		|| !(0 <= ft_atoi(rgb[2]) && ft_atoi(rgb[2]) <= 255))
	{
		scene->plane[i]->err = ERR_RGB_VALUE;
		return (1);
	}
	put_value_pl_rgb1_rgb2(scene, i, s, s[3]);
	return (0);
}

int	parse_pl_rgb_1(t_scene *scene, int i, char ***s)
{
	if (ft_strncmp(s[0][3], "L", 1) == 0 || ft_strncmp(s[0][3], "C", 1) == 0
		|| ft_strncmp(s[0][3], "M,", 2) == 0
		|| ft_strncmp(s[0][3], "T", 1) == 0)
	{
		if (!s[3])
		{
			scene->plane[i]->err = ERR_LINE_TOKEN;
			ft_free_3d(s);
			return (1);
		}
		if ((ft_strncmp(s[0][3], "L", 1) == 0
			&& (token_count(s[3], 3) || check_comma(s[0][4])))
			|| (ft_strncmp(s[0][3], "C", 1) == 0
			&& (token_count(s[3], 3) || check_comma(s[0][4])))
			|| (ft_strncmp(s[0][3], "M,", 2) == 0
			&& (token_count(s[3], 3) || check_comma(s[0][4])))
			|| (ft_strncmp(s[0][3], "T", 1) == 0
			&& (token_count(s[3], 3) || check_comma(s[0][4]))))
		{
			scene->plane[i]->err = ERR_RGB_TOKEN;
			ft_free_3d(s);
			return (1);
		}
	}
	return (0);
}

int	parse_pl_rgb_2(t_scene *scene, int i, char ***s)
{
	if (ft_strncmp(s[0][3], "L", 1) == 0
		|| ft_strncmp(s[0][3], "C", 1) == 0
		|| ft_strncmp(s[0][3], "M,", 2) == 0
		|| ft_strncmp(s[0][3], "T", 1) == 0)
	{
		if (check_value_pl_rgb(scene, i, s, s[3]))
		{
			scene->plane[i]->err = ERR_RGB_VALUE;
			ft_free_3d(s);
			return (1);
		}
	}
	return (0);
}
