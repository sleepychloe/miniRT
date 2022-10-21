/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:46:18 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/20 23:21:03 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	parse_light_token(t_scene *scene, char **token)
{
	if (!token)
	{
		scene->light->err = ERR_MALLOC;
		return (1);
	}
	if (ft_strlen(token[0]) != 1)
	{
		scene->light->err = ERR_IDENTIFIER;
		ft_free_all_2d(token, NULL, NULL, NULL);
		return (1);
	}
	if (token_count(token, 4))
	{
		scene->light->err = ERR_LINE_TOKEN;
		ft_free_all_2d(token, NULL, NULL, NULL);
		return (1);
	}
	return (0);
}

int	check_value_light_xyz_pos(t_scene *scene, char **xyz_pos)
{
	if (ft_atod(xyz_pos[0]) == ERR_ATOD || ft_atod(xyz_pos[1]) == ERR_ATOD
		|| ft_atod(xyz_pos[2]) == ERR_ATOD)
	{
		scene->light->err = ERR_XYZ_POS_VALUE;
		return (1);
	}
	return (0);
}

int	parse_light_xyz_pos(t_scene *scene, char **token, char **xyz_pos)
{
	if (!xyz_pos)
	{
		scene->light->err = ERR_MALLOC;
		ft_free_all_2d(token, NULL, NULL, NULL);
		return (1);
	}
	if (token_count(xyz_pos, 3))
	{
		scene->light->err = ERR_XYZ_POS_TOKEN;
		ft_free_all_2d(token, xyz_pos, NULL, NULL);
		return (1);
	}
	if (check_value_light_xyz_pos(scene, xyz_pos))
	{
		ft_free_all_2d(token, xyz_pos, NULL, NULL);
		return (1);
	}
	scene->light->x_pos = ft_atod(xyz_pos[0]);
	scene->light->y_pos = ft_atod(xyz_pos[1]);
	scene->light->z_pos = ft_atod(xyz_pos[2]);
	return (0);
}

int	parse_light_brightness(t_scene *scene, char **token, char **xyz_pos)
{
	if (ft_atod(token[2]) == ERR_ATOD)
	{
		scene->light->err = ERR_BRIGHTNESS_VALUE;
		ft_free_all_2d(token, xyz_pos, NULL, NULL);
		return (1);
	}
	if ( !(0.0 <= ft_atod(token[2]) && ft_atod(token[2]) <= 1.0))
	{
		scene->light->err = ERR_BRIGHTNESS_VALUE;
		ft_free_all_2d(token, xyz_pos, NULL, NULL);
		return (1);
	}
	scene->light->brightness = ft_atod(token[2]);
	return (0);
}

void	parse_light(t_scene *scene, char **line)
{
	char	**token;
	char	**xyz_pos;
	char	**rgb;

	token = ft_split(*line, ' ');
	if (parse_light_token(scene, token))
		return ;
	xyz_pos = ft_split(token[1], ',');
	if (parse_light_xyz_pos(scene, token, xyz_pos))
		return ;
	if (parse_light_brightness(scene, token, xyz_pos))
		return ;
	rgb = ft_split(token[3], ',');
	if (parse_light_rgb(scene, token, xyz_pos, rgb))
		return ;
	ft_free_all_2d(token, xyz_pos, NULL, rgb);
	scene->camera->cnt++;
}
