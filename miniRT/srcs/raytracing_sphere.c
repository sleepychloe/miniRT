/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_sphere.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:56:04 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/14 00:06:14 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	check_sphere(t_scene *scene, t_ray ray_set, double *t, int sp_i, double lim)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;

	oc = vec3_sub_vec3(ray_set.point, scene->sphere[sp_i]->xyz_pos);
	a = vec3_dot_vec3(ray_set.direc, ray_set.direc);
	b = vec3_dot_vec3(oc, ray_set.direc);
	c = vec3_dot_vec3(oc, oc)
		- (((scene->sphere[sp_i]->diameter) / 2)
			* ((scene->sphere[sp_i]->diameter) / 2));
	if (b * b - a * c < 0)
		return (1);
	*t = (-1 * b - sqrt(b * b - a * c)) / a;
	if (*t < 0.00001 || lim < *t)
	{
		*t = (-1 * b + sqrt(b * b - a * c)) / a;
		if (*t < 0.00001 || lim < *t)
			return (1);
	}
	return (0);
}

int	hit_sphere(t_scene *scene, t_ray ray_set, t_hit *hit, int sp_i, double lim)
{
	double	t;

	if (check_sphere(scene, ray_set, &t, sp_i, lim))
		return (1);
	set_hit_point(ray_set, hit, t);
	hit->normal_vec = vec3_unit(vec3_sub_vec3(hit->hit_point,
				scene->sphere[sp_i]->xyz_pos));
	set_hit_normal_direc(ray_set, hit);
	hit->color = scene->sphere[sp_i]->rgb;
	return (0);
}

int	interfere_sp(t_scene *scene, t_ray r, int sp_i, double lim)
{
	double		t;

	if (!check_sphere(scene, r, &t, sp_i, lim))
		return (0);
	return (1);
}
