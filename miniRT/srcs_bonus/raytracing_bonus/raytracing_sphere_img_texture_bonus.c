/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_sphere_img_texture_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 23:35:29 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/18 23:38:01 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	sphere_img_texture(t_data *data, t_hit *hit, int sp_i)
{
	double	theta;
	double	pi;
	double	uv[2];

	theta = acos(-1 * (hit->normal_vec.y));
	pi = atan2(hit->normal_vec.x, hit->normal_vec.z) + PI / 2;
	uv[0] = pi / PI * 0.5;
	uv[1] = theta / PI;
	hit->color = sphere_img_mapping(data, sp_i, uv[0], uv[1]);
	hit->normal_vec = sphere_normal_mapping(data, hit, sp_i, uv);
}
