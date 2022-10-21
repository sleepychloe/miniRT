/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_err_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 02:18:37 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/21 03:58:35 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	err_check_ambient(t_scene *scene)
{
	if (scene->ambient->err)
	{
		if (scene->ambient->err == ERR_MALLOC)
			err_msg("Map error: ambient: malloc error");
		else if (scene->ambient->err == ERR_IDENTIFIER)
			err_msg("Map error: ambient: identifier error");
		else if (scene->ambient->err == ERR_LINE_TOKEN)
			err_msg("Map error: ambient: line token error");
		else if (scene->ambient->err == ERR_LIGHTING_VALUE)
			err_msg("Map error: ambient: lighting value error: [0.0,1.0]");
		else if (scene->ambient->err == ERR_RGB_TOKEN)
			err_msg("Map error: ambient: rgb token error");
		else if (scene->ambient->err == ERR_RGB_VALUE)
			err_msg("Map error: ambient: rgb value error: [0,255]");
		return (1);
	}
	return (0);
}

int	err_check_camera(t_scene *scene)
{
	if (scene->camera->err)
	{
		if (scene->camera->err == ERR_MALLOC)
			err_msg("Map error: camera: malloc error");
		else if (scene->camera->err == ERR_IDENTIFIER)
			err_msg("Map error: camera: identifier error");
		else if (scene->camera->err == ERR_LINE_TOKEN)
			err_msg("Map error: camera: line token error");
		else if (scene->camera->err == ERR_XYZ_POS_TOKEN)
			err_msg("Map error: camera: xyz position token error");
		else if (scene->camera->err == ERR_XYZ_POS_VALUE)
			err_msg("Map error: camera: xyz position value error");
		else if (scene->camera->err == ERR_XYZ_VEC_TOKEN)
			err_msg("Map error: camera: xyz normalized vector token error");
		else if (scene->camera->err == ERR_XYZ_VEC_VALUE)
			err_msg("Map error: camera: xyz normalized vector value error: [-1.0,1.0]");
		else if (scene->camera->err == ERR_FOV_VALUE)
			err_msg("Map error: camera: fov value error: [0,180]");
		return (1);
	}
	return (0);
}

int	err_check_light(t_scene *scene)
{
	if (scene->light->err)
	{
		if (scene->light->err == ERR_MALLOC)
			err_msg("Map error: light: malloc error");
		else if (scene->light->err == ERR_IDENTIFIER)
			err_msg("Map error: light: identifier error");
		else if (scene->light->err == ERR_LINE_TOKEN)
			err_msg("Map error: light: line token error");
		else if (scene->light->err == ERR_XYZ_POS_TOKEN)
			err_msg("Map error: light: xyz position token error");
		else if (scene->light->err == ERR_XYZ_POS_VALUE)
			err_msg("Map error: light: xyz position value error");
		else if (scene->light->err == ERR_BRIGHTNESS_VALUE)
			err_msg("Map error: light: brightness value error: [0,0,1.0]");
		else if (scene->light->err == ERR_RGB_TOKEN)
			err_msg("Map error: light: rbg token error");
		else if (scene->light->err == ERR_RGB_VALUE)
			err_msg("Map error: light: rgb value error: [0,255]");
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
	if (err_check_sphere(scene))
		return (1);
	return (0);
}
