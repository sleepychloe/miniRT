/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_sphere_checkerboard_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:42:48 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/09 14:45:04 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	sphere_checkerboard(t_data *data, t_hit *hit, int sp_i)
{
	double	theta;
	double	pi;
	int		u;
	int		v;

	theta = atan(hit->normal_vec.z / hit->normal_vec.x) + PI / 2;
	pi = acos((hit->normal_vec.y));
	u = theta * PI;
	v = pi * PI;
	if ((u + v) % 2 == 0)
		hit->color = data->obj[sp_i]->rgb1;
	else
		hit->color = data->obj[sp_i]->rgb2;
}
