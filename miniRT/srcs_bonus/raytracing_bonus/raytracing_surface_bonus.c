/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_surface_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 07:25:13 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/06 14:12:32 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

t_rgb3	surface_lambertian(t_data *data, t_hit *hit, int *depth)
{
	t_vec3	target;
	t_ray	ray_diffuse;
	t_rgb3	diffuse;

	target = vec3_add_vec3(hit->hit_point,
				vec3_add_vec3(vec3_mul_rn(hit->normal_vec, 1e-10),
			random_double_xyz()));
	if (vec3_dot_vec3(target, hit->normal_vec) < 0)
		target = vec3_mul_rn(target, -1);
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
		= vec3_mul_rn(vec3_sub_vec3(proj_normal_reflecting_direc,
				reflecting_ray_direc), 2);
	return (perfect_reflected_direc);
}

t_rgb3	surface_metal(t_data *data, t_hit *hit, int *depth)
{
	t_vec3	pc;
	t_vec3	perfect_reflected_direc;
	t_ray	perfect_reflected_ray;
	t_rgb3	perfect_reflection;

	pc = vec3_sub_vec3(data->scene->camera->xyz_pos, hit->hit_point);
	perfect_reflected_direc
		= calc_perfect_reflected_direc(hit, pc);
	perfect_reflected_ray
		= ray(hit->hit_point, vec3_add_vec3(perfect_reflected_direc,
				vec3_mul_rn(vec3_add_vec3(random_double_xyz(),
						random_double_xyz()), hit->fuzz)));
	perfect_reflection = rgb3(0, 0, 0);
	perfect_reflection = color_add(perfect_reflection,
			color_mul_rn(trace(data, perfect_reflected_ray, *depth - 1), 1.3));
	return (perfect_reflection);
}
