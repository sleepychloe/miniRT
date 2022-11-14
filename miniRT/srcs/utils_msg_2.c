/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_msg_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 05:09:26 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/14 05:17:51 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	print_1(t_scene *scene)
{
	printf("╔═══════════════════════════════╦");
	printf("═══════════════════════════════╦");
	printf("═══════════════════════════════╦");
	printf("═══════════════════════════════╦");
	printf("═══════════════════════════════╗\n");
	printf("║            camera             ║");
	printf("             light             ║");
	printf("            sphere             ║");
	printf("             plane             ║");
	printf("           cylinder            ║\n");
	printf("╠════════════╦═══╦══════════════╬");
	printf("════════════╦═══╦══════════════╬");
	printf("════════════╦═══╦══════════════╬");
	printf("════════════╦═══╦══════════════╬");
	printf("════════════╦═══╦══════════════╣\n");
	printf("║            ║ x ║ %f\t║", scene->camera->xyz_pos.x);
	printf("            ║   ║              ║");
	printf("            ║   ║              ║");
	printf("            ║ x ║ %f\t║", scene->plane[0]->xyz_pos.x);
	printf("            ║ x ║ %f\t║\n", scene->cylinder[0]->xyz_pos.x);
}

void	print_2(t_scene *scene)
{
	printf("║ position   ║ y ║ %f\t║", scene->camera->xyz_pos.y);
	printf("            ║   ║              ║");
	printf("            ║   ║              ║");
	printf(" position   ║ y ║ %f\t║", scene->plane[0]->xyz_pos.y);
	printf(" position   ║ y ║ %f\t║\n", scene->cylinder[0]->xyz_pos.y);
	printf("║            ║ z ║ %f\t║", scene->camera->xyz_pos.z);
	printf("            ║ x ║ %f\t║", scene->light->xyz_pos.x);
	printf("            ║ x ║ %f\t║", scene->sphere[0]->xyz_pos.x);
	printf("            ║ z ║ %f\t║", scene->plane[0]->xyz_pos.z);
	printf("            ║ z ║ %f\t║\n", scene->cylinder[0]->xyz_pos.z);
	printf("╠════════════╬═══╬══════════════╣");
	printf(" position   ║ y ║ %f\t║", scene->light->xyz_pos.y);
	printf(" position   ║ y ║ %f\t╠", scene->sphere[0]->xyz_pos.y);
	printf("════════════╬═══╬══════════════╬");
	printf("════════════╬═══╬══════════════╣\n");
	printf("║            ║ x ║  %f\t║", scene->camera->xyz_vec.x);
	printf("            ║ z ║ %f\t║", scene->light->xyz_pos.z);
	printf("            ║ z ║ %f\t║", scene->sphere[0]->xyz_pos.z);
	printf("            ║ x ║ %f\t║", scene->plane[0]->xyz_vec.x);
	printf("            ║ x ║ %f\t║\n", scene->cylinder[0]->xyz_vec.x);
}

void	print_3(t_scene *scene)
{
	printf("║ normal vec ║ y ║  %f\t║", scene->camera->xyz_vec.y);
	printf("            ║   ║              ║");
	printf("            ║   ║              ║");
	printf(" normal vec ║ y ║ %f\t║", scene->plane[0]->xyz_vec.y);
	printf(" normal vec ║ y ║ %f\t║\n", scene->cylinder[0]->xyz_vec.y);
	printf("║            ║ z ║  %f\t║", scene->camera->xyz_vec.z);
	printf("            ║   ║              ║");
	printf("            ║   ║              ║");
	printf("            ║ z ║ %f\t║", scene->plane[0]->xyz_vec.z);
	printf("            ║ z ║ %f\t║\n", scene->cylinder[0]->xyz_vec.z);
	printf("╚════════════╩═══╩══════════════╩");
	printf("════════════╩═══╩══════════════╩");
	printf("════════════╩═══╩══════════════╩");
	printf("════════════╩═══╩══════════════╩");
	printf("════════════╩═══╩══════════════╝\n");
}

void	print_scene_inform(t_scene *scene)
{
	print_1(scene);
	print_2(scene);
	print_3(scene);
}
