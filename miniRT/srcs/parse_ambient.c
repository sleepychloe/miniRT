/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:34:46 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/19 22:33:21 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	parse_ambient_token(t_scene *scene, char **token)
{
	if (!token)
		return (1);
	if (ft_strlen(token[0]) != 1)
		scene->ambient->err = 1;
	if (token_count(token, 3))
	{
		scene->ambient->err = 2;
		ft_free_2d(token);
		return (1);
	}
	return (0);
}

int	parse_ambient_lighting(t_scene *scene, char **token)
{
	if (ft_atod(token[1]) == -9999
		|| !(0.0 <= ft_atod(token[1]) && ft_atod(token[1]) <= 1.0))
	{
		scene->ambient->err = 3;
		ft_free_2d(token);
		return (1);
	}
	scene->ambient->lighting = ft_atod(token[1]);
	return (0);
}


int	put_ambient_rgb(t_scene *scene, char **rgb)
{
	if (ft_atoi(rgb[0]) == -9999 || ft_atoi(rgb[1]) == -9999
		|| ft_atoi(rgb[2]) == -9999)
	{
		scene->ambient->err = 5;
		return (1);
	}
	if ( !(0 <= ft_atoi(rgb[0]) && ft_atoi(rgb[0]) <= 255)
		|| !(0 <= ft_atoi(rgb[1]) && ft_atoi(rgb[1]) <= 255)
		|| !(0 <= ft_atoi(rgb[2]) && ft_atoi(rgb[2]) <= 255))
	{
		scene->ambient->err = 5;
		return (1);
	}
	scene->ambient->r = ft_atoi(rgb[0]);
	scene->ambient->g = ft_atoi(rgb[1]);
	scene->ambient->b = ft_atoi(rgb[2]);
	return (0);
}

int	parse_ambient_rgb(t_scene *scene, char **token, char **rgb)
{
	if (!rgb)
	{
		ft_free_2d(token);
		return (1);
	}
	if (token_count(rgb, 3))
	{
		scene->ambient->err = 4;
		ft_free_2d(token);
		ft_free_2d(rgb);
		return (1);
	}
	if (put_ambient_rgb(scene, rgb))
	{
		ft_free_2d(token);
		ft_free_2d(rgb);
		return (1);
	}
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
	ft_free_2d(token);
	ft_free_2d(rgb);
	scene->ambient->cnt++;
}
