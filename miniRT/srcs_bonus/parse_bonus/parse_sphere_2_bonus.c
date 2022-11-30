/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 01:08:45 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/30 21:45:05 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

int	parse_sp_diameter(t_scene *scene, int i, char ***s)
{
	if (ft_atod(s[0][2]) == ERR_ATOD)
	{
		scene->sphere[i]->err = ERR_DIAMETER_VALUE;
		ft_free_3d(s);
		return (1);
	}
	if (ft_atod(s[0][2]) <= 0)
	{
		scene->sphere[i]->err = ERR_DIAMETER_VALUE;
		ft_free_3d(s);
		return (1);
	}
	scene->sphere[i]->diameter = ft_atod(s[0][2]);
	return (0);
}

int	check_value_sp_rgb(t_scene *scene, int i, char **rgb)
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
	return (0);
}

int	parse_sp_rgb(t_scene *scene, int i, char ***s)
{
	if (!s[2])
	{
		scene->sphere[i]->err = ERR_MALLOC;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[2], 3) || check_comma(s[0][3]))
	{
		scene->sphere[i]->err = ERR_RGB_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (check_value_sp_rgb(scene, i, s[2]))
	{
		ft_free_3d(s);
		return (1);
	}
	scene->sphere[i]->rgb.r = ft_atoi(s[2][0]);
	scene->sphere[i]->rgb.g = ft_atoi(s[2][1]);
	scene->sphere[i]->rgb.b = ft_atoi(s[2][2]);
	return (0);
}
