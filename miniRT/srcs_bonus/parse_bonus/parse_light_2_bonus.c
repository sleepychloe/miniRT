/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:47:48 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/01 04:38:12 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

int	parse_l_brightness(t_scene *scene, int i, char ***s)
{
	if (ft_atod(s[0][2]) == ERR_ATOD)
	{
		scene->light[i]->err = ERR_BRIGHTNESS_VALUE;
		ft_free_3d(s);
		return (1);
	}
	if (!(0.0 <= ft_atod(s[0][2]) && ft_atod(s[0][2]) <= 1.0))
	{
		scene->light[i]->err = ERR_BRIGHTNESS_VALUE;
		ft_free_3d(s);
		return (1);
	}
	scene->light[i]->brightness = ft_atod(s[0][2]);
	return (0);
}

int	check_value_l_rgb(t_scene *scene, int i, char **rgb)
{
	if (ft_atoi(rgb[0]) == ERR_ATOI || ft_atoi(rgb[1]) == ERR_ATOI
		|| ft_atoi(rgb[2]) == ERR_ATOI)
	{
		scene->light[i]->err = ERR_RGB_VALUE;
		return (1);
	}
	if (!(0 <= ft_atoi(rgb[0]) && ft_atoi(rgb[0]) <= 255)
		|| !(0 <= ft_atoi(rgb[1]) && ft_atoi(rgb[1]) <= 255)
		|| !(0 <= ft_atoi(rgb[2]) && ft_atoi(rgb[2]) <= 255))
	{
		scene->light[i]->err = ERR_RGB_VALUE;
		return (1);
	}
	return (0);
}

int	parse_l_rgb(t_scene *scene, int i, char ***s)
{
	if (!s[2])
	{
		scene->light[i]->err = ERR_MALLOC;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[2], 3) || check_comma(s[0][3]))
	{
		scene->light[i]->err = ERR_RGB_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (check_value_l_rgb(scene, i, s[2]))
	{
		ft_free_3d(s);
		return (1);
	}
	scene->light[i]->rgb.r = ft_atoi(s[2][0]);
	scene->light[i]->rgb.g = ft_atoi(s[2][1]);
	scene->light[i]->rgb.b = ft_atoi(s[2][2]);
	return (0);
}
