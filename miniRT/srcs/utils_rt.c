/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 07:02:00 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/05 07:14:45 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

t_vec3	ray(t_vec3 start, t_vec3 direc, double t)
{
	t_vec3	res;

	if (t == '\0')
		return (direc);
	res = vec3_add_vec3(start, vec3_mul_rn(direc, t));
	return (res);
}

int	rgb_color(t_rgb rgb)
{
	int	res;

	res = rgb.r * 256 * 256 + rgb.g * 256 + rgb.b;
	return (res);
}

int	rgb_unit(float r, float g, float b)
{
	int	res;

	res = (r * 255) * 256 * 256 + (g * 255) * 256 + (b * 255);
	return (res);
}

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
