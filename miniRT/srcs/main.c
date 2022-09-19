/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sucho <sucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 00:47:37 by sucho             #+#    #+#             */
/*   Updated: 2022/09/15 16:43:21 by sucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int main(int argc, char *argv[])
{
	t_scene	*scene;

	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		print_error_and_exit("Malloc error");
	if (argc != 2 || !argv[1])
		print_error_and_exit("Argument error");
	if (!check_file_extention(argv[1]))
		print_error_and_exit("File extension error");
	else
	{
		int	fd;
		char	*line;

		line = NULL;
		fd = open(argv[1], O_RDONLY);
		if (!fd)
			print_error_and_exit("File open error");
		while (1)
		{
			// 구조체 초기화 할 부분 (9/16에 할것 건드리지마셈)
			char *line_trim;
			line = get_next_line(fd);
			if (line == NULL )
				break;
			if (line[ft_strlen(line) - 1] == '\n')
				line_trim = ft_substr(line, 0, ft_strlen(line) - 1);
			else
				line_trim = line;
			if (ft_strncmp(line_trim, "A", 1) == 0)
				parse_ambient(scene, line_trim);
			else if (ft_strncmp(line_trim, "C ", 1) == 0)
				parse_camera(scene, line_trim);
			else if (ft_strncmp(line_trim, "L", 1) == 0)
				parse_light(scene, line_trim);
			else if (ft_strncmp(line_trim, "sp", 2) == 0)
				parse_sphere(scene, line_trim);
			else if (ft_strncmp(line_trim, "pl", 2) == 0)
				parse_plane(scene, line_trim);
			else if (ft_strncmp(line_trim, "cy", 2) == 0)
				parse_cylinder(scene, line_trim);

			// 4. A, C, L인 경우 단 한번만 들어올 수 있음 <- 
			// 	값이 저장 되어 있는 상태인데 값을 한번 더 담으려고 하면 에러 처리 

			// 5.  동적 할당 전부다 프리 
		}
	}
	printf("\n");
	printf("-----struct ambient--------\n");
	printf("ratio\t\t: %s\n", scene->ambient->ratio);
	printf("r\t\t: %d\n", scene->ambient->r);
	printf("g\t\t: %d\n", scene->ambient->g);
	printf("b\t\t: %d\n", scene->ambient->b);
	printf("\n");
	printf("-----struct camera---------\n");
	printf("x_coord\t\t: %s\n", scene->camera->x_coord);
	printf("y_coord\t\t: %s\n", scene->camera->y_coord);
	printf("z_coord\t\t: %s\n", scene->camera->z_coord);
	printf("x_vec\t\t: %d\n", scene->camera->x_vec);
	printf("y_vec\t\t: %d\n", scene->camera->y_vec);
	printf("z_vec\t\t: %d\n", scene->camera->z_vec);
	printf("fov\t\t: %d\n", scene->camera->fov);
	printf("\n");
	printf("-----struct light----------\n");
	printf("x_coord\t\t: %s\n", scene->light->x_coord);
	printf("y_coord\t\t: %s\n", scene->light->y_coord);
	printf("z_coord\t\t: %s\n", scene->light->z_coord);
	printf("ratio\t\t: %s\n", scene->light->ratio);
	printf("r\t\t: %d\n", scene->light->r);
	printf("g\t\t: %d\n", scene->light->g);
	printf("b\t\t: %d\n", scene->light->b);
	printf("\n");
	printf("-----struct sphere1--------\n");
	printf("x_coord\t\t: %s\n", scene->sphere[0]->x_coord);
	printf("y_coord\t\t: %s\n", scene->sphere[0]->y_coord);
	printf("z_coord\t\t: %s\n", scene->sphere[0]->z_coord);
	printf("diameter\t: %s\n", scene->sphere[0]->diameter);
	printf("r\t\t: %d\n", scene->sphere[0]->r);
	printf("g\t\t: %d\n", scene->sphere[0]->g);
	printf("b\t\t: %d\n", scene->sphere[0]->b);
	printf("\n");
	printf("-----struct sphere2--------\n");
	printf("x_coord\t\t: %s\n", scene->sphere[1]->x_coord);
	printf("y_coord\t\t: %s\n", scene->sphere[1]->y_coord);
	printf("z_coord\t\t: %s\n", scene->sphere[1]->z_coord);
	printf("diameter\t: %s\n", scene->sphere[1]->diameter);
	printf("r\t\t: %d\n", scene->sphere[1]->r);
	printf("g\t\t: %d\n", scene->sphere[1]->g);
	printf("b\t\t: %d\n", scene->sphere[1]->b);
	printf("\n");
	printf("-----struct plane1---------\n");
	printf("x_coord\t\t: %s\n", scene->plane[0]->x_coord);
	printf("y_coord\t\t: %s\n", scene->plane[0]->y_coord);
	printf("z_coord\t\t: %s\n", scene->plane[0]->z_coord);
	printf("x_vec\t\t: %d\n", scene->plane[0]->x_vec);
	printf("y_vec\t\t: %d\n", scene->plane[0]->y_vec);
	printf("z_vec\t\t: %d\n", scene->plane[0]->z_vec);
	printf("r\t\t: %d\n", scene->plane[0]->r);
	printf("g\t\t: %d\n", scene->plane[0]->g);
	printf("b\t\t: %d\n", scene->plane[0]->b);
	printf("\n");
	printf("----struct plane2---------\n");
	printf("x_coord\t\t: %s\n", scene->plane[1]->x_coord);
	printf("y_coord\t\t: %s\n", scene->plane[1]->y_coord);
	printf("z_coord\t\t: %s\n", scene->plane[1]->z_coord);
	printf("x_vec\t\t: %d\n", scene->plane[1]->x_vec);
	printf("y_vec\t\t: %d\n", scene->plane[1]->y_vec);
	printf("z_vec\t\t: %d\n", scene->plane[1]->z_vec);
	printf("r\t\t: %d\n", scene->plane[1]->r);
	printf("g\t\t: %d\n", scene->plane[1]->g);
	printf("b\t\t: %d\n", scene->plane[1]->b);
	printf("\n");
	printf("-----struct cylinder1-----\n");
	printf("x_coord\t\t: %s\n", scene->cylinder[0]->x_coord);
	printf("y_coord\t\t: %s\n", scene->cylinder[0]->y_coord);
	printf("z_coord\t\t: %s\n", scene->cylinder[0]->z_coord);
	printf("x_vec\t\t: %d\n", scene->cylinder[0]->x_vec);
	printf("y_vec\t\t: %d\n", scene->cylinder[0]->y_vec);
	printf("z_vec\t\t: %d\n", scene->cylinder[0]->z_vec);
	printf("diameter\t: %s\n", scene->cylinder[0]->diameter);
	printf("height\t\t: %s\n", scene->cylinder[0]->height);
	printf("r\t\t: %d\n", scene->cylinder[0]->r);
	printf("g\t\t: %d\n", scene->cylinder[0]->g);
	printf("b\t\t: %d\n", scene->cylinder[0]->b);
	printf("\n");
	printf("-----struct cylinder2-----\n");
	printf("x_coord\t\t: %s\n", scene->cylinder[1]->x_coord);
	printf("y_coord\t\t: %s\n", scene->cylinder[1]->y_coord);
	printf("z_coord\t\t: %s\n", scene->cylinder[1]->z_coord);
	printf("x_vec\t\t: %d\n", scene->cylinder[1]->x_vec);
	printf("y_vec\t\t: %d\n", scene->cylinder[1]->y_vec);
	printf("z_vec\t\t: %d\n", scene->cylinder[1]->z_vec);
	printf("diameter\t: %s\n", scene->cylinder[1]->diameter);
	printf("height\t\t: %s\n", scene->cylinder[1]->height);
	printf("r\t\t: %d\n", scene->cylinder[1]->r);
	printf("g\t\t: %d\n", scene->cylinder[1]->g);
	printf("b\t\t: %d\n", scene->cylinder[1]->b);
	printf("\n");
	
	exit(0);
}
