/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cylinder_checkerboard_2_bonus.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:29:51 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/10 20:30:43 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	cylinder_circle_checkerboard_xy(t_data *data, t_hit *hit, int cy_i)
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
			hit->color = data->obj[cy_i]->rgb1;
		else
			hit->color = data->obj[cy_i]->rgb2;
	}
	else
	{
		if ((((int)u % 2) + ((int)v % 2)) % 2 == 0)
			hit->color = data->obj[cy_i]->rgb2;
		else
			hit->color = data->obj[cy_i]->rgb1;
	}
}

void	cylinder_circle_checkerboard_zx(t_data *data, t_hit *hit, int cy_i)
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
			hit->color = data->obj[cy_i]->rgb1;
		else
			hit->color = data->obj[cy_i]->rgb2;
	}
	else
	{
		if ((((int)u % 2) + ((int)v % 2)) % 2 == 0)
			hit->color = data->obj[cy_i]->rgb2;
		else
			hit->color = data->obj[cy_i]->rgb1;
	}
}

void	cylinder_circle_checkerboard_zy(t_data *data, t_hit *hit, int cy_i)
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
			hit->color = data->obj[cy_i]->rgb1;
		else
			hit->color = data->obj[cy_i]->rgb2;
	}
	else
	{
		if ((((int)u % 2) + ((int)v % 2)) % 2 == 0)
			hit->color = data->obj[cy_i]->rgb2;
		else
			hit->color = data->obj[cy_i]->rgb1;
	}
}
