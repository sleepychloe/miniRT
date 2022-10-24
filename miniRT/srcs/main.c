/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:14:37 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/24 15:18:06 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	minirt_main(char **argv)
{
	t_scene	*scene;

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
		ft_free_struct(scene);
		exit(1);
	}
	ft_free_struct(scene);
	printf("ok\n");
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
