/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_trace_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 07:26:44 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/01 08:02:21 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

int	hittable(t_data *data, t_hit *hit)
{
	int		i;
	int		hit_flag;
	double	distance;

	i = 0;
	hit_flag = 0;
	distance = INFINITY;
	while (i < data->n_obj + data->scene->n_plane + data->scene->n_plane)
	{
		if (!(hit_sphere(data, hit, i, distance))
			|| !(hit_plane(data, hit, i, distance))
			|| !(hit_cylinder(data, hit, i, distance)))
		{
			hit_flag = 1;
			distance = hit->t;
		}
		i++;
	}
	return (hit_flag);
}

t_rgb3	calc_ambient(t_data *data, t_hit *hit)
{
	t_rgb3	ambient;

	ambient.r = (data->scene->ambient->lighting)
		* (data->scene->ambient->rgb.r) * hit->color.r * 0.001;
	ambient.g = (data->scene->ambient->lighting)
		* (data->scene->ambient->rgb.g) * hit->color.g * 0.001;
	ambient.b = (data->scene->ambient->lighting)
		* (data->scene->ambient->rgb.b) * hit->color.b * 0.001;
	return (ambient);
}

t_rgb3	calc_diffuse(t_data *data, t_hit *hit, int *depth)
{
	t_vec3	target;
	t_ray	ray_diffuse;
	t_rgb3	diffuse;

	target = vec3_add_vec3(vec3_add_vec3(hit->hit_point, hit->normal_vec),
			random_double_xyz());
	if (vec3_dot_vec3(target, hit->normal_vec) < 0)
		target = vec3_add_vec3(vec3_add_vec3(hit->hit_point, hit->normal_vec),
				vec3_mul_rn(hit->normal_vec, 1.0));
	ray_diffuse = ray(hit->hit_point, vec3_sub_vec3(target, hit->hit_point));
	diffuse = rgb3(0, 0, 0);
	diffuse = color_add(diffuse, trace(data, ray_diffuse, *depth - 1));
	diffuse.r *= 0.1;
	diffuse.g *= 0.1;
	diffuse.b *= 0.1;
	return (diffuse);
}

t_rgb3	trace(t_data *data, t_ray ray_set, int depth)
{
	t_hit	hit;
	t_rgb3	ambient;
	t_rgb3	light;
	t_rgb3	diffuse;
	int		i;

	i = -1;
	if (depth <= 0)
		return (rgb3(0, 0, 0));
	data->ray = &ray_set;
	if (hittable(data, &hit))
	{
		ambient = calc_ambient(data, &hit);
		light = rgb3(0, 0, 0);
		while (++i < data->scene->n_light)
			light = color_add(light, apply_light(data, &hit, i));
		diffuse = calc_diffuse(data, &hit, &depth);
		return (color_add(color_add(ambient, light), diffuse));
	}
	return (rgb3(0, 0, 0));
}
