/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_plane_img_texture_1_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 23:44:04 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/18 23:44:29 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	plane_img_texture_norminette_1(t_data *data, t_hit *hit, int pl_i)
{
	if (hit->normal_vec.y == 1 || hit->normal_vec.y == -1)
		plane_img_texture_xz(data, hit, pl_i);
	else if (hit->normal_vec.x == 1 || hit->normal_vec.x == -1)
		plane_img_texture_zy(data, hit, pl_i);
	else
		plane_img_texture_xy(data, hit, pl_i);
}

void	plane_img_texture_norminette_2(t_data *data, t_hit *hit, int pl_i)
{
	if (hit->normal_vec.z == 0)
	{
		if ((hit->normal_vec.y == 1 || hit->normal_vec.y == -1))
			plane_img_texture_xz(data, hit, pl_i);
		else
			plane_img_texture_zy(data, hit, pl_i);
	}
	else
	{
		if (hit->normal_vec.x == 1 || hit->normal_vec.x == -1)
			plane_img_texture_zy(data, hit, pl_i);
		else if (hit->normal_vec.y == 1 || hit->normal_vec.y == -1)
			plane_img_texture_xz(data, hit, pl_i);
		else
			plane_img_texture_xy(data, hit, pl_i);
	}
}

void	plane_img_texture(t_data *data, t_hit *hit, int pl_i)
{
	if (sqrt(hit->normal_vec.x * hit->normal_vec.x
			+ hit->normal_vec.y * hit->normal_vec.y) == 1
		&& hit->normal_vec.x != 0 && hit->normal_vec.y != 0
		&& hit->normal_vec.x != 1 && hit->normal_vec.x != -1
		&& hit->normal_vec.y != 1 && hit->normal_vec.y != -1)
		plane_img_texture_xz(data, hit, pl_i);
	else if (fabs(hit->normal_vec.x) > 0.8
		&& hit->normal_vec.x != 1 && hit->normal_vec.x != -1
		&& hit->normal_vec.y != 0 && hit->normal_vec.z != 0)
		plane_img_texture_zy(data, hit, pl_i);
	else if (fabs(hit->normal_vec.y) > 0.8
		&& hit->normal_vec.y != 1 && hit->normal_vec.y != -1
		&& hit->normal_vec.x != 0 && hit->normal_vec.z != 0)
		plane_img_texture_xz(data, hit, pl_i);
	else if (fabs(hit->normal_vec.z) > 0.8
		&& hit->normal_vec.z != 1 && hit->normal_vec.z != -1
		&& hit->normal_vec.x != 0 && hit->normal_vec.y != 0)
		plane_img_texture_zy(data, hit, pl_i);
	else if (hit->normal_vec.x == 0)
		plane_img_texture_norminette_1(data, hit, pl_i);
	else
		plane_img_texture_norminette_2(data, hit, pl_i);
}
