/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_err_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 01:09:02 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/23 00:41:38 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	err_check_sp(t_scene *scene, int i)
{
	if (scene->sphere[i]->err)
	{
		if (scene->sphere[i]->err == ERR_MALLOC)
			map_err_i(i + 1, "sp", "malloc error");
		else if (scene->sphere[i]->err == ERR_IDENTIFIER)
			map_err_i(i + 1, "sp", "identifier error");
		else if (scene->sphere[i]->err == ERR_LINE_TOKEN)
			map_err_i(i + 1, "sp", "line token error");
		else if (scene->sphere[i]->err == ERR_XYZ_POS_TOKEN)
			map_err_i(i + 1, "sp", "xyz position token error");
		else if (scene->sphere[i]->err == ERR_XYZ_POS_VALUE)
			map_err_i(i + 1, "sp", "xyz position value error");
		else if (scene->sphere[i]->err == ERR_DIAMETER_VALUE)
			map_err_i(i + 1, "sp", "diameter value error");
		else if (scene->sphere[i]->err == ERR_RGB_TOKEN)
			map_err_i(i + 1, "sp", "rbg token error");
		else if (scene->sphere[i]->err == ERR_RGB_VALUE)
			map_err_i(i + 1, "sp", "rgb value error");
	}
}

void	err_check_pl(t_scene *scene, int i)
{
	if (scene->plane[i]->err)
	{
		if (scene->plane[i]->err == ERR_MALLOC)
			map_err_i(i + 1, "pl", "malloc error");
		else if (scene->plane[i]->err == ERR_IDENTIFIER)
			map_err_i(i + 1, "pl", "identifier error");
		else if (scene->plane[i]->err == ERR_LINE_TOKEN)
			map_err_i(i + 1, "pl", "line token error");
		else if (scene->plane[i]->err == ERR_XYZ_POS_TOKEN)
			map_err_i(i + 1, "pl", "xyz position token error");
		else if (scene->plane[i]->err == ERR_XYZ_POS_VALUE)
			map_err_i(i + 1, "pl", "xyz position value error");
		else if (scene->plane[i]->err == ERR_XYZ_VEC_TOKEN)
			map_err_i(i + 1, "pl", "xyz normalized vector token error");
		else if (scene->plane[i]->err == ERR_XYZ_VEC_VALUE)
			map_err_i(i + 1, "pl", "xyz normalized vector value error");
		else if (scene->plane[i]->err == ERR_RGB_TOKEN)
			map_err_i(i + 1, "pl", "rbg token error");
		else if (scene->plane[i]->err == ERR_RGB_VALUE)
			map_err_i(i + 1, "pl", "rgb value error");
	}
}

void	err_check_cy(t_scene *scene, int i)
{
	if (scene->cylinder[i]->err)
	{
		if (scene->cylinder[i]->err == ERR_MALLOC)
			map_err_i(i + 1, "cy", "malloc error");
		else if (scene->cylinder[i]->err == ERR_IDENTIFIER)
			map_err_i(i + 1, "cy", "identifier error");
		else if (scene->cylinder[i]->err == ERR_LINE_TOKEN)
			map_err_i(i + 1, "cy", "line token error");
		else if (scene->cylinder[i]->err == ERR_XYZ_POS_TOKEN)
			map_err_i(i + 1, "cy", "xyz position token error");
		else if (scene->cylinder[i]->err == ERR_XYZ_POS_VALUE)
			map_err_i(i + 1, "cy", "xyz position value error");
		else if (scene->cylinder[i]->err == ERR_XYZ_VEC_TOKEN)
			map_err_i(i + 1, "cy", "xyz normalized vector token error");
		else if (scene->cylinder[i]->err == ERR_XYZ_VEC_VALUE)
			map_err_i(i + 1, "cy", "xyz normalized vector value error");
		else if (scene->cylinder[i]->err == ERR_DIAMETER_VALUE)
			map_err_i(i + 1, "cy", "diameter value error");
		else if (scene->cylinder[i]->err == ERR_HEIGHT_VALUE)
			map_err_i(i + 1, "cy", "height value error");
		else if (scene->cylinder[i]->err == ERR_RGB_TOKEN)
			map_err_i(i + 1, "cy", "rbg token error");
		else if (scene->cylinder[i]->err == ERR_RGB_VALUE)
			map_err_i(i + 1, "cy", "rgb value error");
	}
}
