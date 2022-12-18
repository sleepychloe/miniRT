/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec3_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 03:26:45 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/18 21:27:15 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

t_vec3	vec3_cross_vec3(t_vec3 v1, t_vec3 v2)
{
	t_vec3	res;

	res.x = v1.y * v2.z - v1.z * v2.y;
	res.y = v1.z * v2.x - v1.x * v2.z;
	res.z = v1.x * v2.y - v1.y * v2.x;
	return (res);
}

double	vec3_length(t_vec3 v)
{
	double	res;

	res = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (res);
}

t_vec3	vec3_unit(t_vec3 v)
{
	t_vec3	res;

	res = vec3_mul_rn(v, (1 / vec3_length(v)));
	return (res);
}
