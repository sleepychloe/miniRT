/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:34:46 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/20 15:35:55 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	parse_ambient_token(t_scene *scene, char **token)
{
	if (!token)
	{
		scene->ambient->err = ERR_MALLOC;
		return (1);
	}
	if (ft_strlen(token[0]) != 1)
	{
		scene->ambient->err = ERR_IDENTIFIER;
		ft_free_all_2d(token, NULL, NULL, NULL);
		return (1);
	}
	if (token_count(token, 3))
	{
		scene->ambient->err = ERR_LINE_TOKEN;
		ft_free_all_2d(token, NULL, NULL, NULL);
		return (1);
	}
	return (0);
}

int	parse_ambient_lighting(t_scene *scene, char **token)
{
	if (ft_atod(token[1]) == ERR_ATOD)
	{
		scene->ambient->err = ERR_LIGHTING_VALUE;
		ft_free_all_2d(token, NULL, NULL, NULL);
		return (1);
	}
	if ( !(0.0 <= ft_atod(token[1]) && ft_atod(token[1]) <= 1.0))
	{
		scene->ambient->err = ERR_LIGHTING_VALUE;
		ft_free_all_2d(token, NULL, NULL, NULL);
		return (1);
	}
	scene->ambient->lighting = ft_atod(token[1]);
	return (0);
}


int	check_value_ambient_rgb(t_scene *scene, char **rgb)
{
	if (ft_atoi(rgb[0]) == ERR_ATOI || ft_atoi(rgb[1]) == ERR_ATOI
		|| ft_atoi(rgb[2]) == ERR_ATOI)
	{
		scene->ambient->err = ERR_RGB_VALUE;
		return (1);
	}
	if ( !(0 <= ft_atoi(rgb[0]) && ft_atoi(rgb[0]) <= 255)
		|| !(0 <= ft_atoi(rgb[1]) && ft_atoi(rgb[1]) <= 255)
		|| !(0 <= ft_atoi(rgb[2]) && ft_atoi(rgb[2]) <= 255))
	{
		scene->ambient->err = ERR_RGB_VALUE;
		return (1);
	}
	return (0);
}

int	parse_ambient_rgb(t_scene *scene, char **token, char **rgb)
{
	if (!rgb)
	{
		scene->ambient->err = ERR_MALLOC;
		ft_free_all_2d(token, NULL, NULL, NULL);
		return (1);
	}
	if (token_count(rgb, 3))
	{
		scene->ambient->err = ERR_RGB_TOKEN;
		ft_free_all_2d(token, NULL, NULL, rgb);
		return (1);
	}
	if (check_value_ambient_rgb(scene, rgb))
	{
		ft_free_all_2d(token, NULL, NULL, rgb);
		return (1);
	}
	scene->ambient->r = ft_atoi(rgb[0]);
	scene->ambient->g = ft_atoi(rgb[1]);
	scene->ambient->b = ft_atoi(rgb[2]);
	return (0);
}

void	parse_ambient(t_scene *scene, char **line)
{
	char	**token;
	char	**rgb;

	token = ft_split(*line, ' ');
	if (parse_ambient_token(scene, token))
		return ;
	if (parse_ambient_lighting(scene, token))
		return ;
	rgb = ft_split(token[2], ',');
	if (parse_ambient_rgb(scene, token, rgb))
		return ;
	ft_free_all_2d(token, NULL, NULL, rgb);
	scene->ambient->cnt++;
}
