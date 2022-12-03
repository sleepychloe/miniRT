/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:14:37 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/03 07:29:14 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	minirt_main_norminette(t_scene *scene, t_scene *keep_scene)
{
	if (!keep_scene)
	{
		err_msg("Malloc error");
		free_scene(scene);
		exit(1);
	}
}

int	minirt_main(char **argv)
{
	t_scene	*scene;
	t_scene	*keep_scene;
	t_mlx	mlx;

	scene = (t_scene *)ft_calloc(sizeof(t_scene), 2);
	if (!scene)
	{
		err_msg("Malloc error");
		exit(1);
	}
	init_struct_scene(scene);
	parse_arg(scene, argv[1]);
	parse_map(scene, argv[1]);
	if (check_parse_error(scene))
	{
		free_scene(scene);
		exit(1);
	}
	keep_scene = (t_scene *)ft_calloc(sizeof(t_scene), 2);
	minirt_main_norminette(scene, keep_scene);
	init_struct_keep_scene(keep_scene, scene);
	raytracing_main(scene, keep_scene, &mlx);
	free_scene(scene);
	free_scene(keep_scene);
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
