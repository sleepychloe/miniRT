/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_err_3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 04:51:49 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/03 06:15:13 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	err_check_cy_1(t_scene *scene, int i)
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
	}
}

void	err_check_cy_2(t_scene *scene, int i)
{
	if (scene->cylinder[i]->err)
	{
		if (scene->cylinder[i]->err == ERR_SURFACE_FLAG)
			map_err_i(i + 1, "cy", "surface flag error");
		else if (scene->cylinder[i]->err == ERR_FUZZ_VALUE)
			map_err_i(i + 1, "cy", "fuzz value error");
		else if (scene->cylinder[i]->err == ERR_RGB_TOKEN)
			map_err_i(i + 1, "cy", "rbg token error");
		else if (scene->cylinder[i]->err == ERR_RGB_VALUE)
			map_err_i(i + 1, "cy", "rgb value error");
		else if (scene->cylinder[i]->err == ERR_TEXTURE_PATH)
			map_err_i(i + 1, "cy", "texture path error");
		else if (scene->cylinder[i]->err == ERR_IMAGE_PATH)
			map_err_i(i + 1, "cy", "image path error");
	}
}

void	err_check_co_1(t_scene *scene, int i)
{
	if (scene->cone[i]->err)
	{
		if (scene->cone[i]->err == ERR_MALLOC)
			map_err_i(i + 1, "co", "malloc error");
		else if (scene->cone[i]->err == ERR_IDENTIFIER)
			map_err_i(i + 1, "co", "identifier error");
		else if (scene->cone[i]->err == ERR_LINE_TOKEN)
			map_err_i(i + 1, "co", "line token error");
		else if (scene->cone[i]->err == ERR_XYZ_POS_TOKEN)
			map_err_i(i + 1, "co", "xyz position token error");
		else if (scene->cone[i]->err == ERR_XYZ_POS_VALUE)
			map_err_i(i + 1, "co", "xyz position value error");
		else if (scene->cone[i]->err == ERR_XYZ_VEC_TOKEN)
			map_err_i(i + 1, "co", "xyz normalized vector token error");
		else if (scene->cone[i]->err == ERR_XYZ_VEC_VALUE)
			map_err_i(i + 1, "co", "xyz normalized vector value error");
		else if (scene->cone[i]->err == ERR_DIAMETER_VALUE)
			map_err_i(i + 1, "co", "diameter value error");
		else if (scene->cone[i]->err == ERR_HEIGHT_VALUE)
			map_err_i(i + 1, "co", "height value error");
	}
}

void	err_check_co_2(t_scene *scene, int i)
{
	if (scene->cone[i]->err)
	{
		if (scene->cone[i]->err == ERR_SURFACE_FLAG)
			map_err_i(i + 1, "co", "surface flag error");
		else if (scene->cone[i]->err == ERR_FUZZ_VALUE)
			map_err_i(i + 1, "co", "fuzz value error");
		else if (scene->cone[i]->err == ERR_RGB_TOKEN)
			map_err_i(i + 1, "co", "rbg token error");
		else if (scene->cone[i]->err == ERR_RGB_VALUE)
			map_err_i(i + 1, "co", "rgb value error");
		else if (scene->cone[i]->err == ERR_TEXTURE_PATH)
			map_err_i(i + 1, "co", "texture path error");
		else if (scene->cone[i]->err == ERR_IMAGE_PATH)
			map_err_i(i + 1, "co", "image path error");
	}
}
