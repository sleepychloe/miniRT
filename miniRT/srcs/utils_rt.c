/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 07:02:00 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/12 03:03:55 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

t_ray	ray(t_vec3 point, t_vec3 direc)
{
	t_ray	res;

	res.point = point;
	res.direc = direc;
	return (res);
}

double	color_clamp(double c)
{
	if (c < 0.0)
		c = 0.0;
	if (255.0 < c)
		c = 255.0;
	return (c);
}
