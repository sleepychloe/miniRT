/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_msg_3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 03:33:31 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/02 06:06:03 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	print_info_5(t_data *data, t_scene *scene, int flag)
{
	(void)scene;
	if (flag == 0 || flag == PL_NEXT
		|| flag == PL_MOVE_X_MINUS || flag == PL_MOVE_X_PLUS
		|| flag == PL_MOVE_Y_MINUS || flag == PL_MOVE_Y_PLUS
		|| flag == PL_MOVE_Z_MINUS || flag == PL_MOVE_Z_PLUS
		|| flag == PL_ROTATE_X || flag == PL_ROTATE_Y || flag == PL_ROTATE_Z)
		printf("║            %splane[%d]%s           ║", R, data->pl, B);
	else
		printf("║            plane[%d]           ║", data->pl);
	if (flag == 0 || flag == CY_NEXT
		|| flag == CY_MOVE_X_MINUS || flag == CY_MOVE_X_PLUS
		|| flag == CY_MOVE_Y_MINUS || flag == CY_MOVE_Y_PLUS
		|| flag == CY_MOVE_Z_MINUS || flag == CY_MOVE_Z_PLUS
		|| flag == CY_ROTATE_X || flag == CY_ROTATE_Y || flag == CY_ROTATE_Z)
		printf("          %scylinder[%d]%s          ║", R, data->cy, B);
	else
		printf("          cylinder[%d]          ║", data->cy);
	if (flag == 0 || flag == CO_NEXT
		|| flag == CO_MOVE_X_MINUS || flag == CO_MOVE_X_PLUS
		|| flag == CO_MOVE_Y_MINUS || flag == CO_MOVE_Y_PLUS
		|| flag == CO_MOVE_Z_MINUS || flag == CO_MOVE_Z_PLUS
		|| flag == CO_ROTATE_X || flag == CO_ROTATE_Y || flag == CO_ROTATE_Z)
		printf("            %scone[%d]%s            ║\n", R, data->co, B);
	else
		printf("            cone[%d]            ║\n", data->co);
}

void	print_info_6(t_data *data, t_scene *scene, int flag)
{
	printf("║════════════╦═══╦══════════════╬");
	printf("════════════╦═══╦══════════════╬");
	printf("════════════╦═══╦══════════════╣\n");
	if (flag == PL_MOVE_X_MINUS || flag == PL_MOVE_X_PLUS)
		printf("║            ║ x ║ %s%f%s\t║",
			R, scene->plane[data->pl]->xyz_pos.x, B);
	else
		printf("║            ║ x ║ %f\t║", scene->plane[data->pl]->xyz_pos.x);
	if (flag == CY_MOVE_X_MINUS || flag == CY_MOVE_X_PLUS)
		printf("            ║ x ║ %s%f%s\t║",
			R, scene->cylinder[data->cy]->xyz_pos.x, B);
	else
		printf("            ║ x ║ %f\t║", scene->cylinder[data->cy]->xyz_pos.x);
	if (flag == CO_MOVE_X_MINUS || flag == CO_MOVE_X_PLUS)
		printf("            ║ x ║ %s%f%s\t║\n",
			R, scene->cone[data->co]->xyz_pos.x, B);
	else
		printf("            ║ x ║ %f\t║\n", scene->cone[data->co]->xyz_pos.x);
	if (flag == PL_MOVE_Y_MINUS || flag == PL_MOVE_Y_PLUS)
		printf("║ position   ║ y ║ %s%f%s\t║",
			R, scene->plane[data->pl]->xyz_pos.y, B);
	else
		printf("║ position   ║ y ║ %f\t║", scene->plane[data->pl]->xyz_pos.y);
}

