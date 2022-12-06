/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_plane_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:40:43 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/06 23:19:45 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

int	check_plane(t_data *data, double *t, int pl_i, double distance)
{
	t_vec3	rc;
	double	dot_n_d;
	double	dot_n_rc;

	rc = vec3_sub_vec3(data->obj[pl_i]->xyz_pos, data->ray->point);
	dot_n_d = vec3_dot_vec3(data->obj[pl_i]->xyz_vec, data->ray->direc);
	if (dot_n_d == 0)
		return (1);
	dot_n_rc = vec3_dot_vec3(data->obj[pl_i]->xyz_vec, rc);
	*t = dot_n_rc / dot_n_d;
	if (*t < 0.00001 || distance < *t)
		return (1);
	return (0);
}

void	plane_checkerboard(t_data *data, t_hit *hit, int pl_i)
{
	double	u;
	double	v;
	int	u2;
	int	v2;

	if (hit->normal_vec.y != 1)
	{
		u = hit->hit_point.x * (1 + fabs(hit->normal_vec.x)) * fabs(hit->normal_vec.z);
		v = hit->hit_point.y * (1 + fabs(hit->normal_vec.y)) * fabs(hit->normal_vec.z);
		u2 = (int)u % 2;
		v2 = (int)v % 2;
		if ((hit->hit_point.x > 0 && hit->hit_point.y > 0) || (hit->hit_point.x < 0 && hit->hit_point.y < 0))
		{
			if ((u2 + v2) % 2 == 0)
				hit->color = data->obj[pl_i]->rgb1;
			else
				hit->color = data->obj[pl_i]->rgb2;
		}
		else
		{
			if ((u2 + v2) % 2 == 0)
				hit->color = data->obj[pl_i]->rgb2;
			else
				hit->color = data->obj[pl_i]->rgb1;
		}
	}
	if (hit->normal_vec.z != 1)
	{
		u = hit->hit_point.x * (1 + fabs(hit->normal_vec.x)) * fabs(hit->normal_vec.y);
		v = hit->hit_point.z * (1 + fabs(hit->normal_vec.z)) * fabs(hit->normal_vec.y);
		u2 = (int)u % 2;
		v2 = (int)v % 2;
		if ((hit->hit_point.x > 0 && hit->hit_point.z > 0) || (hit->hit_point.x < 0 && hit->hit_point.z < 0))
		{
			if ((u2 + v2) % 2 == 0)
				hit->color = data->obj[pl_i]->rgb1;
			else
				hit->color = data->obj[pl_i]->rgb2;
		}
		else
		{
			if ((u2 + v2) % 2 == 0)
				hit->color = data->obj[pl_i]->rgb2;
			else
				hit->color = data->obj[pl_i]->rgb1;
		}
	}
	
}

int	hit_plane(t_data *data, t_hit *hit, int pl_i, double distance)
{
	double	t;

	if (data->obj[pl_i]->obj_type != PLANE)
		return (1);
	if (check_plane(data, &t, pl_i, distance))
		return (1);
	set_hit_point(data, hit, t);
	hit->normal_vec = data->obj[pl_i]->xyz_vec;
	hit->surface = data->obj[pl_i]->surface;
	hit->fuzz = data->obj[pl_i]->fuzz;
	hit->color = data->obj[pl_i]->rgb1;
	if (data->obj[pl_i]->surface != SURFACE_C)
		hit->color = data->obj[pl_i]->rgb1;
	else
		plane_checkerboard(data, hit, pl_i);
	return (0);
}

int	light_hit_pl(t_data *data, int pl_i, double distance)
{
	double	t;

	if (data->obj[pl_i]->obj_type != PLANE)
		return (1);
	if (check_plane(data, &t, pl_i, distance))
		return (1);
	return (0);
}
