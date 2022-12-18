/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_sphere_texture_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:11:59 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/18 22:36:56 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

t_vec3	sp_convert_normal_from_tangent_space(t_vec3 hit_n, t_vec3 tangent_n)
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

t_vec3	sphere_normal_mapping(t_data *data, t_hit *hit, int sp_i, double *uv)
{
	int	u_int;
	int	v_int;
	int	color;
	t_vec3	normal;

	u_int = (int)(uv[0] * data->obj[sp_i]->texture_width);
	v_int = (int)((1.0 - uv[1]) * data->obj[sp_i]->texture_height);
	u_int /= 4;
	v_int /= 4;
	color = xpm_texture_pixel_get(data, sp_i, u_int, v_int);
	normal = rgb_to_vec(pixel_to_rgb(color));
	normal = vec3_sub_vec3(vec3_mul_rn(normal, 2), vec3(1, 1, 1));
	return (vec3_add_vec3(vec3_mul_rn(hit->normal_vec, 0.5),
		sp_convert_normal_from_tangent_space(hit->normal_vec, normal)));
}

void	sphere_texture(t_data *data, t_hit *hit, int sp_i)
{
	double	theta;
	double	pi;
	double	uv[2];

	theta = acos(-1 * (hit->normal_vec.y));
	pi = atan2(hit->normal_vec.x, hit->normal_vec.z) + PI / 2;
	uv[0] = pi / PI * 0.5;
	uv[1] = theta / PI;
	hit->color = data->obj[sp_i]->rgb1;
	hit->normal_vec = sphere_normal_mapping(data, hit, sp_i, uv);
}
