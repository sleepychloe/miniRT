/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_plane.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:40:43 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/29 22:42:28 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

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

int	hit_plane(t_data *data, t_hit *hit, int pl_i, double distance)
{
	double	t;

	if (data->obj[pl_i]->obj_type != PLANE)
		return (1);
	if (check_plane(data, &t, pl_i, distance))
		return (1);
	set_hit_point(data, hit, t);
	hit->normal_vec = data->obj[pl_i]->xyz_vec;
	if (hit->normal_vec.x < 0)
		hit->normal_vec.x *= -1;
	if (hit->normal_vec.y < 0)
		hit->normal_vec.y *= -1;
	if (hit->normal_vec.z < 0)
		hit->normal_vec.z *= -1;
	hit->color = data->obj[pl_i]->rgb;
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
