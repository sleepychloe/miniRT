/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_random_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:36:49 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/30 21:54:43 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

double	random_double(void)
{
	static int	a;
	double		res;

	a = (a * 123456789123 + 123456) & 0x7fffffff;
	res = ((double)a / (double)0x80000000);
	return (res);
}

t_vec3	random_double_xyz(void)
{
	t_vec3	res;

	while (1)
	{
		res.x = random_double();
		res.y = random_double();
		if (res.x * res.x + res.y * res.y >= 1)
			continue ;
		res.z = sqrt(1 - res.x * res.x - res.y * res.y);
		if (res.x * res.x + res.y * res.y + res.z * res.z == 1)
			break ;
	}
	return (res);
}
