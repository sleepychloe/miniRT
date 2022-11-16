/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:04:52 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/16 22:03:04 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	check_light_hit_obj(t_data *data, double lim)
{
	int	i;

	i = 0;
	while (i < data->rt->obj)
	{
		if (interfere_sp(data, i, lim))
			return (1);
		i++;
	}
	return (0);
}

int	calculate_light(t_data *data, t_hit *hit, double *s, t_rgb3 *tc)
{
	t_ray	r;
	t_vec3	to;
	double	radius_squared;
	double	td;

	data->ray = &r;
	to = vec3_sub_vec3(hit->hit_point, data->scene->light->xyz_pos);
	radius_squared = vec3_dot_vec3(to, to);
	td = sqrt(radius_squared);
	to = vec3_unit(to);
	*tc = rgb3(data->scene->light->rgb.r * data->scene->light->brightness,
			data->scene->light->rgb.g * data->scene->light->brightness,
			data->scene->light->rgb.b * data->scene->light->brightness);
	tc->r = tc->r / (4 * PI * radius_squared);
	tc->g = tc->g / (4 * PI * radius_squared);
	tc->b = tc->b / (4 * PI * radius_squared);
	r = ray(vec3_add_vec3(hit->hit_point, vec3_mul_rn(hit->normal_vec, 1e-4)),
			vec3_mul_rn(to, -1));
	*s = vec3_dot_vec3(hit->normal_vec, vec3_mul_rn(to, -1));
	if (*s < 0)
		*s = 0;
	return (check_light_hit_obj(data, td));
}

t_rgb3	apply_light(t_data *data, t_hit *hit)
{
	t_rgb3	c;
	t_rgb3	tc;
	double	s;
	int		light;

	light = calculate_light(data, hit, &s, &tc);
	c.r = light * hit->color.r * s * 180 / PI * tc.r * 25;
	c.g = light * hit->color.g * s * 180 / PI * tc.g * 25;
	c.b = light * hit->color.b * s * 180 / PI * tc.b * 25;
	return (c);
}
