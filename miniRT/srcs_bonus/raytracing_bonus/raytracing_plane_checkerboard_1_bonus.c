/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_plane_checkerboard_1_bonus.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:55:02 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/07 21:43:21 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	plane_checkerboard_norminette_1(t_data *data, t_hit *hit, int pl_i)
{
	if (hit->normal_vec.y == 1 || hit->normal_vec.y == -1)
		plane_checkerboard_xz(data, hit, pl_i);
	else if (hit->normal_vec.x == 1 || hit->normal_vec.x == -1)
		plane_checkerboard_zy(data, hit, pl_i);
	else
		plane_checkerboard_xy(data, hit, pl_i);
}

void	plane_checkerboard_norminette_2(t_data *data, t_hit *hit, int pl_i)
{
	if (hit->normal_vec.z == 0)
	{
		if ((hit->normal_vec.y == 1 || hit->normal_vec.y == -1))
			plane_checkerboard_xz(data, hit, pl_i);
		else
			plane_checkerboard_zy(data, hit, pl_i);
	}
	else
	{
		if (hit->normal_vec.x == 1 || hit->normal_vec.x == -1)
			plane_checkerboard_zy(data, hit, pl_i);
		else if (hit->normal_vec.y == 1 || hit->normal_vec.y == -1)
			plane_checkerboard_xz(data, hit, pl_i);
		else
			plane_checkerboard_xy(data, hit, pl_i);
	}
}

void	plane_checkerboard(t_data *data, t_hit *hit, int pl_i)
{
	if (sqrt(hit->normal_vec.x * hit->normal_vec.x
			+ hit->normal_vec.y * hit->normal_vec.y) == 1
		&& hit->normal_vec.x != 0 && hit->normal_vec.y != 0
		&& hit->normal_vec.x != 1 && hit->normal_vec.x != -1
		&& hit->normal_vec.y != 1 && hit->normal_vec.y != -1)
		plane_checkerboard_xz(data, hit, pl_i);
	else if (fabs(hit->normal_vec.x) > 0.8
		&& hit->normal_vec.x != 1 && hit->normal_vec.x != -1
		&& hit->normal_vec.y != 0 && hit->normal_vec.z != 0)
		plane_checkerboard_zy(data, hit, pl_i);
	else if (fabs(hit->normal_vec.y) > 0.8
		&& hit->normal_vec.y != 1 && hit->normal_vec.y != -1
		&& hit->normal_vec.x != 0 && hit->normal_vec.z != 0)
		plane_checkerboard_xz(data, hit, pl_i);
	else if (fabs(hit->normal_vec.z) > 0.8
		&& hit->normal_vec.z != 1 && hit->normal_vec.z != -1
		&& hit->normal_vec.x != 0 && hit->normal_vec.y != 0)
		plane_checkerboard_zy(data, hit, pl_i);
	else if (hit->normal_vec.x == 0)
		plane_checkerboard_norminette_1(data, hit, pl_i);
	else
		plane_checkerboard_norminette_2(data, hit, pl_i);
}
