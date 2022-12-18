/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cylinder_1_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 02:31:10 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/18 22:13:30 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

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

void	cy_put_value_hit_struct(t_data *data, t_hit *hit, int cy_i)
{
	hit->surface = data->obj[cy_i]->surface;
	hit->fuzz = data->obj[cy_i]->fuzz;
	if (data->obj[cy_i]->surface == SURFACE_C)
		cylinder_checkerboard(data, hit, cy_i);
	else if (data->obj[cy_i]->surface == SURFACE_I)
		cylinder_img(data, hit, cy_i);
	else if (data->obj[cy_i]->surface == SURFACE_T)
		cylinder_texture(data, hit, cy_i);
	else
		hit->color = data->obj[cy_i]->rgb1;
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
	cy_put_value_hit_struct(data, hit, cy_i);
	return (0);
}

int	light_hit_cy(t_data *data, int cy_i, double distance)
{
	double	t_body;
	double	t_circle;

	if (data->obj[cy_i]->obj_type != CYLINDER)
		return (1);
	t_body = check_cylinder_body(data, cy_i, distance);
	t_circle = check_cylinder_circle(data, cy_i, distance);
	if (t_body == INFINITY && t_circle == INFINITY)
		return (1);
	return (0);
}
