/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:58:39 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/13 19:16:18 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

t_rgb3	rgb3(double r, double g, double b)
{
	t_rgb3	res;

	res.r = r;
	res.g = g;
	res.b = b;
	return (res);
}

t_rgb3	color_add(t_rgb3 c1, t_rgb3 c2)
{
	t_rgb3	res;

	res.r = c1.r + c2.r;
	res.g = c1.g + c2.g;
	res.b = c1.b + c2.b;
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

t_rgb3	color_average(t_rgb3 c, int samples_per_pixel)
{
	c.r = c.r / samples_per_pixel;
	c.g = c.g / samples_per_pixel;
	c.b = c.b / samples_per_pixel;
	/*c.r = sqrt(c.r / (samples_per_pixel * NUM_DEPTH));
	c.g = sqrt(c.g / (samples_per_pixel * NUM_DEPTH));
	c.b = sqrt(c.b / (samples_per_pixel * NUM_DEPTH));*/
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
