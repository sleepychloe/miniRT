/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_msg_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 03:33:31 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/29 07:01:11 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	print_info_5(t_data *data, t_scene *scene, int flag)
{
	if (flag == PL_MOVE_Z_MINUS || flag == PL_MOVE_Z_PLUS)
		printf("            ║ z ║ %s%f%s\t║",
			R, scene->plane[data->pl]->xyz_pos.z, B);
	else
		printf("            ║ z ║ %f\t║", scene->plane[data->pl]->xyz_pos.z);
	if (flag == CY_MOVE_Z_MINUS || flag == CY_MOVE_Z_PLUS)
		printf("            ║ z ║ %s%f%s\t║\n",
			R, scene->cylinder[data->cy]->xyz_pos.z, B);
	else
		printf("            ║ z ║ %f\t║\n", scene->cylinder[data->cy]->xyz_pos.z);
	printf("╠════════════╬═══╬══════════════╣");
	if (flag == L_MOVE_Y_MINUS || flag == L_MOVE_Y_PLUS)
		printf(" position   ║ y ║ %s%f%s\t║", R, scene->light->xyz_pos.y, B);
	else
		printf(" position   ║ y ║ %f\t║", scene->light->xyz_pos.y);
	if (flag == SP_MOVE_Y_MINUS || flag == SP_MOVE_Y_PLUS)
		printf(" position   ║ y ║ %s%f%s\t╠",
			R, scene->sphere[data->sp]->xyz_pos.y, B);
	else
		printf(" position   ║ y ║ %f\t╠", scene->sphere[data->sp]->xyz_pos.y);
	printf("════════════╬═══╬══════════════╬");
	printf("════════════╬═══╬══════════════╣\n");
}

void	print_info_6(t_data *data, t_scene *scene, int flag)
{
	if (flag == C_ROTATE)
		printf("║            ║ x ║ %s%f%s\t║", R, scene->camera->xyz_vec.x, B);
	else
		printf("║            ║ x ║  %f\t║", scene->camera->xyz_vec.x);
	if (flag == L_MOVE_Z_MINUS || flag == L_MOVE_Z_PLUS)
		printf("            ║ z ║ %s%f%s\t║", R, scene->light->xyz_pos.z, B);
	else
		printf("            ║ z ║ %f\t║", scene->light->xyz_pos.z);
	if (flag == SP_MOVE_Z_MINUS || flag == SP_MOVE_Z_PLUS)
		printf("            ║ z ║ %s%f%s\t║",
			R, scene->sphere[data->sp]->xyz_pos.z, B);
	else
		printf("            ║ z ║ %f\t║", scene->sphere[data->sp]->xyz_pos.z);
	if (flag == PL_ROTATE)
		printf("            ║ x ║ %s%f%s\t║",
			R, scene->plane[data->pl]->xyz_vec.x, B);
	else
		printf("            ║ x ║ %f\t║", scene->plane[data->pl]->xyz_vec.x);
	if (flag == CY_ROTATE)
		printf("            ║ x ║ %s%f%s\t║\n",
			R, scene->cylinder[data->cy]->xyz_vec.x, B);
	else
		printf("            ║ x ║ %f\t║\n", scene->cylinder[data->cy]->xyz_vec.x);
}

void	print_info_7(t_data *data, t_scene *scene, int flag)
{
	if (flag == C_ROTATE)
		printf("║ normal vec ║ y ║ %s%f%s\t║", R, scene->camera->xyz_vec.y, B);
	else
		printf("║ normal vec ║ y ║  %f\t║", scene->camera->xyz_vec.y);
	printf("            ║   ║              ║");
	printf("            ║   ║              ║");
	if (flag == PL_ROTATE)
		printf(" normal vec ║ y ║ %s%f%s\t║",
			R, scene->plane[data->pl]->xyz_vec.y, B);
	else
		printf(" normal vec ║ y ║ %f\t║", scene->plane[data->pl]->xyz_vec.y);
	if (flag == CY_ROTATE)
		printf(" normal vec ║ y ║ %s%f%s\t║\n",
			R, scene->cylinder[data->cy]->xyz_vec.y, B);
	else
		printf(" normal vec ║ y ║ %f\t║\n", scene->cylinder[data->cy]->xyz_vec.y);
	if (flag == C_ROTATE)
		printf("║            ║ z ║ %s%f%s\t║", R, scene->camera->xyz_vec.z, B);
	else
		printf("║            ║ z ║  %f\t║", scene->camera->xyz_vec.z);
	printf("            ║   ║              ║");
	printf("            ║   ║              ║");
}

void	print_info_8(t_data *data, t_scene *scene, int flag)
{
	if (flag == PL_ROTATE)
		printf("            ║ z ║ %s%f%s\t║",
			R, scene->plane[data->pl]->xyz_vec.z, B);
	else
		printf("            ║ z ║ %f\t║", scene->plane[data->pl]->xyz_vec.z);
	if (flag == CY_ROTATE)
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
