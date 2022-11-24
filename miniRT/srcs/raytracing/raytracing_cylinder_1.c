/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cylinder_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 02:31:10 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/24 16:27:54 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	norminette_check_cylinder_body(t_data *data,
				int cy_i, double *d, t_vec3 *cy_center)
{
	t_vec3	rc;
	double	dot_n_d;
	double	dot_n_rc;
	double	delta;

	rc = vec3_sub_vec3(data->obj[cy_i]->xyz_pos, data->ray->point);
	dot_n_d = vec3_dot_vec3(data->ray->direc, data->obj[cy_i]->xyz_vec);
	dot_n_rc = vec3_dot_vec3(rc, data->obj[cy_i]->xyz_vec);
	d[0] = vec3_dot_vec3(data->ray->direc, data->ray->direc)
		- dot_n_d * dot_n_d;
	d[1] = -1 * (vec3_dot_vec3(rc, data->ray->direc) - dot_n_d * dot_n_rc);
	d[2] = (vec3_dot_vec3(rc, rc) - dot_n_rc * dot_n_rc)
		- (data->obj[cy_i]->diameter) / 2 * (data->obj[cy_i]->diameter) / 2;
	delta = data->obj[cy_i]->height / 2
		* sqrt(1 / (data->obj[cy_i]->xyz_vec.x * data->obj[cy_i]->xyz_vec.x
				+ data->obj[cy_i]->xyz_vec.y * data->obj[cy_i]->xyz_vec.y
				+ data->obj[cy_i]->xyz_vec.z * data->obj[cy_i]->xyz_vec.z));
	cy_center[TOP]
		= vec3(data->obj[cy_i]->xyz_pos.x + delta * data->obj[cy_i]->xyz_vec.x,
			data->obj[cy_i]->xyz_pos.y + delta * data->obj[cy_i]->xyz_vec.y,
			data->obj[cy_i]->xyz_pos.z + delta * data->obj[cy_i]->xyz_vec.z);
	cy_center[BOTTOM]
		= vec3(data->obj[cy_i]->xyz_pos.x - delta * data->obj[cy_i]->xyz_vec.x,
			data->obj[cy_i]->xyz_pos.y - delta * data->obj[cy_i]->xyz_vec.y,
			data->obj[cy_i]->xyz_pos.z - delta * data->obj[cy_i]->xyz_vec.z);
}

double	check_cylinder_body(t_data *data, int cy_i, double distance)
{
	double	d[3];
	t_vec3	cy_center[2];
	double	t_body;

	norminette_check_cylinder_body(data, cy_i, d, cy_center);
	if (d[1] * d[1] - d[0] * d[2] < 0)
		return (INFINITY);
	t_body = (-1 * d[1] - sqrt(d[1] * d[1] - d[0] * d[2])) / d[0];
	if (t_body < 0.00001 || distance < t_body)
	{
		t_body = (-1 * d[1] + sqrt(d[1] * d[1] - d[0] * d[2])) / d[0];
		if (t_body < 0.00001 || distance < t_body)
			return (INFINITY);
	}
	if (vec3_dot_vec3(vec3_sub_vec3(vec3_add_vec3(data->ray->point,
					vec3_mul_rn(data->ray->direc, t_body)),
				cy_center[TOP]), data->obj[cy_i]->xyz_vec) > 0
		|| vec3_dot_vec3(vec3_sub_vec3(vec3_add_vec3(data->ray->point,
					vec3_mul_rn(data->ray->direc, t_body)),
				cy_center[BOTTOM]), data->obj[cy_i]->xyz_vec) < 0)
		return (INFINITY);
	return (t_body);
}

t_vec3	calc_normal_vec_cylinder_body(t_data *data, t_hit *hit, int cy_i)
{
	t_vec3	hit_p;
	t_vec3	c_hit_p;
	t_vec3	proj_c_hit_p;
	t_vec3	res;

	hit_p = hit->hit_point;
	c_hit_p = vec3_sub_vec3(hit->hit_point, data->obj[cy_i]->xyz_pos);
	proj_c_hit_p = vec3_mul_rn(data->obj[cy_i]->xyz_vec,
			(vec3_dot_vec3(data->obj[cy_i]->xyz_vec, c_hit_p)
				/ vec3_dot_vec3(data->obj[cy_i]->xyz_vec,
					data->obj[cy_i]->xyz_vec)));
	res = vec3_sub_vec3(hit_p,
			vec3_add_vec3(data->obj[cy_i]->xyz_pos, proj_c_hit_p));
	res = vec3_unit(res);
	return (res);
}

int	hit_cylinder(t_data *data, t_hit *hit, int cy_i, double distance)
{
	double	t_body;
	double	t_circle;

	if (data->obj[cy_i]->obj_type != CYLINDER)
		return (1);
	t_body = check_cylinder_body(data, cy_i, distance);
	t_circle = check_cylinder_circle(data, cy_i, distance);
	if (t_body == INFINITY && t_circle == INFINITY)
		return (1);
	if (t_body < t_circle)
	{
		set_hit_point(data, hit, t_body);
		hit->normal_vec = calc_normal_vec_cylinder_body(data, hit, cy_i);
		set_hit_normal_direc(data, hit);
	}
	else
	{
		set_hit_point(data, hit, t_circle);
		hit->normal_vec = data->obj[cy_i]->xyz_vec;
		set_hit_normal_direc(data, hit);
	}
	hit->color = data->obj[cy_i]->rgb;
	return (0);
}

int	light_hit_cy(t_data *data, int cy_i, double distance)
{
	double	t_body;
	double	t_circle;

	if (data->obj[cy_i]->obj_type != CYLINDER)
		return (0);
	t_body = check_cylinder_body(data, cy_i, distance);
	t_circle = check_cylinder_circle(data, cy_i, distance);
	if (t_body == INFINITY && t_circle == INFINITY)
		return (0);
	return (1);
}
