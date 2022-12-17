/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:22:21 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/17 01:52:42 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

t_rgb3	pixel_to_rgb(int color)
{
	t_rgb3	res;

	res.r = (double)((color >> 16) & 0xFF);
	res.g = (double)((color >> 8) & 0xFF);
	res.b = (double)((color >> 0) & 0xFF);
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

t_rgb3	color_average(t_rgb3 c)
{
	c.r = c.r / (NUM_SAMPLE * NUM_DEPTH);
	c.g = c.g / (NUM_SAMPLE * NUM_DEPTH);
	c.b = c.b / (NUM_SAMPLE * NUM_DEPTH);
	return (c);
}

int	color_convert_to_int(t_rgb3 rgb)
{
	int	res;

	rgb.r = color_clamp(rgb.r);
	rgb.g = color_clamp(rgb.g);
	rgb.b = color_clamp(rgb.b);
	res = (int)rgb.r * 256 * 256 + (int)rgb.g * 256 + (int)rgb.b;
	return (res);
}
