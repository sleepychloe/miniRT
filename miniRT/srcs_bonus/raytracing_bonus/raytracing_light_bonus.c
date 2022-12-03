/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_light_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:04:52 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/03 17:15:40 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

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

int	light_hit_obj(t_data *data, t_hit *hit, int i)
{
	t_ray	ray_calc_light;
	t_vec3	light_direc;
	double	distance;
	int		check_light_hit;

	data->ray = &ray_calc_light;
	light_direc = vec3_sub_vec3(hit->hit_point, data->scene->light[i]->xyz_pos);
	distance = sqrt(light_direc.x * light_direc.x
			+ light_direc.y * light_direc.y + light_direc.z * light_direc.z);
	light_direc = vec3_unit(light_direc);
	ray_calc_light = ray(hit->hit_point, vec3_mul_rn(light_direc, -1));
	check_light_hit = check_light_hit_obj(data, distance);
	return (check_light_hit);
}

double	calc_specular(double *light_intensity)
{
	if (*light_intensity > 0.93)
	{
		*light_intensity *= 1.001;
		if (*light_intensity > 0.95)
		{
			*light_intensity *= 1.01;
			if (*light_intensity > 0.97)
			{
				*light_intensity *= 1.01;
				if (*light_intensity > 0.98)
				{
					*light_intensity *= 1.01;
					if (*light_intensity > 0.999999)
						*light_intensity *= 1.02;
				}
			}
		}
	}
	return (*light_intensity);
}

t_rgb3	calc_light_color(t_data *data, t_hit *hit, t_vec3 light_direc, int i)
{
	t_rgb3	light_color;
	double	distance;
	double	light_intensity;

	light_direc = vec3_sub_vec3(hit->hit_point, data->scene->light[i]->xyz_pos);
	distance = sqrt(light_direc.x * light_direc.x
			+ light_direc.y * light_direc.y + light_direc.z * light_direc.z);
	light_direc = vec3_unit(light_direc);
	light_color = rgb3(data->scene->light[i]->rgb.r
			* data->scene->light[i]->brightness,
			data->scene->light[i]->rgb.g * data->scene->light[i]->brightness,
			data->scene->light[i]->rgb.b * data->scene->light[i]->brightness);
	light_color.r = light_color.r / (4 * PI * distance * distance);
	light_color.g = light_color.g / (4 * PI * distance * distance);
	light_color.b = light_color.b / (4 * PI * distance * distance);
	light_intensity = vec3_dot_vec3(vec3_mul_rn(hit->normal_vec, 1 + 1e-10),
			vec3_mul_rn(light_direc, -1));
	if (light_intensity < 0)
		light_intensity = 0;
	calc_specular(&light_intensity);
	return (color_mul_rn(light_color, light_intensity));
}

t_rgb3	apply_light(t_data *data, t_hit *hit)
{
	t_rgb3	color_applied_light;
	t_vec3	light_direc;
	int		light_hit;
	int		i;

	i = -1;
	color_applied_light = rgb3(0, 0, 0);
	while (++i < data->scene->n_light)
	{
		light_hit = light_hit_obj(data, hit, i);
		if (light_hit == 0)
			color_add(color_applied_light, rgb3(0, 0, 0));
		light_direc = vec3_sub_vec3(hit->hit_point,
				data->scene->light[i]->xyz_pos);
		color_applied_light.r
			+= light_hit * hit->color.r
			* calc_light_color(data, hit, light_direc, i).r * 10;
		color_applied_light.g
			+= light_hit * hit->color.g
			* calc_light_color(data, hit, light_direc, i).g * 10;
		color_applied_light.b
			+= light_hit * hit->color.b
			* calc_light_color(data, hit, light_direc, i).b * 10;
	}
	return (color_applied_light);
}
