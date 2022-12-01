/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_msg_3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 03:33:31 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/01 08:06:09 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	print_info_5(t_data *data, t_scene *scene, int flag)
{
	if (flag == SP_MOVE_X_MINUS || flag == SP_MOVE_X_PLUS)
		printf("            ║ x ║ %s%f%s\t║",
			R, scene->sphere[data->sp]->xyz_pos.x, B);
	else
		printf("            ║ x ║ %f\t║", scene->sphere[data->sp]->xyz_pos.x);
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
		printf(" position   ║ y ║ %s%f%s\t║",
			R, scene->light[data->l]->xyz_pos.y, B);
	else
		printf(" position   ║ y ║ %f\t║", scene->light[data->l]->xyz_pos.y);
}

void	print_info_6(t_data *data, t_scene *scene, int flag)
{
	if (flag == SP_MOVE_Y_MINUS || flag == SP_MOVE_Y_PLUS)
		printf(" position   ║ y ║ %s%f%s\t╠",
			R, scene->sphere[data->sp]->xyz_pos.y, B);
	else
		printf(" position   ║ y ║ %f\t╠", scene->sphere[data->sp]->xyz_pos.y);
	printf("════════════╬═══╬══════════════╬");
	printf("════════════╬═══╬══════════════╣\n");
	if (flag == C_ROTATE_X || flag == C_ROTATE_Y || flag == C_ROTATE_Z)
		printf("║            ║ x ║ %s%f%s\t║", R, scene->camera->xyz_vec.x, B);
	else
		printf("║            ║ x ║  %f\t║", scene->camera->xyz_vec.x);
	if (flag == L_MOVE_Z_MINUS || flag == L_MOVE_Z_PLUS)
		printf("            ║ z ║ %s%f%s\t║",
			R, scene->light[data->l]->xyz_pos.z, B);
	else
		printf("            ║ z ║ %f\t║", scene->light[data->l]->xyz_pos.z);
	if (flag == SP_MOVE_Z_MINUS || flag == SP_MOVE_Z_PLUS)
		printf("            ║ z ║ %s%f%s\t║",
			R, scene->sphere[data->sp]->xyz_pos.z, B);
	else
		printf("            ║ z ║ %f\t║", scene->sphere[data->sp]->xyz_pos.z);
}

void	print_info_7(t_data *data, t_scene *scene, int flag)
{
	if (flag == PL_ROTATE_X || flag == PL_ROTATE_Y || flag == PL_ROTATE_Z)
		printf("            ║ x ║ %s%f%s\t║",
			R, scene->plane[data->pl]->xyz_vec.x, B);
	else
		printf("            ║ x ║ %f\t║", scene->plane[data->pl]->xyz_vec.x);
	if (flag == CY_ROTATE_X || flag == CY_ROTATE_Y || flag == CY_ROTATE_Z)
		printf("            ║ x ║ %s%f%s\t║\n",
			R, scene->cylinder[data->cy]->xyz_vec.x, B);
	else
		printf("            ║ x ║ %f\t║\n", scene->cylinder[data->cy]->xyz_vec.x);
	if (flag == C_ROTATE_X || flag == C_ROTATE_Y || flag == C_ROTATE_Z)
		printf("║ normal vec ║ y ║ %s%f%s\t║", R, scene->camera->xyz_vec.y, B);
	else
		printf("║ normal vec ║ y ║  %f\t║", scene->camera->xyz_vec.y);
	printf("            ║   ║              ║");
	printf("            ║   ║              ║");
	if (flag == PL_ROTATE_X || flag == PL_ROTATE_Y || flag == PL_ROTATE_Z)
		printf(" normal vec ║ y ║ %s%f%s\t║",
			R, scene->plane[data->pl]->xyz_vec.y, B);
	else
		printf(" normal vec ║ y ║ %f\t║", scene->plane[data->pl]->xyz_vec.y);
}

void	print_info_8(t_data *data, t_scene *scene, int flag)
{
	if (flag == CY_ROTATE_X || flag == CY_ROTATE_Y || flag == CY_ROTATE_Z)
		printf(" normal vec ║ y ║ %s%f%s\t║\n",
			R, scene->cylinder[data->cy]->xyz_vec.y, B);
	else
		printf(" normal vec ║ y ║ %f\t║\n", scene->cylinder[data->cy]->xyz_vec.y);
	if (flag == C_ROTATE_X || flag == C_ROTATE_Y || flag == C_ROTATE_Z)
		printf("║            ║ z ║ %s%f%s\t║", R, scene->camera->xyz_vec.z, B);
	else
		printf("║            ║ z ║  %f\t║", scene->camera->xyz_vec.z);
	printf("            ║   ║              ║");
	printf("            ║   ║              ║");
	if (flag == PL_ROTATE_X || flag == PL_ROTATE_Y || flag == PL_ROTATE_Z)
		printf("            ║ z ║ %s%f%s\t║",
			R, scene->plane[data->pl]->xyz_vec.z, B);
	else
		printf("            ║ z ║ %f\t║", scene->plane[data->pl]->xyz_vec.z);
	if (flag == CY_ROTATE_X || flag == CY_ROTATE_Y || flag == CY_ROTATE_Z)
		printf("            ║ z ║ %s%f%s\t║\n",
			R, scene->cylinder[data->cy]->xyz_vec.z, B);
	else
		printf("            ║ z ║ %f\t║\n", scene->cylinder[data->cy]->xyz_vec.z);
}

void	print_info_9(t_data *data, t_scene *scene, int flag)
{
	(void)data;
	(void)scene;
	(void)flag;
	printf("╚════════════╩═══╩══════════════╩");
	printf("════════════╩═══╩══════════════╩");
	printf("════════════╩═══╩══════════════╩");
	printf("════════════╩═══╩══════════════╩");
	printf("════════════╩═══╩══════════════╝\n");
}
