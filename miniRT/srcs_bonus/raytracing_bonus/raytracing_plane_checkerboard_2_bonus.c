/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_plane_checkerboard_2_bonus.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:56:04 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/07 21:43:19 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	plane_checkerboard_xy(t_data *data, t_hit *hit, int pl_i)
{
	double	u;
	double	v;

	u = hit->hit_point.x
		* (1 + fabs(hit->normal_vec.x)) * fabs(hit->normal_vec.z);
	v = hit->hit_point.y
		* (1 + fabs(hit->normal_vec.y)) * fabs(hit->normal_vec.z);
	if ((hit->hit_point.x > 0 && hit->hit_point.y > 0)
		|| (hit->hit_point.x < 0 && hit->hit_point.y < 0))
	{
		if ((((int)u % 2) + ((int)v % 2)) % 2 == 0)
			hit->color = data->obj[pl_i]->rgb1;
		else
			hit->color = data->obj[pl_i]->rgb2;
	}
	else
	{
		if ((((int)u % 2) + ((int)v % 2)) % 2 == 0)
			hit->color = data->obj[pl_i]->rgb2;
		else
			hit->color = data->obj[pl_i]->rgb1;
	}
}

void	plane_checkerboard_xz(t_data *data, t_hit *hit, int pl_i)
{
	double	u;
	double	v;

	u = hit->hit_point.x
		* (1 + fabs(hit->normal_vec.x)) * fabs(hit->normal_vec.y);
	v = hit->hit_point.z
		* (1 + fabs(hit->normal_vec.z)) * fabs(hit->normal_vec.y);
	if ((hit->hit_point.x > 0 && hit->hit_point.z > 0)
		|| (hit->hit_point.x < 0 && hit->hit_point.z < 0))
	{
		if ((((int)u % 2) + ((int)v % 2)) % 2 == 0)
			hit->color = data->obj[pl_i]->rgb1;
		else
			hit->color = data->obj[pl_i]->rgb2;
	}
	else
	{
		if ((((int)u % 2) + ((int)v % 2)) % 2 == 0)
			hit->color = data->obj[pl_i]->rgb2;
		else
			hit->color = data->obj[pl_i]->rgb1;
	}
}

void	plane_checkerboard_zy(t_data *data, t_hit *hit, int pl_i)
{
	double	u;
	double	v;

	u = hit->hit_point.z
		* (1 + fabs(hit->normal_vec.z)) * fabs(hit->normal_vec.x);
	v = hit->hit_point.y
		* (1 + fabs(hit->normal_vec.y)) * fabs(hit->normal_vec.x);
	if ((hit->hit_point.z > 0 && hit->hit_point.y > 0)
		|| (hit->hit_point.z < 0 && hit->hit_point.y < 0))
	{
		if ((((int)u % 2) + ((int)v % 2)) % 2 == 0)
			hit->color = data->obj[pl_i]->rgb1;
		else
			hit->color = data->obj[pl_i]->rgb2;
	}
	else
	{
		if ((((int)u % 2) + ((int)v % 2)) % 2 == 0)
			hit->color = data->obj[pl_i]->rgb2;
		else
			hit->color = data->obj[pl_i]->rgb1;
	}
}
