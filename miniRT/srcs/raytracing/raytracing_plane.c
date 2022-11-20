/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_plane.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:40:43 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/20 03:48:08 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	check_plane(t_data *data, double *t, int pl_i, double distance)
{
	double	d;
	double	n;

	d = vec3_dot_vec3(data->ray->direc, data->obj[pl_i]->xyz_vec);
	if (!d)
		return (1);
	n = vec3_dot_vec3(vec3_sub_vec3(data->obj[pl_i]->xyz_pos,
				data->ray->point),
			data->obj[pl_i]->xyz_vec);
	*t = n / d;
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
	set_hit_normal_direc(data, hit);
	hit->color = data->obj[pl_i]->rgb;
	return (0);
}

int	light_hit_pl(t_data *data, int pl_i, double distance)
{
	double	t;

	if (data->obj[pl_i]->obj_type != PLANE)
		return (0);
	if (!check_plane(data, &t, pl_i, distance))
		return (0);
	return (1);
}
