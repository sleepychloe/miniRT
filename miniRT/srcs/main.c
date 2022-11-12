/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:14:37 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/12 04:36:57 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	minirt_main(char **argv)
{
	t_scene	*scene;
	t_mlx	mlx;

	scene = (t_scene *)ft_calloc(sizeof(t_scene), 2);
	if (!scene)
	{
		err_msg("Malloc error");
		exit(1);
	}
	init_struct(scene);
	parse_arg(scene, argv[1]);
	parse_map(scene, argv[1]);
	if (check_parse_error(scene))
	{
		free_scene(scene);
		exit(1);
	}
	raytracing_main(scene, &mlx);
	free_scene(scene);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		err_msg("Argument error");
		exit(1);
	}
	else
		minirt_main(argv);
	return (0);
}
