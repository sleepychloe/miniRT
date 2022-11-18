/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_sphere.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:56:04 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/18 23:49:48 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	check_sphere(t_data *data, double *t, int sp_i, double lim)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;

	oc = vec3_sub_vec3(data->ray->point, data->obj[sp_i]->xyz_pos);
	a = vec3_dot_vec3(data->ray->direc, data->ray->direc);
	b = vec3_dot_vec3(oc, data->ray->direc);
	c = vec3_dot_vec3(oc, oc)
		- (((data->obj[sp_i]->diameter) / 2)
			* ((data->obj[sp_i]->diameter) / 2));
	if (b * b - a * c < 0)
		return (1);
	*t = (-1 * b - sqrt(b * b - a * c)) / a;
	if (*t < 0.00001 || lim < *t)
	{
		*t = (-1 * b + sqrt(b * b - a * c)) / a;
		if (*t < 0.00001 || lim < *t)
			return (1);
	}
	return (0);
}

int	hit_sphere(t_data *data, t_hit *hit, int sp_i, double lim)
{
	double	t;

	if (data->obj[sp_i]->obj_type != SPHERE)
		return (1);
	if (check_sphere(data, &t, sp_i, lim))
		return (1);
	set_hit_point(data, hit, t);
	hit->normal_vec = vec3_unit(vec3_sub_vec3(hit->hit_point,
				data->obj[sp_i]->xyz_pos));
	set_hit_normal_direc(data, hit);
	hit->color = data->obj[sp_i]->rgb;
	return (0);
}

int	interfere_sp(t_data *data, int sp_i, double lim)
{
	double		t;

	if (data->obj[sp_i]->obj_type != SPHERE)
		return (1);
	if (!check_sphere(data, &t, sp_i, lim))
		return (1);
	return (0);
}
