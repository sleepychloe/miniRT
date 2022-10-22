/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_err_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 02:18:37 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/23 01:13:55 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	err_check_a(t_scene *scene)
{
	if (scene->ambient->err)
	{
		if (scene->ambient->err == ERR_MALLOC)
			err_msg("Map error: A: malloc error");
		else if (scene->ambient->err == ERR_IDENTIFIER)
			err_msg("Map error: A: identifier error");
		else if (scene->ambient->err == ERR_LINE_TOKEN)
			err_msg("Map error: A: line token error");
		else if (scene->ambient->err == ERR_LIGHTING_VALUE)
			err_msg("Map error: A: lighting value error");
		else if (scene->ambient->err == ERR_RGB_TOKEN)
			err_msg("Map error: A: rgb token error");
		else if (scene->ambient->err == ERR_RGB_VALUE)
			err_msg("Map error: A: rgb value error");
	}
}

void	err_check_c(t_scene *scene)
{
	if (scene->camera->err)
	{
		if (scene->camera->err == ERR_MALLOC)
			err_msg("Map error: C: malloc error");
		else if (scene->camera->err == ERR_IDENTIFIER)
			err_msg("Map error: C: identifier error");
		else if (scene->camera->err == ERR_LINE_TOKEN)
			err_msg("Map error: C: line token error");
		else if (scene->camera->err == ERR_XYZ_POS_TOKEN)
			err_msg("Map error: C: xyz position token error");
		else if (scene->camera->err == ERR_XYZ_POS_VALUE)
			err_msg("Map error: C: xyz position value error");
		else if (scene->camera->err == ERR_XYZ_VEC_TOKEN)
			err_msg("Map error: C: xyz normalized vector token error");
		else if (scene->camera->err == ERR_XYZ_VEC_VALUE)
			err_msg("Map error: C: xyz normalized vector value error");
		else if (scene->camera->err == ERR_FOV_VALUE)
			err_msg("Map error: C: fov value error");
	}
}

void	err_check_l(t_scene *scene)
{
	if (scene->light->err)
	{
		if (scene->light->err == ERR_MALLOC)
			err_msg("Map error: L: malloc error");
		else if (scene->light->err == ERR_IDENTIFIER)
			err_msg("Map error: L: identifier error");
		else if (scene->light->err == ERR_LINE_TOKEN)
			err_msg("Map error: L: line token error");
		else if (scene->light->err == ERR_XYZ_POS_TOKEN)
			err_msg("Map error: L: xyz position token error");
		else if (scene->light->err == ERR_XYZ_POS_VALUE)
			err_msg("Map error: L: xyz position value error");
		else if (scene->light->err == ERR_BRIGHTNESS_VALUE)
			err_msg("Map error: L: brightness value error");
		else if (scene->light->err == ERR_RGB_TOKEN)
			err_msg("Map error: L: rbg token error");
		else if (scene->light->err == ERR_RGB_VALUE)
			err_msg("Map error: L: rgb value error");
	}
}

int	check_parse_error(t_scene *scene)
{
	if (!(scene->ambient->check) || !(scene->camera->check)
		|| !(scene->light->check) || !(scene->n_sphere)
		|| !(scene->n_plane) || !(scene->n_cylinder))
	{
		if (!(scene->ambient->check))
			err_msg("Map error: A should exist at least once");
		if (!(scene->camera->check))
			err_msg("Map error: C should exist at least once");
		if (!(scene->light->check))
			err_msg("Map error: L should exist at least once");
		if (!(scene->n_sphere))
			err_msg("Map error: sp should exist at least once");
		if (!(scene->n_plane))
			err_msg("Map error: pl should exist at least once");
		if (!(scene->n_cylinder))
			err_msg("Map error: cy should exist at least once");
		return (1);
	}
	return (0);
}
