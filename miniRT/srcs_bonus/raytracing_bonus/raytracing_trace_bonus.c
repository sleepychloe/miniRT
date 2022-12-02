/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_trace_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 07:26:44 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/02 06:14:40 by yhwang           ###   ########.fr       */
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

t_rgb3	surface_lambertian(t_data *data, t_hit *hit, int *depth)
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
	diffuse = color_add(diffuse,
                                color_mul_rn(trace(data, ray_diffuse, *depth - 1), 0.1));
	return (diffuse);
}

t_vec3	calc_perfect_reflected_direc(t_hit *hit, t_vec3 reflecting_ray_direc)
{
	t_vec3	proj_normal_reflecting_direc;
	t_vec3	perfect_reflected_direc;

	proj_normal_reflecting_direc = vec3_mul_rn(hit->normal_vec,
					(vec3_dot_vec3(hit->normal_vec, reflecting_ray_direc)
					/ vec3_dot_vec3(hit->normal_vec, hit->normal_vec)));
	perfect_reflected_direc
		= vec3_mul_rn(vec3_sub_vec3(proj_normal_reflecting_direc, reflecting_ray_direc), 2);
	return (perfect_reflected_direc);
}

t_rgb3	surface_metal(t_data *data, t_hit *hit, int *depth)
{
	t_vec3	pc;
	t_vec3	perfect_reflected_direc;
	t_ray	perfect_reflected_ray;
	t_rgb3  perfect_reflection;
	double	fuzz;

	fuzz = 0;
	pc = vec3_sub_vec3(data->scene->camera->xyz_pos, hit->hit_point);
	perfect_reflected_direc = calc_perfect_reflected_direc(hit, pc);
	perfect_reflected_ray = ray(hit->hit_point, vec3_add_vec3(perfect_reflected_direc,
				vec3_mul_rn(vec3_add_vec3(random_double_xyz(), random_double_xyz()), fuzz)));
	perfect_reflection = rgb3(0, 0, 0);
	perfect_reflection = color_add(perfect_reflection,
					color_mul_rn(trace(data, perfect_reflected_ray, *depth - 1), 1.3));
	return (perfect_reflection);
}

t_rgb3	trace(t_data *data, t_ray ray_set, int depth)
{
	t_hit	hit;
	t_rgb3	ambient;
	t_rgb3	light;
	//t_rgb3	lambertian;
        t_rgb3  metal;//

	if (depth <= 0)
		return (rgb3(0, 0, 0));
	data->ray = &ray_set;
	if (hittable(data, &hit))
	{
		ambient = calc_ambient(data, &hit);
                light = apply_light(data, &hit);
		//lambertian = surface_lambertian(data, &hit, &depth);
                metal = surface_metal(data, &hit, &depth);//
		//return (color_add(color_add(ambient, light), lambertian));
		return (color_add(color_add(ambient, light), metal));//
	}
	return (rgb3(0, 0, 0));
}
