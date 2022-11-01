/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:00:26 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/01 21:00:44 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	init_window(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!(mlx->mlx_ptr))
		return (1);
	mlx->win = mlx_new_window(mlx->mlx_ptr, 500, 500, "miniRT");
	if ((!mlx->win))
		return (1);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, 500, 500);
	if (!(mlx->img_ptr))
		return (1);
	mlx->addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	if (!(mlx->addr))
		return (1);
	return (0);
}

int	raytracing_main(t_scene *scene)
{
	t_mlx	mlx;

        if (init_window(&mlx))
	{
		err_msg("mlx init error");
		return(1);
	}
	mlx_hook(mlx.win, 17, 2, mlx_exit, (void *)scene);
	mlx_key_hook(mlx.win, mlx_keys, (void *)scene);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
