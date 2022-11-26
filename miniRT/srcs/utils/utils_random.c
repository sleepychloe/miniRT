/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_random.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:36:49 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/26 04:04:19 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

double	random_double(void)
{
	int		fd;
	double	x;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
		return (-9999);
	read(fd, &x, sizeof(x));
	close(fd);
	x = cos(x);
	return (x);
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
