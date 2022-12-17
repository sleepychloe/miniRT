/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_plane_img_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:12:30 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/17 05:03:46 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

t_rgb3	plane_img_mapping(t_data *data, int pl_i, double u, double v)
{
	int	u_int;
	int	v_int;
	int	color;

	v *= -1;
	u_int = (int)((u + 7) * data->obj[pl_i]->img_width);
	v_int = (int)((v + 9) * data->obj[pl_i]->img_height);
	u_int /= 70;
	v_int /= 70;
	color = xpm_img_pixel_get(data, pl_i, u_int, v_int);
	return (pixel_to_rgb(color));
}

void	plane_img(t_data *data, t_hit *hit, int pl_i)
{
	double	u;
	double	v;

	u = hit->hit_point.x;
	v = hit->hit_point.y;
	if (hit->hit_point.x > 0 && hit->hit_point.y > 0)
	{
		u -= 7;
		v -= 7;
	}
	else
	{
		hit->hit_point.x *= -1;
		hit->hit_point.y *= -1;
		u += 7;
		v += 7;
	}
	if ((hit->hit_point.x > 0 && hit->hit_point.y > 0)
		&& hit->hit_point.x < 14 && hit->hit_point.y < 14)
		hit->color = plane_img_mapping(data, pl_i, u, v);
	else
		hit->color = rgb3(255, 255, 255);
}