/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_sphere_img_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:17:14 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/18 00:09:53 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

t_rgb3	sphere_img_mapping(t_data *data, int sp_i, double u, double v)
{
	int	u_int;
	int	v_int;
	int	color;

	u += 0.22;
	v += 0.17;
	u_int = (int)(u * data->obj[sp_i]->img_width);
	v_int = (int)((1.0 - v) * data->obj[sp_i]->img_height);
	u_int /= 4;
	v_int /= 4;
	color = xpm_img_pixel_get(data, sp_i, u_int, v_int);
	return (pixel_to_rgb(color));
}

void	sphere_img(t_data *data, t_hit *hit, int sp_i)
{
	double	theta;
	double	pi;
	double	u;
	double	v;

	theta = acos(-1 * (hit->normal_vec.y));
	pi = atan2(hit->normal_vec.x, hit->normal_vec.z) + PI / 2;
	u = pi / PI * 0.5;
	v = theta / PI;
	hit->color = sphere_img_mapping(data, sp_i, u, v);
}
