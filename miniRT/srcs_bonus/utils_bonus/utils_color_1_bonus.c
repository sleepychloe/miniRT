/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color_1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:58:39 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/02 01:01:36 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

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

t_rgb3	color_mul_rn(t_rgb3 c, double rn)
{
	t_rgb3	res;

	res.r = c.r * rn;
	res.g = c.g * rn;
	res.b = c.b * rn;
	return (res);
}
