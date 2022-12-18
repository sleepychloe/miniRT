/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_plane_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:40:43 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/18 22:09:22 by yhwang           ###   ########.fr       */
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
	if (data->obj[pl_i]->surface == SURFACE_C)
		plane_checkerboard(data, hit, pl_i);
	else if (data->obj[pl_i]->surface == SURFACE_I)
		plane_img(data, hit, pl_i);
	else if (data->obj[pl_i]->surface == SURFACE_T)
		plane_texture(data, hit, pl_i);
	else
		hit->color = data->obj[pl_i]->rgb1;
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
