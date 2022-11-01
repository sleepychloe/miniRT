/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:59:01 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/01 21:09:14 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	mlx_exit(t_scene *scene)
{
	free_scene(scene);
	exit(1);
	return (0);
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
