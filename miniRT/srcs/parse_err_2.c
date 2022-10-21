/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_err_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 01:09:02 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/21 07:56:46 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	err_check_sphere(t_scene *scene)
{
	int	i;

	i = 0;
	while (i < scene->n_sphere)
	{
		if (scene->sphere[i]->err)
		{
			if (scene->sphere[i]->err == ERR_MALLOC)
				err_msg("Map error: sphere[i]: malloc error");
			else if (scene->sphere[i]->err == ERR_IDENTIFIER)
				err_msg("Map error: sphere[i]: identifier error");
			else if (scene->sphere[i]->err == ERR_LINE_TOKEN)
				err_msg("Map error: sphere[i]: line token error");
			else if (scene->sphere[i]->err == ERR_XYZ_POS_TOKEN)
				err_msg("Map error: sphere[i]: xyz position token error");
			else if (scene->sphere[i]->err == ERR_XYZ_POS_VALUE)
				err_msg("Map error: sphere[i]: xyz position value error");
			else if (scene->sphere[i]->err == ERR_DIAMETER_VALUE)
				err_msg("Map error: sphere[i]: diameter value error");
			else if (scene->sphere[i]->err == ERR_RGB_TOKEN)
				err_msg("Map error: sphere[i]: rbg token error");
			else if (scene->sphere[i]->err == ERR_RGB_VALUE)
				err_msg("Map error: sphere[i]: rgb value error: [0,255]");
			return (1);
		}
		else
			i++;
	}
	return (0);
}

int	err_check_plane(t_scene *scene)
{
	int	i;

	i = 0;
	while (i < scene->n_plane)
	{
		if (scene->plane[i]->err)
		{
			if (scene->plane[i]->err == ERR_MALLOC)
				err_msg("Map error: plane[i]: malloc error");
			else if (scene->plane[i]->err == ERR_IDENTIFIER)
				err_msg("Map error: plane[i]: identifier error");
			else if (scene->plane[i]->err == ERR_LINE_TOKEN)
				err_msg("Map error: plane[i]: line token error");
			else if (scene->plane[i]->err == ERR_XYZ_POS_TOKEN)
				err_msg("Map error: plane[i]: xyz position token error");
			else if (scene->plane[i]->err == ERR_XYZ_POS_VALUE)
				err_msg("Map error: plane[i]: xyz position value error");
			else if (scene->plane[i]->err == ERR_XYZ_VEC_TOKEN)
				err_msg("Map error: plane[i]: xyz normalized vector token error");
			else if (scene->plane[i]->err == ERR_XYZ_VEC_VALUE)
				err_msg("Map error: plane[i]: xyz normalized vector value error: [-1.0,1.0]");
			else if (scene->plane[i]->err == ERR_RGB_TOKEN)
				err_msg("Map error: plane[i]: rbg token error");
			else if (scene->plane[i]->err == ERR_RGB_VALUE)
				err_msg("Map error: plane[i]: rgb value error: [0,255]");
			return (1);
		}
		else
			i++;
	}
	return (0);
}

int	err_check_cylinder(t_scene *scene)
{
	int	i;

	i = 0;
	while (i < scene->n_cylinder)
	{
		if (scene->cylinder[i]->err)
		{
			if (scene->cylinder[i]->err == ERR_MALLOC)
				err_msg("Map error: cylinder[i]: malloc error");
			else if (scene->cylinder[i]->err == ERR_IDENTIFIER)
				err_msg("Map error: cylinder[i]: identifier error");
			else if (scene->cylinder[i]->err == ERR_LINE_TOKEN)
				err_msg("Map error: cylinder[i]: line token error");
			else if (scene->cylinder[i]->err == ERR_XYZ_POS_TOKEN)
				err_msg("Map error: cylinder[i]: xyz position token error");
			else if (scene->cylinder[i]->err == ERR_XYZ_POS_VALUE)
				err_msg("Map error: cylinder[i]: xyz position value error");
			else if (scene->cylinder[i]->err == ERR_XYZ_VEC_TOKEN)
				err_msg("Map error: cylinder[i]: xyz normalized vector token error");
			else if (scene->cylinder[i]->err == ERR_XYZ_VEC_VALUE)
				err_msg("Map error: cylinder[i]: xyz normalized vector value error: [-1.0,1.0]");
			else if (scene->cylinder[i]->err == ERR_DIAMETER_VALUE)
				err_msg("Map error: cylinder[i]: diameter value error");
			else if (scene->cylinder[i]->err == ERR_HEIGHT_VALUE)
				err_msg("Map error: cylinder[i]: height value error");
			else if (scene->cylinder[i]->err == ERR_RGB_TOKEN)
				err_msg("Map error: cylinder[i]: rbg token error");
			else if (scene->cylinder[i]->err == ERR_RGB_VALUE)
				err_msg("Map error: cylinder[i]: rgb value error: [0,255]");
			return (1);
		}
		else
			i++;
	}
	return (0);
}