/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:47:48 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/21 06:57:07 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	check_value_light_rgb(t_scene *scene, char **rgb)
{
	if (ft_atoi(rgb[0]) == ERR_ATOI || ft_atoi(rgb[1]) == ERR_ATOI
		|| ft_atoi(rgb[2]) == ERR_ATOI)
	{
		scene->light->err = ERR_RGB_VALUE;
		return (1);
	}
	if ( !(0 <= ft_atoi(rgb[0]) && ft_atoi(rgb[0]) <= 255)
		|| !(0 <= ft_atoi(rgb[1]) && ft_atoi(rgb[1]) <= 255)
		|| !(0 <= ft_atoi(rgb[2]) && ft_atoi(rgb[2]) <= 255))
	{
		scene->light->err = ERR_RGB_VALUE;
		return (1);
	}
	return (0);
}

int	parse_light_rgb(t_scene *scene, char ***s)
{
	if (!s[2])
	{
		scene->light->err = ERR_MALLOC;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[2], 3))
	{
		scene->light->err = ERR_RGB_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (check_value_light_rgb(scene, s[2]))
	{
		ft_free_3d(s);
		return (1);
	}
	scene->light->r = ft_atoi(s[2][0]);
	scene->light->g = ft_atoi(s[2][1]);
	scene->light->b = ft_atoi(s[2][2]);
	return (0);
}