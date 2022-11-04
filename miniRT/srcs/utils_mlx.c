/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 02:53:52 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/02 12:24:43 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (x * mlx->bits_per_pixel / 8) + (y * mlx->line_length);
	*(unsigned int *)dst = color;
}

int	mlx_exit(t_mlx *mlx)
{
        mlx_destroy_window(mlx->mlx_ptr, mlx->win);
	exit (0);
}

int	mlx_keys(int key, t_mlx *mlx)
{
	if (key == ESC)
                mlx_exit(mlx);
	return (0);
}
