/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_msg_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 05:09:26 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/02 06:06:46 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	print_info_1(t_data *data, t_scene *scene, int flag)
{
	(void)scene;
	printf("╔═══════════════════════════════╦");
	printf("═══════════════════════════════╦");
	printf("═══════════════════════════════╗\n");
	if (flag == C_MOVE_X_MINUS || flag == C_MOVE_X_PLUS
		|| flag == C_MOVE_Y_MINUS || flag == C_MOVE_Y_PLUS
		|| flag == C_MOVE_Z_MINUS || flag == C_MOVE_Z_PLUS
		|| flag == C_ROTATE_X || flag == C_ROTATE_Y || flag == C_ROTATE_Z)
		printf("║            %scamera%s             ║", R, B);
	else
		printf("║            camera             ║");
	if (flag == 0 || flag == L_NEXT
		|| flag == L_MOVE_X_MINUS || flag == L_MOVE_X_PLUS
		|| flag == L_MOVE_Y_MINUS || flag == L_MOVE_Y_PLUS
		|| flag == L_MOVE_Z_MINUS || flag == L_MOVE_Z_PLUS)
		printf("           %slight[%d]%s            ║", R, data->l, B);
	else
		printf("            light[%d]           ║", data->l);
	if (flag == 0 || flag == SP_NEXT
		|| flag == SP_MOVE_X_MINUS || flag == SP_MOVE_X_PLUS
		|| flag == SP_MOVE_Y_MINUS || flag == SP_MOVE_Y_PLUS
		|| flag == SP_MOVE_Z_MINUS || flag == SP_MOVE_Z_PLUS)
		printf("           %ssphere[%d]%s           ║\n", R, data->sp, B);
	else
		printf("           sphere[%d]           ║\n", data->sp);
}

void	print_info_2(t_data *data, t_scene *scene, int flag)
{
	printf("╠════════════╦═══╦══════════════╬");
	printf("════════════╦═══╦══════════════╬");
	printf("════════════╦═══╦══════════════╣\n");
	if (flag == C_MOVE_X_MINUS || flag == C_MOVE_X_PLUS)
		printf("║            ║ x ║ %s%f%s\t║", R, scene->camera->xyz_pos.x, B);
	else
		printf("║            ║ x ║ %f\t║", scene->camera->xyz_pos.x);
	printf("            ║   ║              ║");
	printf("            ║   ║              ║\n");
	if (flag == C_MOVE_Y_MINUS || flag == C_MOVE_Y_PLUS)
		printf("║ position   ║ y ║ %s%f%s\t║", R, scene->camera->xyz_pos.y, B);
	else
		printf("║ position   ║ y ║ %f\t║", scene->camera->xyz_pos.y);
	printf("            ║   ║              ║");
	printf("            ║   ║              ║\n");
	if (flag == C_MOVE_Z_MINUS || flag == C_MOVE_Z_PLUS)
		printf("║            ║ z ║ %s%f%s\t║", R, scene->camera->xyz_pos.z, B);
	else
		printf("║            ║ z ║ %f\t║", scene->camera->xyz_pos.z);
	if (flag == L_MOVE_X_MINUS || flag == L_MOVE_X_PLUS)
		printf("            ║ x ║ %s%f%s\t║",
			R, scene->light[data->l]->xyz_pos.x, B);
	else
		printf("            ║ x ║ %f\t║", scene->light[data->l]->xyz_pos.x);
}

void	print_info_3(t_data *data, t_scene *scene, int flag)
{
	if (flag == SP_MOVE_X_MINUS || flag == SP_MOVE_X_PLUS)
		printf("            ║ x ║ %s%f%s\t║\n",
			R, scene->sphere[data->sp]->xyz_pos.x, B);
	else
		printf("            ║ x ║ %f\t║\n", scene->sphere[data->sp]->xyz_pos.x);
	printf("╠════════════╬═══╬══════════════╬");
	if (flag == L_MOVE_Y_MINUS || flag == L_MOVE_Y_PLUS)
		printf(" position   ║ y ║ %s%f%s\t║",
			R, scene->light[data->l]->xyz_pos.y, B);
	else
		printf(" position   ║ y ║ %f\t║", scene->light[data->l]->xyz_pos.y);
	if (flag == SP_MOVE_Y_MINUS || flag == SP_MOVE_Y_PLUS)
		printf(" position   ║ y ║ %s%f%s\t║\n",
			R, scene->sphere[data->sp]->xyz_pos.y, B);
	else
		printf(" position   ║ y ║ %f\t║\n", scene->sphere[data->sp]->xyz_pos.y);
	if (flag == C_ROTATE_X || flag == C_ROTATE_Y || flag == C_ROTATE_Z)
		printf("║            ║ x ║ %s%f%s\t║", R, scene->camera->xyz_vec.x, B);
	else
		printf("║            ║ x ║  %f\t║", scene->camera->xyz_vec.x);
	if (flag == L_MOVE_Z_MINUS || flag == L_MOVE_Z_PLUS)
		printf("            ║ z ║ %s%f%s\t║",
			R, scene->light[data->l]->xyz_pos.z, B);
	else
		printf("            ║ z ║ %f\t║", scene->light[data->l]->xyz_pos.z);
}

void	print_info_4(t_data *data, t_scene *scene, int flag)
{
	if (flag == SP_MOVE_Z_MINUS || flag == SP_MOVE_Z_PLUS)
		printf("            ║ z ║ %s%f%s\t║\n",
			R, scene->sphere[data->sp]->xyz_pos.z, B);
	else
		printf("            ║ z ║ %f\t║\n", scene->sphere[data->sp]->xyz_pos.z);
	if (flag == C_ROTATE_X || flag == C_ROTATE_Y || flag == C_ROTATE_Z)
		printf("║ normal vec ║ y ║ %s%f%s\t║", R, scene->camera->xyz_vec.y, B);
	else
		printf("║ normal vec ║ y ║  %f\t║", scene->camera->xyz_vec.y);
	printf("            ║   ║              ║");
	printf("            ║   ║              ║\n");
	if (flag == C_ROTATE_X || flag == C_ROTATE_Y || flag == C_ROTATE_Z)
		printf("║            ║ z ║ %s%f%s\t║", R, scene->camera->xyz_vec.z, B);
	else
		printf("║            ║ z ║  %f\t║", scene->camera->xyz_vec.z);
	printf("            ║   ║              ║");
	printf("            ║   ║              ║\n");
	printf("╚════════════╩═══╩══════════════╩");
	printf("════════════╩═══╩══════════════╩");
	printf("════════════╩═══╩══════════════╝\n");
	printf("╔═══════════════════════════════╦");
	printf("═══════════════════════════════╦");
	printf("═══════════════════════════════╗\n");
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
	print_info_8(data, scene, flag);
	print_info_9(data, scene, flag);
	printf("╚════════════╩═══╩══════════════╩");
	printf("════════════╩═══╩══════════════╩");
	printf("════════════╩═══╩══════════════╝\n");
}
