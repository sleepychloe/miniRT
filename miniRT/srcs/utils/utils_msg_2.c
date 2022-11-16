/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_msg_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 05:09:26 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/16 03:34:03 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	print_info_1(t_data *data, t_scene *scene, int flag)
{
	(void)data;
	(void)scene;
	printf("╔═══════════════════════════════╦");
	printf("═══════════════════════════════╦");
	printf("═══════════════════════════════╦");
	printf("═══════════════════════════════╦");
	printf("═══════════════════════════════╗\n");
	if (flag == 1 || flag == 2 || flag == 3 || flag == 4)
		printf("║            %scamera%s             ║", R, B);
	else
		printf("║            camera             ║");
	if (flag == 5 || flag == 6 || flag == 7)
		printf("             %slight%s            ║", R, B);
	else
		printf("             light             ║");
	if (flag == 0 || flag == 8 || flag == 9 || flag == 10 || flag == 19)
		printf("           %ssphere[%d]%s           ║", R, data->sp, B);
	else
		printf("           sphere[%d]           ║", data->sp);
	if (flag == 0 || flag == 11 || flag == 12
		|| flag == 13 || flag == 14 || flag == 20)
		printf("            %splane[%d]%s           ║", R, data->pl, B);
	else
		printf("            plane[%d]           ║", data->pl);
}

void	print_info_2(t_data *data, t_scene *scene, int flag)
{
	if (flag == 0 || flag == 15 || flag == 16
		|| flag == 17 || flag == 18 || flag == 21)
		printf("          %scylinder[%d]%s          ║\n", R, data->cy, B);
	else
		printf("          cylinder[%d]          ║\n", data->cy);
	printf("╠════════════╦═══╦══════════════╬");
	printf("════════════╦═══╦══════════════╬");
	printf("════════════╦═══╦══════════════╬");
	printf("════════════╦═══╦══════════════╬");
	printf("════════════╦═══╦══════════════╣\n");
	if (flag == 1)
		printf("║            ║ x ║ %s%f%s\t║", R, scene->camera->xyz_pos.x, B);
	else
		printf("║            ║ x ║ %f\t║", scene->camera->xyz_pos.x);
	printf("            ║   ║              ║");
	printf("            ║   ║              ║");
	if (flag == 11)
		printf("            ║ x ║ %s%f%s\t║",
			R, scene->plane[data->pl]->xyz_pos.x, B);
	else
		printf("            ║ x ║ %f\t║", scene->plane[data->pl]->xyz_pos.x);
}

void	print_info_3(t_data *data, t_scene *scene, int flag)
{
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
	if (flag == 12)
		printf(" position   ║ y ║ %s%f%s\t║",
			R, scene->plane[data->pl]->xyz_pos.y, B);
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
}

void	print_info_4(t_data *data, t_scene *scene, int flag)
{
	if (flag == 5)
		printf("            ║ x ║ %s%f%s\t║", R, scene->light->xyz_pos.x, B);
	else
		printf("            ║ x ║ %f\t║", scene->light->xyz_pos.x);
	if (flag == 8)
		printf("            ║ x ║ %s%f%s\t║",
			R, scene->sphere[data->sp]->xyz_pos.x, B);
	else
		printf("            ║ x ║ %f\t║", scene->sphere[data->sp]->xyz_pos.x);
	if (flag == 13)
		printf("            ║ z ║ %s%f%s\t║",
			R, scene->plane[data->pl]->xyz_pos.z, B);
	else
		printf("            ║ z ║ %f\t║", scene->plane[data->pl]->xyz_pos.z);
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
}

void	print_scene_info(t_data *data, t_scene *scene, int flag)
{
	print_info_1(data, scene, flag);
	print_info_2(data, scene, flag);
	print_info_3(data, scene, flag);
	print_info_4(data, scene, flag);
	print_info_5(data, scene, flag);
	print_info_6(data, scene, flag);
	print_info_7(data, scene, flag);
}
