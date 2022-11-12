/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:58:39 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/12 04:10:23 by yhwang           ###   ########.fr       */
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

int	rgb_color(t_rgb3 rgb)
{
	int	res;

	res = (int)rgb.r * 256 * 256 + (int)rgb.g * 256 + (int)rgb.b;
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

t_rgb3	color_average(t_rgb3 c, int samples_per_pixel)
{
	c.r = c.r / samples_per_pixel;
	c.b = c.b / samples_per_pixel;
	c.g = c.g / samples_per_pixel;
	c.r = color_clamp(c.r);
	c.g = color_clamp(c.g);
	c.b = color_clamp(c.b);
	return (c);
}
