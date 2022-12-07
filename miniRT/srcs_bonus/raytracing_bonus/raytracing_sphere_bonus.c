/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_sphere_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:56:04 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/07 21:43:34 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

int	check_sphere(t_data *data, double *t, int sp_i, double distance)
{
	t_vec3	rc;
	double	a;
	double	b;
	double	c;

	rc = vec3_sub_vec3(data->obj[sp_i]->xyz_pos, data->ray->point);
	a = vec3_dot_vec3(data->ray->direc, data->ray->direc);
	b = -1 * vec3_dot_vec3(rc, data->ray->direc);
	c = vec3_dot_vec3(rc, rc)
		- (((data->obj[sp_i]->diameter) / 2)
			* ((data->obj[sp_i]->diameter) / 2));
	if (b * b - a * c < 0)
		return (1);
	*t = (-1 * b - sqrt(b * b - a * c)) / a;
	if (*t < 0.00001 || distance < *t)
	{
		*t = (-1 * b + sqrt(b * b - a * c)) / a;
		if (*t < 0.00001 || distance < *t)
			return (1);
	}
	return (0);
}

int	hit_sphere(t_data *data, t_hit *hit, int sp_i, double distance)
{
	double	t;

	if (data->obj[sp_i]->obj_type != SPHERE)
		return (1);
	if (check_sphere(data, &t, sp_i, distance))
		return (1);
	set_hit_point(data, hit, t);
	hit->normal_vec = vec3_unit(vec3_sub_vec3(hit->hit_point,
				data->obj[sp_i]->xyz_pos));
	set_hit_normal_direc(data, hit);
	hit->surface = data->obj[sp_i]->surface;
	hit->fuzz = data->obj[sp_i]->fuzz;
	if (data->obj[sp_i]->surface != SURFACE_C)
		hit->color = data->obj[sp_i]->rgb1;
	else
		sphere_checkerboard(data, hit, sp_i);
	return (0);
}

int	light_hit_sp(t_data *data, int sp_i, double distance)
{
	double		t;

	if (data->obj[sp_i]->obj_type != SPHERE)
		return (1);
	if (check_sphere(data, &t, sp_i, distance))
		return (1);
	return (0);
}
