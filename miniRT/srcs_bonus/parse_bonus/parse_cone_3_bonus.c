/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone_3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:56:41 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/02 00:06:55 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

int	check_value_co_rgb(t_scene *scene, int i, char **rgb)
{
	if (ft_atoi(rgb[0]) == ERR_ATOI || ft_atoi(rgb[1]) == ERR_ATOI
		|| ft_atoi(rgb[2]) == ERR_ATOI)
	{
		scene->cone[i]->err = ERR_RGB_VALUE;
		return (1);
	}
	if (!(0 <= ft_atoi(rgb[0]) && ft_atoi(rgb[0]) <= 255)
		|| !(0 <= ft_atoi(rgb[1]) && ft_atoi(rgb[1]) <= 255)
		|| !(0 <= ft_atoi(rgb[2]) && ft_atoi(rgb[2]) <= 255))
	{
		scene->cone[i]->err = ERR_RGB_VALUE;
		return (1);
	}
	return (0);
}

int	parse_co_rgb(t_scene *scene, int i, char ***s)
{
	if (!s[3])
	{
		scene->cone[i]->err = ERR_MALLOC;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[3], 3) || check_comma(s[0][5]))
	{
		scene->cone[i]->err = ERR_RGB_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (check_value_co_rgb(scene, i, s[3]))
	{
		ft_free_3d(s);
		return (1);
	}
	scene->cone[i]->rgb.r = ft_atoi(s[3][0]);
	scene->cone[i]->rgb.g = ft_atoi(s[3][1]);
	scene->cone[i]->rgb.b = ft_atoi(s[3][2]);
	return (0);
}
