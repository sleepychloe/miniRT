/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone_3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:56:41 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/03 06:04:13 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

int	parse_co_diameter(t_scene *scene, int i, char ***s)
{
	if (ft_atod(s[0][3]) == ERR_ATOD)
	{
		scene->cone[i]->err = ERR_DIAMETER_VALUE;
		ft_free_3d(s);
		return (1);
	}
	if (ft_atod(s[0][3]) <= 0)
	{
		scene->cone[i]->err = ERR_DIAMETER_VALUE;
		ft_free_3d(s);
		return (1);
	}
	scene->cone[i]->diameter = ft_atod(s[0][3]);
	return (0);
}

int	parse_co_height(t_scene *scene, int i, char ***s)
{
	if (ft_atod(s[0][4]) == ERR_ATOD)
	{
		scene->cone[i]->err = ERR_HEIGHT_VALUE;
		ft_free_3d(s);
		return (1);
	}
	if (ft_atod(s[0][4]) <= 0)
	{
		scene->cone[i]->err = ERR_HEIGHT_VALUE;
		ft_free_3d(s);
		return (1);
	}
	scene->cone[i]->height = ft_atod(s[0][4]);
	return (0);
}

int	parse_co_surface_metal_fuzz(t_scene *scene, int i, char ***s)
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
	scene->cone[i]->surface = SURFACE_M;
	scene->cone[i]->fuzz = ft_atod(s[4][1]);
	return (0);
}

int	parse_co_surface_1(t_scene *scene, int i, char ***s)
{
	if (!((ft_strncmp(s[0][5], "L", 1) == 0 && ft_strlen(s[0][5]) == 1)
		|| (ft_strncmp(s[0][5], "C", 1) == 0 && ft_strlen(s[0][5]) == 1)
		|| (ft_strncmp(s[0][5], "T", 1) == 0 && ft_strlen(s[0][5]) == 1)
		|| (ft_strncmp(s[0][5], "I", 1) == 0 && ft_strlen(s[0][5]) == 1)
		|| (ft_strncmp(s[0][5], "D", 1) == 0 && ft_strlen(s[0][5]) == 1)
		|| (ft_strncmp(s[0][5], "M,", 2) == 0)
		|| (ft_strncmp(s[0][5], "G", 2) == 0 && ft_strlen(s[0][5]) == 1)))
	{
		scene->cone[i]->err = ERR_SURFACE_FLAG;
		ft_free_3d(s);
		return (1);
	}
	if (ft_strncmp(s[0][5], "L", 1) == 0)
	{
		scene->cone[i]->surface = SRUFACE_L;
	}
	else if (ft_strncmp(s[0][5], "C", 1) == 0)
		scene->cone[i]->surface = SURFACE_C;
	else if (ft_strncmp(s[0][5], "T", 1) == 0)
		scene->cone[i]->surface = SURFACE_T;
	else if (ft_strncmp(s[0][5], "I", 1) == 0)
		scene->cone[i]->surface = SURFACE_I;
	else if (ft_strncmp(s[0][5], "D", 1) == 0)
		scene->cone[i]->surface = SURFACE_D;
	return (0);
}

int	parse_co_surface_2(t_scene *scene, int i, char ***s)
{
	if (ft_strncmp(s[0][5], "M,", 2) == 0)
	{
		if (!s[4] || !s[4][0] || !s[4][1])
		{
			scene->cone[i]->err = ERR_LINE_TOKEN;
			ft_free_3d(s);
			return (1);
		}
		if (token_count(s[4], 2) || check_comma_surface_flag(s[0][5]))
		{
			scene->cone[i]->err = ERR_SURFACE_FLAG;
			ft_free_3d(s);
			return (1);
		}
		if (parse_co_surface_metal_fuzz(scene, i, s))
		{
			scene->cone[i]->err = ERR_FUZZ_VALUE;
			ft_free_3d(s);
			return (1);
		}
	}
	else if (ft_strncmp(s[0][5], "G", 2) == 0)
		scene->cone[i]->surface = SURFACE_G;
	return (0);
}
