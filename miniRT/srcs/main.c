/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:14:37 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/19 06:58:06 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	minirt_main(char **argv)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
	{
		err_msg("Malloc error");
		exit(1);
	}
	init_struct(scene);
	parse_arg(argv[1]);
	parse_map(scene, argv[1]);
	/*
	printf("\n");
	printf("-----struct ambient--------\n");
	printf("cnt\t\t: %d\n", scene->ambient->cnt);
	printf("err\t\t: %d\n", scene->ambient->err);
	printf("lighting\t: %.1f\n", scene->ambient->lighting);
	printf("r\t\t: %d\n", scene->ambient->r);
	printf("g\t\t: %d\n", scene->ambient->g);
	printf("b\t\t: %d\n", scene->ambient->b);
	printf("\n");

	printf("-----struct camera---------\n");
	printf("cnt\t\t: %d\n", scene->camera->cnt);
	printf("err\t\t: %d\n", scene->camera->err);
	printf("x_pos\t\t: %.1f\n", scene->camera->x_pos);
	printf("y_pos\t\t: %.1f\n", scene->camera->y_pos);
	printf("z_pos\t\t: %.1f\n", scene->camera->z_pos);
	printf("x_vec\t\t: %d\n", scene->camera->x_vec);
	printf("y_vec\t\t: %d\n", scene->camera->y_vec);
	printf("z_vec\t\t: %d\n", scene->camera->z_vec);
	printf("fov\t\t: %d\n", scene->camera->fov);
	printf("\n");
	printf("-----struct light----------\n");
	printf("cnt\t\t: %d\n", scene->light->cnt);
	printf("err\t\t: %d\n", scene->light->err);
	printf("x_pos\t\t: %.1f\n", scene->light->x_pos);
	printf("y_pos\t\t: %.1f\n", scene->light->y_pos);
	printf("z_pos\t\t: %.1f\n", scene->light->z_pos);
	printf("brightness\t: %.1f\n", scene->light->brightness);
	printf("r\t\t: %d\n", scene->light->r);
	printf("g\t\t: %d\n", scene->light->g);
	printf("b\t\t: %d\n", scene->light->b);
	printf("\n");
	printf("-----struct sphere1--------\n");
	printf("cnt\t\t: %d\n", scene->sphere[0]->cnt);
	printf("x_pos\t\t: %.1f\n", scene->sphere[0]->x_pos);
	printf("y_pos\t\t: %.1f\n", scene->sphere[0]->y_pos);
	printf("z_pos\t\t: %.1f\n", scene->sphere[0]->z_pos);
	printf("diameter\t: %1.f\n", scene->sphere[0]->diameter);
	printf("r\t\t: %d\n", scene->sphere[0]->r);
	printf("g\t\t: %d\n", scene->sphere[0]->g);
	printf("b\t\t: %d\n", scene->sphere[0]->b);
	printf("\n");
	printf("-----struct plane1---------\n");
	printf("cnt\t\t: %d\n", scene->plane[0]->cnt);
	printf("x_pos\t\t: %.1f\n", scene->plane[0]->x_pos);
	printf("y_pos\t\t: %.1f\n", scene->plane[0]->y_pos);
	printf("z_pos\t\t: %.1f\n", scene->plane[0]->z_pos);
	printf("x_vec\t\t: %d\n", scene->plane[0]->x_vec);
	printf("y_vec\t\t: %d\n", scene->plane[0]->y_vec);
	printf("z_vec\t\t: %d\n", scene->plane[0]->z_vec);
	printf("r\t\t: %d\n", scene->plane[0]->r);
	printf("g\t\t: %d\n", scene->plane[0]->g);
	printf("b\t\t: %d\n", scene->plane[0]->b);
	printf("\n");
	printf("-----struct cylinder1-----\n");
	printf("cnt\t\t: %d\n", scene->cylinder[0]->cnt);
	printf("x_pos\t\t: %.1f\n", scene->cylinder[0]->x_pos);
	printf("y_pos\t\t: %.1f\n", scene->cylinder[0]->y_pos);
	printf("z_pos\t\t: %.1f\n", scene->cylinder[0]->z_pos);
	printf("x_vec\t\t: %d\n", scene->cylinder[0]->x_vec);
	printf("y_vec\t\t: %d\n", scene->cylinder[0]->y_vec);
	printf("z_vec\t\t: %d\n", scene->cylinder[0]->z_vec);
	printf("diameter\t: %.1f\n", scene->cylinder[0]->diameter);
	printf("height\t\t: %.1f\n", scene->cylinder[0]->height);
	printf("r\t\t: %d\n", scene->cylinder[0]->r);
	printf("g\t\t: %d\n", scene->cylinder[0]->g);
	printf("b\t\t: %d\n", scene->cylinder[0]->b);
	printf("\n");
	*/
	if (check_parse_error(scene))
	{
		ft_free_struct(scene);
		exit(1);
	}
	ft_free_struct(scene);
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
	{
		minirt_main(argv);
		printf("\n\nOK\n\n");
	}
	return (0);
}
