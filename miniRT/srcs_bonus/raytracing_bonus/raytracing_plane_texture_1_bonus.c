/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_plane_texture_1_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:36:30 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/19 02:44:48 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

t_vec3	pl_convert_normal_from_tangent_space(t_vec3 hit_n, t_vec3 tangent_n)
{
	t_vec3	u_axis;
	t_vec3	v_axis;
	t_vec3	res;

	u_axis = vec3_unit(vec3_cross_vec3(vec3(1, 0, 0), hit_n));
	v_axis = vec3_unit(vec3_cross_vec3(hit_n, u_axis));
	res.x = u_axis.x * tangent_n.x + v_axis.x * tangent_n.y
		+ hit_n.x * tangent_n.z;
	res.y = u_axis.y * tangent_n.x + v_axis.y * tangent_n.y
		+ hit_n.y * tangent_n.z;
	res.z = u_axis.z * tangent_n.x + v_axis.z * tangent_n.y
		+ hit_n.z * tangent_n.z;
	return (vec3_unit(res));
}

t_vec3	plane_normal_mapping(t_data *data, t_hit *hit, int pl_i, double *uv)
{
	int		u_int;
	int		v_int;
	int		color;
	t_vec3	normal;

	uv[1] *= -1;
	u_int = (int)((uv[0] + 7) * data->obj[pl_i]->texture_width);
	v_int = (int)((uv[1] + 9) * data->obj[pl_i]->texture_height);
	u_int /= 70;
	v_int /= 70;
	color = xpm_texture_pixel_get(data, pl_i, u_int, v_int);
	normal = rgb_to_vec(pixel_to_rgb(color));
	normal = vec3_sub_vec3(vec3_mul_rn(normal, 2), vec3(1, 1, 1));
	return (vec3_add_vec3(vec3_mul_rn(hit->normal_vec, 0.5),
			pl_convert_normal_from_tangent_space(hit->normal_vec, normal)));
}

void	plane_texture_norminette_1(t_data *data, t_hit *hit, int pl_i)
{
	if (hit->normal_vec.y == 1 || hit->normal_vec.y == -1)
		plane_texture_xz(data, hit, pl_i);
	else if (hit->normal_vec.x == 1 || hit->normal_vec.x == -1)
		plane_texture_zy(data, hit, pl_i);
	else
		plane_texture_xy(data, hit, pl_i);
}

void	plane_texture_norminette_2(t_data *data, t_hit *hit, int pl_i)
{
	if (hit->normal_vec.z == 0)
	{
		if ((hit->normal_vec.y == 1 || hit->normal_vec.y == -1))
			plane_texture_xz(data, hit, pl_i);
		else
			plane_texture_zy(data, hit, pl_i);
	}
	else
	{
		if (hit->normal_vec.x == 1 || hit->normal_vec.x == -1)
			plane_texture_zy(data, hit, pl_i);
		else if (hit->normal_vec.y == 1 || hit->normal_vec.y == -1)
			plane_texture_xz(data, hit, pl_i);
		else
			plane_texture_xy(data, hit, pl_i);
	}
}

void	plane_texture(t_data *data, t_hit *hit, int pl_i)
{
	if (sqrt(hit->normal_vec.x * hit->normal_vec.x
			+ hit->normal_vec.y * hit->normal_vec.y) == 1
		&& hit->normal_vec.x != 0 && hit->normal_vec.y != 0
		&& hit->normal_vec.x != 1 && hit->normal_vec.x != -1
		&& hit->normal_vec.y != 1 && hit->normal_vec.y != -1)
		plane_texture_xz(data, hit, pl_i);
	else if (fabs(hit->normal_vec.x) > 0.8
		&& hit->normal_vec.x != 1 && hit->normal_vec.x != -1
		&& hit->normal_vec.y != 0 && hit->normal_vec.z != 0)
		plane_texture_zy(data, hit, pl_i);
	else if (fabs(hit->normal_vec.y) > 0.8
		&& hit->normal_vec.y != 1 && hit->normal_vec.y != -1
		&& hit->normal_vec.x != 0 && hit->normal_vec.z != 0)
		plane_texture_xz(data, hit, pl_i);
	else if (fabs(hit->normal_vec.z) > 0.8
		&& hit->normal_vec.z != 1 && hit->normal_vec.z != -1
		&& hit->normal_vec.x != 0 && hit->normal_vec.y != 0)
		plane_texture_zy(data, hit, pl_i);
	else if (hit->normal_vec.x == 0)
		plane_texture_norminette_1(data, hit, pl_i);
	else
		plane_texture_norminette_2(data, hit, pl_i);
}
