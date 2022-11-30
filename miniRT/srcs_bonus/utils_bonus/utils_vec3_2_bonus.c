/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec3_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 03:26:45 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/30 21:54:51 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

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
