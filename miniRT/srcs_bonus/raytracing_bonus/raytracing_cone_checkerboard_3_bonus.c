/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cone_checkerboard_3_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:46:59 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/10 22:47:20 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	cone_circle_checkerboard_xy(t_data *data, t_hit *hit, int co_i)
{
	double	u;
	double	v;

	u = hit->hit_point.x
		* (1 + fabs(hit->normal_vec.x)) * fabs(hit->normal_vec.z) * 5;
	v = hit->hit_point.y
		* (1 + fabs(hit->normal_vec.y)) * fabs(hit->normal_vec.z) * 5;
	if ((hit->hit_point.x > 0 && hit->hit_point.y > 0)
		|| (hit->hit_point.x < 0 && hit->hit_point.y < 0))
	{
		if ((((int)u % 2) + ((int)v % 2)) % 2 == 0)
			hit->color = data->obj[co_i]->rgb1;
		else
			hit->color = data->obj[co_i]->rgb2;
	}
	else
	{
		if ((((int)u % 2) + ((int)v % 2)) % 2 == 0)
			hit->color = data->obj[co_i]->rgb2;
		else
			hit->color = data->obj[co_i]->rgb1;
	}
}

void	cone_circle_checkerboard_zx(t_data *data, t_hit *hit, int co_i)
{
	double	u;
	double	v;

	u = hit->hit_point.z
		* (1 + fabs(hit->normal_vec.z)) * fabs(hit->normal_vec.y) * 5;
	v = hit->hit_point.x
		* (1 + fabs(hit->normal_vec.x)) * fabs(hit->normal_vec.y) * 5;
	if ((hit->hit_point.x > 0 && hit->hit_point.z > 0)
		|| (hit->hit_point.x < 0 && hit->hit_point.z < 0))
	{
		if ((((int)u % 2) + ((int)v % 2)) % 2 == 0)
			hit->color = data->obj[co_i]->rgb1;
		else
			hit->color = data->obj[co_i]->rgb2;
	}
	else
	{
		if ((((int)u % 2) + ((int)v % 2)) % 2 == 0)
			hit->color = data->obj[co_i]->rgb2;
		else
			hit->color = data->obj[co_i]->rgb1;
	}
}

void	cone_circle_checkerboard_zy(t_data *data, t_hit *hit, int co_i)
{
	double	u;
	double	v;

	u = hit->hit_point.z
		* (1 + fabs(hit->normal_vec.z)) * fabs(hit->normal_vec.x) * 5;
	v = hit->hit_point.y
		* (1 + fabs(hit->normal_vec.y)) * fabs(hit->normal_vec.x) * 5;
	if ((hit->hit_point.z > 0 && hit->hit_point.y > 0)
		|| (hit->hit_point.z < 0 && hit->hit_point.y < 0))
	{
		if ((((int)u % 2) + ((int)v % 2)) % 2 == 0)
			hit->color = data->obj[co_i]->rgb1;
		else
			hit->color = data->obj[co_i]->rgb2;
	}
	else
	{
		if ((((int)u % 2) + ((int)v % 2)) % 2 == 0)
			hit->color = data->obj[co_i]->rgb2;
		else
			hit->color = data->obj[co_i]->rgb1;
	}
}
