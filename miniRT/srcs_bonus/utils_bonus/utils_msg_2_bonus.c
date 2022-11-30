/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_msg_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 05:09:26 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/30 21:54:13 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	print_info_1(t_data *data, t_scene *scene, int flag)
{
	(void)data;
	(void)scene;
	printf("╔═══════════════════════════════╦");
	printf("═══════════════════════════════╦");
	printf("═══════════════════════════════╦");
	printf("═══════════════════════════════╦");
	printf("═══════════════════════════════╗\n");
	if (flag == C_MOVE_X_MINUS || flag == C_MOVE_X_PLUS
		|| flag == C_MOVE_Y_MINUS || flag == C_MOVE_Y_PLUS
		|| flag == C_MOVE_Z_MINUS || flag == C_MOVE_Z_PLUS
		|| flag == C_ROTATE_X || flag == C_ROTATE_Y || flag == C_ROTATE_Z)
		printf("║            %scamera%s             ║", R, B);
	else
		printf("║            camera             ║");
	if (flag == L_MOVE_X_MINUS || flag == L_MOVE_X_PLUS
		|| flag == L_MOVE_Y_MINUS || flag == L_MOVE_Y_PLUS
		|| flag == L_MOVE_Z_MINUS || flag == L_MOVE_Z_PLUS)
		printf("             %slight%s             ║", R, B);
	else
		printf("             light             ║");
}

void	print_info_2(t_data *data, t_scene *scene, int flag)
{
	(void)scene;
	if (flag == 0 || flag == SP_NEXT
		|| flag == SP_MOVE_X_MINUS || flag == SP_MOVE_X_PLUS
		|| flag == SP_MOVE_Y_MINUS || flag == SP_MOVE_Y_PLUS
		|| flag == SP_MOVE_Z_MINUS || flag == SP_MOVE_Z_PLUS)
		printf("           %ssphere[%d]%s           ║", R, data->sp, B);
	else
		printf("           sphere[%d]           ║", data->sp);
	if (flag == 0 || flag == PL_NEXT
		|| flag == PL_MOVE_X_MINUS || flag == PL_MOVE_X_PLUS
		|| flag == PL_MOVE_Y_MINUS || flag == PL_MOVE_Y_PLUS
		|| flag == PL_MOVE_Z_MINUS || flag == PL_MOVE_Z_PLUS
		|| flag == PL_ROTATE_X || flag == PL_ROTATE_Y || flag == PL_ROTATE_Z)
		printf("            %splane[%d]%s           ║", R, data->pl, B);
	else
		printf("            plane[%d]           ║", data->pl);
	if (flag == 0 || flag == CY_NEXT
		|| flag == CY_MOVE_X_MINUS || flag == CY_MOVE_X_PLUS
		|| flag == CY_MOVE_Y_MINUS || flag == CY_MOVE_Y_PLUS
		|| flag == CY_MOVE_Z_MINUS || flag == CY_MOVE_Z_PLUS
		|| flag == CY_ROTATE_X || flag == CY_ROTATE_Y || flag == CY_ROTATE_Z)
		printf("          %scylinder[%d]%s          ║\n", R, data->cy, B);
	else
		printf("          cylinder[%d]          ║\n", data->cy);
}

void	print_info_3(t_data *data, t_scene *scene, int flag)
{
	printf("╠════════════╦═══╦══════════════╬");
	printf("════════════╦═══╦══════════════╬");
	printf("════════════╦═══╦══════════════╬");
	printf("════════════╦═══╦══════════════╬");
	printf("════════════╦═══╦══════════════╣\n");
	if (flag == C_MOVE_X_MINUS || flag == C_MOVE_X_PLUS)
		printf("║            ║ x ║ %s%f%s\t║", R, scene->camera->xyz_pos.x, B);
	else
		printf("║            ║ x ║ %f\t║", scene->camera->xyz_pos.x);
	printf("            ║   ║              ║");
	printf("            ║   ║              ║");
	if (flag == PL_MOVE_X_MINUS || flag == PL_MOVE_X_PLUS)
		printf("            ║ x ║ %s%f%s\t║",
			R, scene->plane[data->pl]->xyz_pos.x, B);
	else
		printf("            ║ x ║ %f\t║", scene->plane[data->pl]->xyz_pos.x);
	if (flag == CY_MOVE_X_MINUS || flag == CY_MOVE_X_PLUS)
		printf("            ║ x ║ %s%f%s\t║\n",
			R, scene->cylinder[data->cy]->xyz_pos.x, B);
	else
		printf("            ║ x ║ %f\t║\n", scene->cylinder[data->cy]->xyz_pos.x);
	if (flag == C_MOVE_Y_MINUS || flag == C_MOVE_Y_PLUS)
		printf("║ position   ║ y ║ %s%f%s\t║", R, scene->camera->xyz_pos.y, B);
	else
		printf("║ position   ║ y ║ %f\t║", scene->camera->xyz_pos.y);
}

void	print_info_4(t_data *data, t_scene *scene, int flag)
{
	printf("            ║   ║              ║");
	printf("            ║   ║              ║");
	if (flag == PL_MOVE_Y_MINUS || flag == PL_MOVE_Y_PLUS)
		printf(" position   ║ y ║ %s%f%s\t║",
			R, scene->plane[data->pl]->xyz_pos.y, B);
	else
		printf(" position   ║ y ║ %f\t║", scene->plane[data->pl]->xyz_pos.y);
	if (flag == CY_MOVE_Y_MINUS || flag == CY_MOVE_Y_PLUS)
		printf(" position   ║ y ║ %s%f%s\t║\n",
			R, scene->cylinder[data->cy]->xyz_pos.y, B);
	else
		printf(" position   ║ y ║ %f\t║\n", scene->cylinder[data->cy]->xyz_pos.y);
	if (flag == C_MOVE_Z_MINUS || flag == C_MOVE_Z_PLUS)
		printf("║            ║ z ║ %s%f%s\t║", R, scene->camera->xyz_pos.z, B);
	else
		printf("║            ║ z ║ %f\t║", scene->camera->xyz_pos.z);
	if (flag == L_MOVE_X_MINUS || flag == L_MOVE_X_PLUS)
		printf("            ║ x ║ %s%f%s\t║", R, scene->light->xyz_pos.x, B);
	else
		printf("            ║ x ║ %f\t║", scene->light->xyz_pos.x);
	if (flag == SP_MOVE_X_MINUS || flag == SP_MOVE_X_PLUS)
		printf("            ║ x ║ %s%f%s\t║",
			R, scene->sphere[data->sp]->xyz_pos.x, B);
	else
		printf("            ║ x ║ %f\t║", scene->sphere[data->sp]->xyz_pos.x);
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
}
