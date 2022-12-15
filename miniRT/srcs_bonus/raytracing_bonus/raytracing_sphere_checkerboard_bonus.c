/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_sphere_checkerboard_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:42:48 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/15 08:12:29 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	sphere_checkerboard(t_data *data, t_hit *hit, int sp_i)
{
	double	theta;
	double	pi;
	int		u;
	int		v;

	theta = acos(-1 * (hit->normal_vec.y));
	pi = atan2(hit->normal_vec.x, hit->normal_vec.z) + PI / 2;
	u = pi / PI * 10;
	v = theta / PI * 10;
	if ((u + v) % 2 == 0)
		hit->color = data->obj[sp_i]->rgb1;
	else
		hit->color = data->obj[sp_i]->rgb2;
}
