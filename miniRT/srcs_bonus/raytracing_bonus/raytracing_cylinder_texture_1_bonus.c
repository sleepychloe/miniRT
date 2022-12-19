/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cylinder_texture_1_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:14:18 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/19 02:35:23 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

t_vec3	cy_convert_normal_from_tangent_space(t_vec3 hit_n, t_vec3 tangent_n)
{
	t_vec3	u_axis;
	t_vec3	v_axis;
	t_vec3	res;

	u_axis = vec3_unit(vec3_cross_vec3(vec3(0, 1, 0), hit_n));
	v_axis = vec3_unit(vec3_cross_vec3(hit_n, u_axis));
	res.x = u_axis.x * tangent_n.x + v_axis.x * tangent_n.y
		+ hit_n.x * tangent_n.z;
	res.y = u_axis.y * tangent_n.x + v_axis.y * tangent_n.y
		+ hit_n.y * tangent_n.z;
	res.z = u_axis.z * tangent_n.x + v_axis.z * tangent_n.y
		+ hit_n.z * tangent_n.z;
	return (vec3_unit(res));
}

t_vec3	cylinder_texture_mapping(t_data *data,
				t_hit *hit, int cy_i, double *theta_height)
{
	double	uv[2];
	int		u_int;
	int		v_int;
	int		color;
	t_vec3	normal;

	uv[0] = theta_height[0] / PI * 0.5;
	uv[1] = theta_height[1] / PI;
	uv[0] += 0.05;
	uv[1] -= 0.38;
	u_int = (int)(uv[0] * data->obj[cy_i]->texture_width);
	v_int = (int)((1.0 - uv[1]) * data->obj[cy_i]->texture_height);
	u_int /= 4;
	v_int /= 4;
	color = xpm_texture_pixel_get(data, cy_i, u_int, v_int);
	normal = rgb_to_vec(pixel_to_rgb(color));
	normal = vec3_sub_vec3(vec3_mul_rn(normal, 2), vec3(1, 1, 1));
	return (vec3_add_vec3(vec3_mul_rn(hit->normal_vec, 0.5),
			cy_convert_normal_from_tangent_space(hit->normal_vec, normal)));
}

t_vec3	cylinder_circle_texture_mapping(t_data *data,
				t_hit *hit, int cy_i, double *hit_point)
{
	double	uv[2];
	int		u_int;
	int		v_int;
	int		color;
	t_vec3	normal;

	uv[0] = hit_point[0];
	uv[1] = hit_point[1];
	uv[1] *= -1;
	u_int = (int)((uv[0] + 10) * data->obj[cy_i]->texture_width);
	v_int = (int)((uv[1] + 10) * data->obj[cy_i]->texture_height);
	u_int /= 70;
	v_int /= 70;
	color = xpm_texture_pixel_get(data, cy_i, u_int, v_int);
	normal = rgb_to_vec(pixel_to_rgb(color));
	normal = vec3_sub_vec3(vec3_mul_rn(normal, 2), vec3(1, 1, 1));
	return (vec3_add_vec3(vec3_mul_rn(hit->normal_vec, 0.5),
			pl_convert_normal_from_tangent_space(hit->normal_vec, normal)));
}

void	cylinder_texture_norminette(t_data *data, t_hit *hit, int cy_i)
{
	if (fabs(data->obj[cy_i]->xyz_vec.y) > 0.7
		|| (fabs(data->obj[cy_i]->xyz_vec.x) != 0
			&& fabs(data->obj[cy_i]->xyz_vec.y) > 0.5
			&& fabs(data->obj[cy_i]->xyz_vec.z) > 0.7))
		cylinder_texture_zx(data, hit, cy_i);
	else if (fabs(data->obj[cy_i]->xyz_vec.z) == 1
		|| fabs(data->obj[cy_i]->xyz_vec.z) > 0.7
		|| (fabs(data->obj[cy_i]->xyz_vec.y) > 0.6
			&& fabs(data->obj[cy_i]->xyz_vec.z) > 0.6))
		cylinder_texture_xy(data, hit, cy_i);
	else
		cylinder_texture_zy(data, hit, cy_i);
}

void	cylinder_texture(t_data *data, t_hit *hit, int cy_i)
{
	if ((data->obj[cy_i]->xyz_vec.x != 1 && data->obj[cy_i]->xyz_vec.x != -1
			&& data->obj[cy_i]->xyz_vec.y != 0))
	{
		if (fabs(data->obj[cy_i]->xyz_vec.z) == 0)
			cylinder_texture_zx(data, hit, cy_i);
		else if (fabs(data->obj[cy_i]->xyz_vec.x) == 0
			&& fabs(data->obj[cy_i]->xyz_vec.z) == 1)
			cylinder_texture_xy(data, hit, cy_i);
		else if (fabs(data->obj[cy_i]->xyz_vec.x) != 0)
			cylinder_texture_norminette(data, hit, cy_i);
		else
			cylinder_texture_zx(data, hit, cy_i);
	}
	else
		cylinder_texture_zy(data, hit, cy_i);
}
