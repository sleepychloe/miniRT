/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 02:53:52 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/14 13:18:10 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

int	mlx_init_window(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!(mlx->mlx_ptr))
		return (1);
	mlx->win = mlx_new_window(mlx->mlx_ptr,
			WIN_W, WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H, "miniRT");
	if ((!mlx->win))
		return (1);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_W,
			WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H);
	if (!(mlx->img_ptr))
		return (1);
	mlx->addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	if (!(mlx->addr))
		return (1);
	return (0);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (x * mlx->bits_per_pixel / 8) + (y * mlx->line_length);
	*(unsigned int *)dst = color;
}

int	mlx_exit(t_data *data)
{
	mlx_clear_window(data->mlx->mlx_ptr, data->mlx->win);
	mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win);
	free_obj(data->obj);
	free_scene(data->keep_scene);
	free_scene(data->scene);
	exit (0);
}

void	mlx_move_rotate_obj(int key, t_data *data)
{
	if (key == KEY_LEFT_SHIFT || key == KEY_Z || key == KEY_X
		|| key == KEY_C || key == KEY_V || key == KEY_B || key == KEY_N)
		mlx_move_sphere(key, data, data->sp);
	if (key == KEY_CAPSLOCK || key == KEY_A || key == KEY_S
		|| key == KEY_D || key == KEY_F || key == KEY_G || key == KEY_H)
		mlx_move_plane(key, data, data->pl);
	if (key == KEY_J || key == KEY_K || key == KEY_L)
		mlx_rotate_plane(key, data, data->pl);
	if (key == KEY_TAB || key == KEY_Q || key == KEY_W
		|| key == KEY_E || key == KEY_R || key == KEY_T || key == KEY_Y)
		mlx_move_cylinder(key, data, data->cy);
	if (key == KEY_U || key == KEY_I || key == KEY_O)
		mlx_rotate_cylinder(key, data, data->cy);
	if (key == KEY_GRAVE_ACCENT || key == KEY_1 || key == KEY_2
		|| key == KEY_3 || key == KEY_4 || key == KEY_5 || key == KEY_6)
		mlx_move_cone(key, data, data->co);
	if (key == KEY_7 || key == KEY_8 || key == KEY_9)
		mlx_rotate_cone(key, data, data->co);
}

int	mlx_keys(int key, t_data *data)
{
	if (key == KEY_ESC)
		mlx_exit(data);
	if (key == KEY_F1 || key == KEY_F2 || key == KEY_F3 || key == KEY_F4
		|| key == KEY_F5 || key == KEY_F6 || key == KEY_UP || key == KEY_DOWN)
		mlx_move_camera(key, data);
	if (key == KEY_F7 || key == KEY_F8 || key == KEY_F9)
		mlx_rotate_camera(key, data);
	if (key == KEY_LEFT_CTRL || key == KEY_POINT || key == KEY_SLASH
		|| key == KEY_SEMICOLON || key == KEY_SINGLE_QUOTE
		|| key == KEY_SQUARE_BRACKET_LEFT || key == KEY_SQUARE_BRACKET_RIGHT)
		mlx_move_light(key, data, data->l);
	if (key == KEY_LEFT_SHIFT || key == KEY_Z || key == KEY_X
		|| key == KEY_C || key == KEY_V || key == KEY_B || key == KEY_N
		|| key == KEY_CAPSLOCK || key == KEY_A || key == KEY_S
		|| key == KEY_D || key == KEY_F || key == KEY_G || key == KEY_H
		|| key == KEY_J || key == KEY_K || key == KEY_L
		|| key == KEY_TAB || key == KEY_Q || key == KEY_W
		|| key == KEY_E || key == KEY_R || key == KEY_T || key == KEY_Y
		|| key == KEY_U || key == KEY_I || key == KEY_O
		|| key == KEY_GRAVE_ACCENT || key == KEY_1 || key == KEY_2
		|| key == KEY_3 || key == KEY_4 || key == KEY_5 || key == KEY_6
		|| key == KEY_7 || key == KEY_8 || key == KEY_9)
		mlx_move_rotate_obj(key, data);
	return (0);
}
