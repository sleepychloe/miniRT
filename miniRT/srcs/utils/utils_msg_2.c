/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_msg_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 05:09:26 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/16 00:03:19 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	print_1(t_data *data, t_scene *scene, int flag)
{
	if (flag == 1)
		printf("║            ║ x ║ %s%f%s\t║", R, scene->camera->xyz_pos.x, B);
	else
		printf("║            ║ x ║ %f\t║", scene->camera->xyz_pos.x);
	printf("            ║   ║              ║");
	printf("            ║   ║              ║");
	if (flag == 11)
		printf("            ║ x ║ %s%f%s\t║", R, scene->plane[data->pl]->xyz_pos.x, B);
	else
		printf("            ║ x ║ %f\t║", scene->plane[data->pl]->xyz_pos.x);
	if (flag == 15)
		printf("            ║ x ║ %s%f%s\t║\n",
			R, scene->cylinder[data->cy]->xyz_pos.x, B);
	else
		printf("            ║ x ║ %f\t║\n", scene->cylinder[data->cy]->xyz_pos.x);
	if (flag == 2)
		printf("║ position   ║ y ║ %s%f%s\t║", R, scene->camera->xyz_pos.y, B);
	else
		printf("║ position   ║ y ║ %f\t║", scene->camera->xyz_pos.y);
	printf("            ║   ║              ║");
	printf("            ║   ║              ║");
}

void	print_2(t_data *data, t_scene *scene, int flag)
{
	if (flag == 12)
		printf(" position   ║ y ║ %s%f%s\t║", R, scene->plane[data->pl]->xyz_pos.y, B);
	else
		printf(" position   ║ y ║ %f\t║", scene->plane[data->pl]->xyz_pos.y);
	if (flag == 16)
		printf(" position   ║ y ║ %s%f%s\t║\n",
			R, scene->cylinder[data->cy]->xyz_pos.y, B);
	else
		printf(" position   ║ y ║ %f\t║\n", scene->cylinder[data->cy]->xyz_pos.y);
	if (flag == 3)
		printf("║            ║ z ║ %s%f%s\t║", R, scene->camera->xyz_pos.z, B);
	else
		printf("║            ║ z ║ %f\t║", scene->camera->xyz_pos.z);
	if (flag == 5)
		printf("            ║ x ║ %s%f%s\t║", R, scene->light->xyz_pos.x, B);
	else
		printf("            ║ x ║ %f\t║", scene->light->xyz_pos.x);
	if (flag == 8)
		printf("            ║ x ║ %s%f%s\t║", R, scene->sphere[data->sp]->xyz_pos.x, B);
	else
		printf("            ║ x ║ %f\t║", scene->sphere[data->sp]->xyz_pos.x);
	if (flag == 13)
		printf("            ║ z ║ %s%f%s\t║", R, scene->plane[data->pl]->xyz_pos.z, B);
	else
		printf("            ║ z ║ %f\t║", scene->plane[data->pl]->xyz_pos.z);
}

void	print_3(t_data *data, t_scene *scene, int flag)
{
	if (flag == 17)
		printf("            ║ z ║ %s%f%s\t║\n",
			R, scene->cylinder[data->cy]->xyz_pos.z, B);
	else
		printf("            ║ z ║ %f\t║\n", scene->cylinder[data->cy]->xyz_pos.z);
	printf("╠════════════╬═══╬══════════════╣");
	if (flag == 6)
		printf(" position   ║ y ║ %s%f%s\t║", R, scene->light->xyz_pos.y, B);
	else
		printf(" position   ║ y ║ %f\t║", scene->light->xyz_pos.y);
	if (flag == 9)
		printf(" position   ║ y ║ %s%f%s\t╠", R, scene->sphere[data->sp]->xyz_pos.y, B);
	else
		printf(" position   ║ y ║ %f\t╠", scene->sphere[data->sp]->xyz_pos.y);
	printf("════════════╬═══╬══════════════╬");
	printf("════════════╬═══╬══════════════╣\n");
	if (flag == 4)
		printf("║            ║ x ║  %s%f%s\t║", R, scene->camera->xyz_vec.x, B);
	else
		printf("║            ║ x ║  %f\t║", scene->camera->xyz_vec.x);
	if (flag == 7)
		printf("            ║ z ║ %s%f%s\t║", R, scene->light->xyz_pos.z, B);
	else
		printf("            ║ z ║ %f\t║", scene->light->xyz_pos.z);
}

void	print_4(t_data *data, t_scene *scene, int flag)
{
	if (flag == 10)
		printf("            ║ z ║ %s%f%s\t║", R, scene->sphere[data->sp]->xyz_pos.z, B);
	else
		printf("            ║ z ║ %f\t║", scene->sphere[data->sp]->xyz_pos.z);
	if (flag == 14)
		printf("            ║ x ║ %s%f%s\t║", R, scene->plane[data->pl]->xyz_vec.x, B);
	else
		printf("            ║ x ║ %f\t║", scene->plane[data->pl]->xyz_vec.x);
	if (flag == 18)
		printf("            ║ x ║ %s%f%s\t║\n",
			R, scene->cylinder[data->cy]->xyz_vec.x, B);
	else
		printf("            ║ x ║ %f\t║\n", scene->cylinder[data->cy]->xyz_vec.x);
	if (flag == 4)
		printf("║ normal vec ║ y ║  %s%f%s\t║", R, scene->camera->xyz_vec.y, B);
	else
		printf("║ normal vec ║ y ║  %f\t║", scene->camera->xyz_vec.y);
	printf("            ║   ║              ║");
	printf("            ║   ║              ║");
	if (flag == 14)
		printf(" normal vec ║ y ║ %s%f%s\t║", R, scene->plane[data->pl]->xyz_vec.y, B);
	else
		printf(" normal vec ║ y ║ %f\t║", scene->plane[data->pl]->xyz_vec.y);
}

void	print_5(t_data *data, t_scene *scene, int flag)
{
	if (flag == 18)
		printf(" normal vec ║ y ║ %s%f%s\t║\n",
			R, scene->cylinder[data->cy]->xyz_vec.y, B);
	else
		printf(" normal vec ║ y ║ %f\t║\n", scene->cylinder[data->cy]->xyz_vec.y);
	if (flag == 4)
		printf("║            ║ z ║  %s%f%s\t║", R, scene->camera->xyz_vec.z, B);
	else
		printf("║            ║ z ║  %f\t║", scene->camera->xyz_vec.z);
	printf("            ║   ║              ║");
	printf("            ║   ║              ║");
	if (flag == 14)
		printf("            ║ z ║ %s%f%s\t║", R, scene->plane[data->pl]->xyz_vec.z, B);
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
