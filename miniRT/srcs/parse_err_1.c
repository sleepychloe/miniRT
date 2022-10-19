/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_err_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 02:18:37 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/19 06:51:55 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	err_check_ambient(t_scene *scene)
{
	if (scene->ambient->err)
	{
		if (scene->ambient->err == 1)
			err_msg("Map error: ambient: identifier error");
		else if (scene->ambient->err == 2)
			err_msg("Map error: ambient: line token error");
		else if (scene->ambient->err == 3)
			err_msg("Map error: ambient: rgb token error");
		else if (scene->ambient->err == 4)
			err_msg("Map error: ambient: lightning value error");
		else if (scene->ambient->err == 5)
			err_msg("Map error: ambient: rgb value error");
		return (1);
	}
	return (0);
}

int	err_check_camera(t_scene *scene)
{
	if (scene->camera->err)
	{
		if (scene->camera->err == 1)
			err_msg("Map error: camera: identifier error");
		else if (scene->camera->err == 2)
			err_msg("Map error: camera: line token error");
		else if (scene->camera->err == 3)
			err_msg("Map error: camera: xyz position token error");
		else if (scene->camera->err == 4)
			err_msg("Map error: camera: xyz normalized vector token error");
		else if (scene->camera->err == 5)
			err_msg("Map error: camera: xyz position value error");
		else if (scene->camera->err == 6)
			err_msg("Map error: camera: xyz normalized vector value error");
		else if (scene->camera->err == 7)
			err_msg("Map error: camera: fov value error");
		return (1);
	}
	return (0);
}

int	err_check_light(t_scene *scene)
{
	if (scene->light->err)
	{
		if (scene->light->err == 1)
			err_msg("Map error: light: identifier error");
		else if (scene->light->err == 2)
			err_msg("Map error: light: line token error");
		else if (scene->light->err == 3)
			err_msg("Map error: light: xyz position token error");
		else if (scene->light->err == 4)
			err_msg("Map error: light: rbg token error");
		else if (scene->light->err == 5)
			err_msg("Map error: light: xyz position value error");
		else if (scene->light->err == 6)
			err_msg("Map error: light: brightness value error");
		else if (scene->light->err == 7)
			err_msg("Map error: light: rgb value error");
		return (1);
	}
	return (0);
}

int	check_parse_error(t_scene *scene)
{
	if (err_check_ambient(scene))
		return (1);
	if (err_check_camera(scene))
		return (1);
	if (err_check_light(scene))
		return (1);
	return (0);
}
