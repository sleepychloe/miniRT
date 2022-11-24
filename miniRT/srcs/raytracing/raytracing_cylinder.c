/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cylinder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 02:31:10 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/24 09:24:39 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	check_cylinder_height(t_data *data, double *t, int cy_i)
{
	double	delta;
	t_vec3	cy_top_center;
	t_vec3	cy_bottom_center;
	t_vec3	top_hit_point;

	delta = data->obj[cy_i]->height / 2
		* sqrt(1 / (data->obj[cy_i]->xyz_vec.x * data->obj[cy_i]->xyz_vec.x
			+ data->obj[cy_i]->xyz_vec.y * data->obj[cy_i]->xyz_vec.y
			+ data->obj[cy_i]->xyz_vec.z * data->obj[cy_i]->xyz_vec.z));
	cy_top_center = vec3(data->obj[cy_i]->xyz_pos.x + delta * data->obj[cy_i]->xyz_vec.x,
				data->obj[cy_i]->xyz_pos.y + delta * data->obj[cy_i]->xyz_vec.y,
				data->obj[cy_i]->xyz_pos.z + delta * data->obj[cy_i]->xyz_vec.z);
	cy_bottom_center = vec3(data->obj[cy_i]->xyz_pos.x - delta * data->obj[cy_i]->xyz_vec.x,
				data->obj[cy_i]->xyz_pos.y - delta * data->obj[cy_i]->xyz_vec.y,
				data->obj[cy_i]->xyz_pos.z - delta * data->obj[cy_i]->xyz_vec.z);
	top_hit_point = vec3_add_vec3(data->ray->point,
				vec3_mul_rn(data->ray->direc, *t));
	if (vec3_dot_vec3(vec3_sub_vec3(top_hit_point, cy_top_center),
				data->obj[cy_i]->xyz_vec) > 0
		|| vec3_dot_vec3(vec3_sub_vec3(top_hit_point, cy_bottom_center),
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

double	check_cylinder_body(t_data *data, double *t, int cy_i, double distance)
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
		return (INFINITY);
	*t = (-1 * b - sqrt(b * b - a * c)) / a;
	if (*t < 0.00001 || distance < *t)
	{
		*t = (-1 * b + sqrt(b * b - a * c)) / a;
		if (*t < 0.00001 || distance < *t)
			return (INFINITY);
	}
	if (check_cylinder_height(data, t, cy_i))
		return (INFINITY);
	return (*t);
}

double	check_cylinder_circle(t_data *data, int cy_i, double distance)
{
	t_vec3	top_tc;
	t_vec3	bottom_tc;
	double	dot_normal_ray;
	double	dot_normal_top_tc;
	double	dot_normal_bottom_tc;
	double	delta;
	t_vec3	cy_top_center;
	t_vec3	cy_bottom_center;
	t_vec3	top_hit_point;
	t_vec3	bottom_hit_point;
	double	top_t;
	double	bottom_t;

	delta = data->obj[cy_i]->height / 2
		* sqrt(1 / (data->obj[cy_i]->xyz_vec.x * data->obj[cy_i]->xyz_vec.x
			+ data->obj[cy_i]->xyz_vec.y * data->obj[cy_i]->xyz_vec.y
			+ data->obj[cy_i]->xyz_vec.z * data->obj[cy_i]->xyz_vec.z));
	cy_top_center = vec3(data->obj[cy_i]->xyz_pos.x + delta * data->obj[cy_i]->xyz_vec.x,
				data->obj[cy_i]->xyz_pos.y + delta * data->obj[cy_i]->xyz_vec.y,
				data->obj[cy_i]->xyz_pos.z + delta * data->obj[cy_i]->xyz_vec.z);
	cy_bottom_center = vec3(data->obj[cy_i]->xyz_pos.x - delta * data->obj[cy_i]->xyz_vec.x,
				data->obj[cy_i]->xyz_pos.y - delta * data->obj[cy_i]->xyz_vec.y,
				data->obj[cy_i]->xyz_pos.z - delta * data->obj[cy_i]->xyz_vec.z);
	top_tc = vec3_sub_vec3(cy_top_center, data->ray->point);
	bottom_tc = vec3_sub_vec3(cy_bottom_center, data->ray->point);
	dot_normal_ray = vec3_dot_vec3(data->obj[cy_i]->xyz_vec, data->ray->direc);
	if (dot_normal_ray == 0)
		return (INFINITY);
	dot_normal_top_tc = vec3_dot_vec3(data->obj[cy_i]->xyz_vec, top_tc);
	dot_normal_bottom_tc = vec3_dot_vec3(data->obj[cy_i]->xyz_vec, bottom_tc);
	top_t = dot_normal_top_tc / dot_normal_ray;
	bottom_t = dot_normal_bottom_tc / dot_normal_ray;
	if (top_t < 0.00001 || distance < top_t)
		top_t = INFINITY;
	if (bottom_t < 0.00001 || distance < bottom_t)
		bottom_t = INFINITY;
	top_hit_point = vec3_add_vec3(data->ray->point,
				vec3_mul_rn(data->ray->direc, top_t));
	bottom_hit_point = vec3_add_vec3(data->ray->point,
				vec3_mul_rn(data->ray->direc, bottom_t));
	if (sqrt(vec3_dot_vec3(vec3_sub_vec3(top_hit_point, cy_top_center),
		vec3_sub_vec3(top_hit_point, cy_top_center))) > (data->obj[cy_i]->diameter / 2))
		top_t = INFINITY;
	if (sqrt(vec3_dot_vec3(vec3_sub_vec3(bottom_hit_point, cy_bottom_center),
		vec3_sub_vec3(bottom_hit_point, cy_bottom_center))) > (data->obj[cy_i]->diameter / 2))
		bottom_t = INFINITY;
	if (top_t < bottom_t)
		return (top_t);
	return (bottom_t);
}


int	hit_cylinder(t_data *data, t_hit *hit, int cy_i, double distance)
{
	double	t_body;
	double	t_circle;

	if (data->obj[cy_i]->obj_type != CYLINDER)
		return (1);
	t_body = check_cylinder_body(data, &t_body, cy_i, distance);
	t_circle = check_cylinder_circle(data, cy_i, distance);
	if (t_body == INFINITY && t_circle == INFINITY)
		return (1);
	if (t_body < t_circle)
	{
		set_hit_point(data, hit, t_body);
		hit->normal_vec = vec3_unit(vec3_sub_vec3(hit->hit_point,
			vec3_add_vec3(data->obj[cy_i]->xyz_pos,
				vec3_mul_rn(data->obj[cy_i]->xyz_vec,
					((vec3_dot_vec3(data->obj[cy_i]->xyz_vec,
					vec3_sub_vec3(hit->hit_point, data->obj[cy_i]->xyz_pos))))
					/ vec3_dot_vec3(data->obj[cy_i]->xyz_vec,
						data->obj[cy_i]->xyz_vec)))));
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
	t_body = check_cylinder_body(data, &t_body, cy_i, distance);
	t_circle = check_cylinder_circle(data, cy_i, distance);
	if (t_body == INFINITY && t_circle == INFINITY)
		return (0);
	return (1);
}
