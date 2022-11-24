/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cylinder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 02:31:10 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/24 02:29:15 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	check_cylinder_height(t_data *data, double *t, int cy_i)
{
	double	delta;
	t_vec3	cy_top_center;
	t_vec3	cy_bottom_center;
	t_vec3	hit_point;

	delta = data->obj[cy_i]->height / 2
		* sqrt(1 / (data->obj[cy_i]->xyz_vec.x * data->obj[cy_i]->xyz_vec.x
			+ data->obj[cy_i]->xyz_vec.y * data->obj[cy_i]->xyz_vec.y
			+ data->obj[cy_i]->xyz_vec.z * data->obj[cy_i]->xyz_vec.z));
	cy_top_center = vec3(data->obj[cy_i]->xyz_pos.x + delta,
				data->obj[cy_i]->xyz_pos.y + delta,
				data->obj[cy_i]->xyz_pos.z + delta);
	cy_bottom_center = vec3(data->obj[cy_i]->xyz_pos.x - delta,
				data->obj[cy_i]->xyz_pos.y - delta,
				data->obj[cy_i]->xyz_pos.z - delta);
	hit_point = vec3_add_vec3(data->ray->point,
				vec3_mul_rn(data->ray->direc, *t));
	if (vec3_dot_vec3(vec3_sub_vec3(hit_point, cy_top_center),
				data->obj[cy_i]->xyz_vec) > 0
		|| vec3_dot_vec3(vec3_sub_vec3(hit_point, cy_bottom_center),
				data->obj[cy_i]->xyz_vec) < 0)
		return (1);
	return (0);
}

void	norminette_check_cylinder(t_data *data, int cy_i, double *dot)
{
	t_vec3	rc;

	rc = vec3_sub_vec3(data->obj[cy_i]->xyz_pos, data->ray->point);
	dot[0] = vec3_dot_vec3(data->ray->direc, data->obj[cy_i]->xyz_vec);
	dot[1] = vec3_dot_vec3(rc, data->obj[cy_i]->xyz_vec);
}

int	check_cylinder(t_data *data, double *t, int cy_i, double distance)
{
	t_vec3	rc;
	double	dot[2];
	double	a;
	double	b;
	double	c;

	norminette_check_cylinder(data, cy_i, dot);
	rc = vec3_sub_vec3(data->obj[cy_i]->xyz_pos, data->ray->point);
	a = vec3_dot_vec3(data->ray->direc, data->ray->direc) - dot[0] * dot[0];
	b = -1 * (vec3_dot_vec3(rc, data->ray->direc) - dot[0] * dot[1]);
	c = (vec3_dot_vec3(rc, rc) - dot[1] * dot[1])
		- (data->obj[cy_i]->diameter) / 2 * (data->obj[cy_i]->diameter) / 2;
	if (b * b - a * c < 0)
		return (1);
	*t = (-1 * b - sqrt(b * b - a * c)) / a;
	if (*t < 0.00001 || distance < *t)
	{
		*t = (-1 * b + sqrt(b * b - a * c)) / a;
		if (*t < 0.00001 || distance < *t)
			return (1);
	}
	if (check_cylinder_height(data, t, cy_i))
		return (1);
	return (0);
}

int	hit_cylinder(t_data *data, t_hit *hit, int cy_i, double distance)
{
	double	t;

	if (data->obj[cy_i]->obj_type != CYLINDER)
		return (1);
	if (check_cylinder(data, &t, cy_i, distance))
		return (1);
	set_hit_point(data, hit, t);
	hit->normal_vec = data->obj[cy_i]->xyz_vec;
	set_hit_normal_direc(data, hit);
	hit->color = data->obj[cy_i]->rgb;
	return (0);
}

int	light_hit_cy(t_data *data, int cy_i, double distance)
{
	double	t;

	if (data->obj[cy_i]->obj_type != CYLINDER)
		return (0);
	if (!check_cylinder(data, &t, cy_i, distance))
		return (0);
	return (1);
}
