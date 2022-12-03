/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_err_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 01:09:02 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/03 05:48:19 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	err_check_sp_1(t_scene *scene, int i)
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
	}
}

void	err_check_sp_2(t_scene *scene, int i)
{
	if (scene->sphere[i]->err)
	{
		if (scene->sphere[i]->err == ERR_SURFACE_FLAG)
			map_err_i(i + 1, "sp", "surface flag error");
		else if (scene->sphere[i]->err == ERR_FUZZ_VALUE)
			map_err_i(i + 1, "sp", "fuzz value error");
		else if (scene->sphere[i]->err == ERR_RGB_TOKEN)
			map_err_i(i + 1, "sp", "rbg token error");
		else if (scene->sphere[i]->err == ERR_RGB_VALUE)
			map_err_i(i + 1, "sp", "rgb value error");
		else if (scene->sphere[i]->err == ERR_TEXTURE_PATH)
			map_err_i(i + 1, "sp", "texture path error");
		else if (scene->sphere[i]->err == ERR_IMAGE_PATH)
			map_err_i(i + 1, "sp", "image path error");
	}
}

void	err_check_pl_1(t_scene *scene, int i)
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
	}
}

void	err_check_pl_2(t_scene *scene, int i)
{
	if (scene->plane[i]->err)
	{
		if (scene->plane[i]->err == ERR_SURFACE_FLAG)
			map_err_i(i + 1, "pl", "surface flag error");
		else if (scene->plane[i]->err == ERR_FUZZ_VALUE)
			map_err_i(i + 1, "pl", "fuzz value error");
		else if (scene->plane[i]->err == ERR_RGB_TOKEN)
			map_err_i(i + 1, "pl", "rbg token error");
		else if (scene->plane[i]->err == ERR_RGB_VALUE)
			map_err_i(i + 1, "pl", "rgb value error");
		else if (scene->plane[i]->err == ERR_TEXTURE_PATH)
			map_err_i(i + 1, "pl", "texture path error");
		else if (scene->plane[i]->err == ERR_IMAGE_PATH)
			map_err_i(i + 1, "pl", "image path error");
	}
}
