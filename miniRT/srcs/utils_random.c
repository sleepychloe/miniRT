/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_random.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:36:49 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/11 18:37:11 by yhwang           ###   ########.fr       */
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
	int		i;

	i = 100000000;
	while (0 < i)
	{
		res.x = random_double();
		res.y = random_double();
		res.z = sqrt(1 - res.x * res.x - res.y * res.y);
		if (res.x * res.x + res.y * res.y + res.z * res.z == 1)
			return (res);
		i--;
	}
	return (vec3(0, 0, 0));
}
