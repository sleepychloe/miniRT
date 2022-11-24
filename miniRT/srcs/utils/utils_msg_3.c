/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_msg_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 03:33:31 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/20 12:48:14 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	print_info_5(t_data *data, t_scene *scene, int flag)
{
	if (flag == 9)
		printf(" position   ║ y ║ %s%f%s\t╠",
			R, scene->sphere[data->sp]->xyz_pos.y, B);
	else
		printf(" position   ║ y ║ %f\t╠", scene->sphere[data->sp]->xyz_pos.y);
	printf("════════════╬═══╬══════════════╬");
	printf("════════════╬═══╬══════════════╣\n");
	if (flag == 4)
		printf("║            ║ x ║ %s%f%s\t║", R, scene->camera->xyz_vec.x, B);
	else
		printf("║            ║ x ║  %f\t║", scene->camera->xyz_vec.x);
	if (flag == 7)
		printf("            ║ z ║ %s%f%s\t║", R, scene->light->xyz_pos.z, B);
	else
		printf("            ║ z ║ %f\t║", scene->light->xyz_pos.z);
	if (flag == 10)
		printf("            ║ z ║ %s%f%s\t║",
			R, scene->sphere[data->sp]->xyz_pos.z, B);
	else
		printf("            ║ z ║ %f\t║", scene->sphere[data->sp]->xyz_pos.z);
	if (flag == 14)
		printf("            ║ x ║ %s%f%s\t║",
			R, scene->plane[data->pl]->xyz_vec.x, B);
	else
		printf("            ║ x ║ %f\t║", scene->plane[data->pl]->xyz_vec.x);
}

void	print_info_6(t_data *data, t_scene *scene, int flag)
{
	if (flag == 18)
		printf("            ║ x ║ %s%f%s\t║\n",
			R, scene->cylinder[data->cy]->xyz_vec.x, B);
	else
		printf("            ║ x ║ %f\t║\n", scene->cylinder[data->cy]->xyz_vec.x);
	if (flag == 4)
		printf("║ normal vec ║ y ║ %s%f%s\t║", R, scene->camera->xyz_vec.y, B);
	else
		printf("║ normal vec ║ y ║  %f\t║", scene->camera->xyz_vec.y);
	printf("            ║   ║              ║");
	printf("            ║   ║              ║");
	if (flag == 14)
		printf(" normal vec ║ y ║ %s%f%s\t║",
			R, scene->plane[data->pl]->xyz_vec.y, B);
	else
		printf(" normal vec ║ y ║ %f\t║", scene->plane[data->pl]->xyz_vec.y);
	if (flag == 18)
		printf(" normal vec ║ y ║ %s%f%s\t║\n",
			R, scene->cylinder[data->cy]->xyz_vec.y, B);
	else
		printf(" normal vec ║ y ║ %f\t║\n", scene->cylinder[data->cy]->xyz_vec.y);
	if (flag == 4)
		printf("║            ║ z ║ %s%f%s\t║", R, scene->camera->xyz_vec.z, B);
	else
		printf("║            ║ z ║  %f\t║", scene->camera->xyz_vec.z);
}

void	print_info_7(t_data *data, t_scene *scene, int flag)
{
	printf("            ║   ║              ║");
	printf("            ║   ║              ║");
	if (flag == 14)
		printf("            ║ z ║ %s%f%s\t║",
			R, scene->plane[data->pl]->xyz_vec.z, B);
	else
		printf("            ║ z ║ %f\t║", scene->plane[data->pl]->xyz_vec.z);
	if (flag == 18)
		printf("            ║ z ║ %s%f%s\t║\n",
			R, scene->cylinder[data->cy]->xyz_vec.z, B);
	else
		printf("            ║ z ║ %f\t║\n", scene->cylinder[data->cy]->xyz_vec.z);
	printf("╚════════════╩═══╩══════════════╩");
	printf("════════════╩═══╩══════════════╩");
	printf("════════════╩═══╩══════════════╩");
	printf("════════════╩═══╩══════════════╩");
	printf("════════════╩═══╩══════════════╝\n");
}
