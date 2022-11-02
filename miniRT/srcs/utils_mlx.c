/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 02:53:52 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/02 03:21:22 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (x * mlx->bits_per_pixel / 8) + (y * mlx->line_length);
	*(unsigned int *)dst = color;
}

int	mlx_exit(t_scene *scene)
{
	free_scene(scene);
	exit(1);
}

int	mlx_keys(int key, t_scene *scene)
{
	if (key == ESC)
	{
		if (mlx_exit(scene))
			return (1);
	}
	return (0);
}
