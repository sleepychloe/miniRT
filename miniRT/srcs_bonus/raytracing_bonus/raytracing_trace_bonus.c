/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_trace_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 07:26:44 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/16 04:31:18 by yhwang           ###   ########.fr       */
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
	while (i < data->n_obj + data->scene->n_plane)
	{
		if (!(hit_sphere(data, hit, i, distance))
			|| !(hit_plane(data, hit, i, distance))
			|| !(hit_cylinder(data, hit, i, distance))
			|| !(hit_cone(data, hit, i, distance)))
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

t_rgb3	trace(t_data *data, t_ray ray_set, int depth)
{
	t_hit	hit;
	t_rgb3	ambient;
	t_rgb3	light;

	if (depth <= 0)
		return (rgb3(0, 0, 0));
	data->ray = &ray_set;
	if (hittable(data, &hit))
	{
		ambient = calc_ambient(data, &hit);
		light = color_add(color_mul_rn(apply_specular(data, &hit), 0.05),
				apply_light(data, &hit));
		if (!(hit.surface == SURFACE_M))
			return (color_add(color_add(ambient, light),
					color_mul_rn(surface_lambertian(data,
							&hit, &depth), 0.2)));
		else
			return (color_add(color_add(ambient, light),
					surface_metal(data, &hit, &depth)));
	}
	return (rgb3(0, 0, 0));
}
