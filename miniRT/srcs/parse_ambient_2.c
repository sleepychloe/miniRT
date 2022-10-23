/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 02:43:47 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/23 05:11:38 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	parse_a_token(t_scene *scene, char ***s)
{
	if (!s[0])
	{
		scene->ambient->err = ERR_MALLOC;
		return (1);
	}
	if (ft_strlen(s[0][0]) != 1)
	{
		scene->ambient->err = ERR_IDENTIFIER;
		ft_free_3d(s);
		return (1);
	}
	if (!s[0][1] || token_count(s[0], 3))
	{
		scene->ambient->err = ERR_LINE_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	return (0);
}

int	parse_a_lighting(t_scene *scene, char ***s)
{
	if (ft_atod(s[0][1]) == ERR_ATOD)
	{
		scene->ambient->err = ERR_LIGHTING_VALUE;
		ft_free_3d(s);
		return (1);
	}
	if (!(0.0 <= ft_atod(s[0][1]) && ft_atod(s[0][1]) <= 1.0))
	{
		scene->ambient->err = ERR_LIGHTING_VALUE;
		ft_free_3d(s);
		return (1);
	}
	scene->ambient->lighting = ft_atod(s[0][1]);
	return (0);
}

int	check_value_a_rgb(t_scene *scene, char **rgb)
{
	if (ft_atoi(rgb[0]) == ERR_ATOI || ft_atoi(rgb[1]) == ERR_ATOI
		|| ft_atoi(rgb[2]) == ERR_ATOI)
	{
		scene->ambient->err = ERR_RGB_VALUE;
		return (1);
	}
	if (!(0 <= ft_atoi(rgb[0]) && ft_atoi(rgb[0]) <= 255)
		|| !(0 <= ft_atoi(rgb[1]) && ft_atoi(rgb[1]) <= 255)
		|| !(0 <= ft_atoi(rgb[2]) && ft_atoi(rgb[2]) <= 255))
	{
		scene->ambient->err = ERR_RGB_VALUE;
		return (1);
	}
	return (0);
}

int	parse_a_rgb(t_scene *scene, char ***s)
{
	if (!s[1])
	{
		scene->ambient->err = ERR_MALLOC;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[1], 3))
	{
		scene->ambient->err = ERR_RGB_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (check_value_a_rgb(scene, s[1]))
	{
		ft_free_3d(s);
		return (1);
	}
	scene->ambient->r = ft_atoi(s[1][0]);
	scene->ambient->g = ft_atoi(s[1][1]);
	scene->ambient->b = ft_atoi(s[1][2]);
	return (0);
}
