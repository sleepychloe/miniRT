/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_plane_img_3_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:25:39 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/17 22:30:05 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	plane_img_first_quadrant(double *hit_point_one, double *hit_point_two,
				double *u, double *v)
{
	if (*hit_point_one > 14)
		*u -= 14 * ((int)*hit_point_one / 14);
	if (*hit_point_two > 14)
		*v -= 14 * ((int)*hit_point_two / 14);
	*u -= 7;
	*v -= 7;
}

void	plane_img_second_quadrant(double *hit_point_one, double *hit_point_two,
				double *u, double *v)
{
	if (*hit_point_one < -14)
		*u += 14 * ((int)*hit_point_one / -14);
	if (*hit_point_two > 14)
		*v -= 14 * ((int)*hit_point_two / 14);
	*v -= 7;
	*hit_point_one *= -1;
	*u += 7;
}

void	plane_img_third_quadrant(double *hit_point_one, double *hit_point_two,
				double *u, double *v)
{
	if (*hit_point_one < -14)
		*u += 14 * ((int)*hit_point_one / -14);
	if (*hit_point_two < -14)
		*v += 14 * ((int)*hit_point_two / -14);
	*hit_point_one *= -1;
	*hit_point_two *= -1;
	*u += 7;
	*v += 7;
}

void	plane_img_forth_quadrant(double *hit_point_one, double *hit_point_two,
				double *u, double *v)
{
	if (*hit_point_one > 14)
		*u -= 14 * ((int)*hit_point_one / 14);
	if (*hit_point_two < -14)
		*v += 14 * ((int)*hit_point_two / -14);
	*u -= 7;
	*hit_point_two *= -1;
	*v += 7;
}
