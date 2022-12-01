/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:04:52 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/01 07:45:13 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	check_light_hit_obj(t_data *data, double distance)
{
	int	i;

	i = 0;
	while (i < data->n_obj + data->scene->n_plane + data->scene->n_plane)
	{
		if ((!light_hit_sp(data, i, distance)))
			return (0);
		if (!(light_hit_pl(data, i, distance)))
			return (0);
		if (!(light_hit_cy(data, i, distance)))
			return (0);
		i++;
	}
	return (1);
}

int	calculate_light(t_data *data, t_hit *hit,
			double *light_intensity, t_rgb3 *light_color)
{
	t_ray	ray_calc_light;
	t_vec3	light_direc;
	double	distance;
	int		check_light_hit;

	data->ray = &ray_calc_light;
	light_direc = vec3_sub_vec3(hit->hit_point, data->scene->light->xyz_pos);
	distance = sqrt(light_direc.x * light_direc.x
			+ light_direc.y * light_direc.y + light_direc.z * light_direc.z);
	light_direc = vec3_unit(light_direc);
	*light_color = rgb3(data->scene->light->rgb.r
			* data->scene->light->brightness,
			data->scene->light->rgb.g * data->scene->light->brightness,
			data->scene->light->rgb.b * data->scene->light->brightness);
	light_color->r = light_color->r / (4 * PI * distance * distance);
	light_color->g = light_color->g / (4 * PI * distance * distance);
	light_color->b = light_color->b / (4 * PI * distance * distance);
	ray_calc_light = ray(hit->hit_point, vec3_mul_rn(light_direc, -1));
	*light_intensity = vec3_dot_vec3(vec3_mul_rn(hit->normal_vec, 1 + 1e-10),
			vec3_mul_rn(light_direc, -1));
	if (*light_intensity < 0)
		*light_intensity = 0;
	check_light_hit = check_light_hit_obj(data, distance);
	return (check_light_hit);
}

t_rgb3	apply_light(t_data *data, t_hit *hit)
{
	t_rgb3	color_applied_light;
	t_rgb3	light_color;
	double	light_intensity;
	int		light_hit;

	light_hit = calculate_light(data, hit, &light_intensity, &light_color);
	if (light_hit == 0)
		return (rgb3(0, 0, 0));
	color_applied_light.r
		= light_hit * hit->color.r * light_intensity * light_color.r * 10;
	color_applied_light.g
		= light_hit * hit->color.g * light_intensity * light_color.g * 10;
	color_applied_light.b
		= light_hit * hit->color.b * light_intensity * light_color.b * 10;
	return (color_applied_light);
}