void	print_info_7(t_data *data, t_scene *scene, int flag)
{
	if (flag == CY_MOVE_Y_MINUS || flag == CY_MOVE_Y_PLUS)
		printf(" position   ║ y ║ %s%f%s\t║",
			R, scene->cylinder[data->cy]->xyz_pos.y, B);
	else
		printf(" position   ║ y ║ %f\t║", scene->cylinder[data->cy]->xyz_pos.y);
	if (flag == CO_MOVE_Y_MINUS || flag == CO_MOVE_Y_PLUS)
		printf(" position   ║ y ║ %s%f%s\t║\n",
			R, scene->cone[data->co]->xyz_pos.y, B);
	else
		printf(" position   ║ y ║ %f\t║\n", scene->cone[data->co]->xyz_pos.y);
	if (flag == PL_MOVE_Z_MINUS || flag == PL_MOVE_Z_PLUS)
		printf("║            ║ z ║ %s%f%s\t║",
			R, scene->plane[data->pl]->xyz_pos.z, B);
	else
		printf("║            ║ z ║ %f\t║", scene->plane[data->pl]->xyz_pos.z);
	if (flag == CY_MOVE_Z_MINUS || flag == CY_MOVE_Z_PLUS)
		printf("            ║ z ║ %s%f%s\t║",
			R, scene->cylinder[data->cy]->xyz_pos.z, B);
	else
		printf("            ║ z ║ %f\t║", scene->cylinder[data->cy]->xyz_pos.z);
	if (flag == CO_MOVE_Z_MINUS || flag == CO_MOVE_Z_PLUS)
		printf("            ║ z ║ %s%f%s\t║\n",
			R, scene->cone[data->co]->xyz_pos.z, B);
	else
		printf("            ║ z ║ %f\t║\n", scene->cone[data->co]->xyz_pos.z);
}

void	print_info_8(t_data *data, t_scene *scene, int flag)
{
	printf("║════════════╬═══╬══════════════╬");
	printf("════════════╬═══╬══════════════╬");
	printf("════════════╬═══╬══════════════╣\n");
	if (flag == PL_ROTATE_X || flag == PL_ROTATE_Y || flag == PL_ROTATE_Z)
		printf("║            ║ x ║ %s%f%s\t║",
			R, scene->plane[data->pl]->xyz_vec.x, B);
	else
		printf("║            ║ x ║ %f\t║", scene->plane[data->pl]->xyz_vec.x);
	if (flag == CY_ROTATE_X || flag == CY_ROTATE_Y || flag == CY_ROTATE_Z)
		printf("            ║ x ║ %s%f%s\t║",
			R, scene->cylinder[data->cy]->xyz_vec.x, B);
	else
		printf("            ║ x ║ %f\t║", scene->cylinder[data->cy]->xyz_vec.x);
	if (flag == CO_ROTATE_X || flag == CO_ROTATE_Y || flag == CO_ROTATE_Z)
		printf("            ║ x ║ %s%f%s\t║\n",
			R, scene->cone[data->co]->xyz_vec.x, B);
	else
		printf("            ║ x ║ %f\t║\n", scene->cone[data->co]->xyz_vec.x);
	if (flag == PL_ROTATE_X || flag == PL_ROTATE_Y || flag == PL_ROTATE_Z)
		printf("║ normal vec ║ y ║ %s%f%s\t║",
			R, scene->plane[data->pl]->xyz_vec.y, B);
	else
		printf("║ normal vec ║ y ║ %f\t║", scene->plane[data->pl]->xyz_vec.y);
}

void	print_info_9(t_data *data, t_scene *scene, int flag)
{
	if (flag == CY_ROTATE_X || flag == CY_ROTATE_Y || flag == CY_ROTATE_Z)
		printf(" normal vec ║ y ║ %s%f%s\t║",
			R, scene->cylinder[data->cy]->xyz_vec.y, B);
	else
		printf(" normal vec ║ y ║ %f\t║", scene->cylinder[data->cy]->xyz_vec.y);
	if (flag == CO_ROTATE_X || flag == CO_ROTATE_Y || flag == CO_ROTATE_Z)
		printf(" normal vec ║ y ║ %s%f%s\t║\n",
			R, scene->cone[data->co]->xyz_vec.y, B);
	else
		printf(" normal vec ║ y ║ %f\t║\n", scene->cone[data->co]->xyz_vec.y);
	if (flag == PL_ROTATE_X || flag == PL_ROTATE_Y || flag == PL_ROTATE_Z)
		printf("║            ║ z ║ %s%f%s\t║",
			R, scene->plane[data->pl]->xyz_vec.z, B);
	else
		printf("║            ║ z ║ %f\t║", scene->plane[data->pl]->xyz_vec.z);
	if (flag == CY_ROTATE_X || flag == CY_ROTATE_Y || flag == CY_ROTATE_Z)
		printf("            ║ z ║ %s%f%s\t║",
			R, scene->cylinder[data->cy]->xyz_vec.z, B);
	else
		printf("            ║ z ║ %f\t║", scene->cylinder[data->cy]->xyz_vec.z);
	if (flag == CO_ROTATE_X || flag == CO_ROTATE_Y || flag == CO_ROTATE_Z)
		printf("            ║ z ║ %s%f%s\t║\n",
			R, scene->cone[data->co]->xyz_vec.z, B);
	else
		printf("            ║ z ║ %f\t║\n", scene->cone[data->co]->xyz_vec.z);
}
