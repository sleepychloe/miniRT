/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_msg_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 03:38:52 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/15 04:56:10 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	show_1(void)
{
	printf("║ %s1%s    ║ translate: -x position ║", BLUE, B);
	printf(" %s.%s    ║ translate: -x position ║", BLUE, B);
	printf("      ║                        ║");
	printf(" %sA%s    ║ translate: -x position ║", BLUE, B);
	printf(" %sQ%s    ║ translate: -x position ║\n", BLUE, B);
	printf("║ %s2%s    ║ translate: +x position ║", BLUE, B);
	printf(" %s/%s    ║ translate: +x position ║", BLUE, B);
	printf("      ║                        ║");
	printf(" %sS%s    ║ translate: +x position ║", BLUE, B);
	printf(" %sW%s    ║ translate: +x position ║\n", BLUE, B);
	printf("║ %s3%s    ║ translate: -y position ║", BLUE, B);
	printf(" %s;%s    ║ translate: -y position ║", BLUE, B);
	printf("      ║                        ║");
	printf(" %sD%s    ║ translate: -y position ║", BLUE, B);
	printf(" %sE%s    ║ translate: -y position ║\n", BLUE, B);
	printf("║ %s4%s    ║ translate: +y position ║", BLUE, B);
	printf(" %s'%s    ║ translate: +y position ║", BLUE, B);
	printf(" %sZ%s    ║ translate: -x position ║", BLUE, B);
	printf(" %sF%s    ║ translate: +y position ║", BLUE, B);
	printf(" %sR%s    ║ translate: +y position ║\n", BLUE, B);
	printf("║ %s5%s    ║ translate: -z position ║", BLUE, B);
	printf(" %s[%s    ║ translate: -z position ║", BLUE, B);
	printf(" %sX%s    ║ translate: +x position ║", BLUE, B);
	printf(" %sG%s    ║ translate: -z position ║", BLUE, B);
	printf(" %sT%s    ║ translate: -z position ║\n", BLUE, B);
}

void	show_2(void)
{
	printf("║ %s6%s    ║ translate: +z position ║", BLUE, B);
	printf(" %s]%s    ║ translate: +z position ║", BLUE, B);
	printf(" %sC%s    ║ translate: -y position ║", BLUE, B);
	printf(" %sH%s    ║ translate: +z position ║", BLUE, B);
	printf(" %sY%s    ║ translate: +z position ║\n", BLUE, B);
	printf("╠══════╬════════════════════════╬");
	printf("══════╩════════════════════════╣");
	printf(" %sV%s    ║ translate: +y position ╠", BLUE, B);
	printf("══════╬════════════════════════╬");
	printf("══════╬════════════════════════╣\n");
	printf("║      ║                        ║");
	printf("             utils             ║");
	printf(" %sB%s    ║ translate: -z position ║", BLUE, B);
	printf("      ║                        ║");
	printf("      ║                        ║\n");
	printf("║ %s7%s    ║ rotate: x axis, +30°   ╠", BLUE, B);
	printf("══════╦════════════════════════╣");
	printf(" %sN%s    ║ translate: +z position ║", BLUE, B);
	printf(" %sJ%s    ║ rotate: x axis, +30°   ║", BLUE, B);
	printf(" %sU%s    ║ rotate: x axis, +30°   ║\n", BLUE, B);
	printf("║ %s8%s    ║ rotate: y axis, +30°   ║", BLUE, B);
	printf(" %sESC%s  ║ exit                   ║", BLUE, B);
	printf("      ║                        ║");
	printf(" %sK%s    ║ rotate: y axis, +30°   ║", BLUE, B);
	printf(" %sI%s    ║ rotate: y axis, +30°   ║\n", BLUE, B);
}

void	show_3(void)
{
	printf("║ %s9%s    ║ rotate: z axis, +30°   ║", BLUE, B);
	printf(" %sUP%s   ║ zoom in                ║", BLUE, B);
	printf("      ║                        ║");
	printf(" %sL%s    ║ rotate: z axis, +30°   ║", BLUE, B);
	printf(" %sO%s    ║ rotate: z axis, +30°   ║\n", BLUE, B);
	printf("║      ║                        ║");
	printf(" %sDOWN%s ║ zoom out               ║", BLUE, B);
	printf("      ║                        ║");
	printf("      ║                        ║");
	printf("      ║                        ║\n");
	printf("╚══════╩════════════════════════╩");
	printf("══════╩════════════════════════╩");
	printf("══════╩════════════════════════╩");
	printf("══════╩════════════════════════╩");
	printf("══════╩════════════════════════╝\n");
}

void	show_guide(void)
{
	printf("╔═══════════════════════════════╦");
	printf("═══════════════════════════════╦");
	printf("═══════════════════════════════╦");
	printf("═══════════════════════════════╦");
	printf("═══════════════════════════════╗\n");
	printf("║             camera            ║");
	printf("             light             ║");
	printf("             sphere            ║");
	printf("             plane             ║");
	printf("           cylinder            ║\n");
	printf("╠══════╦════════════════════════╬");
	printf("══════╦════════════════════════╬");
	printf("══════╦════════════════════════╬");
	printf("══════╦════════════════════════╬");
	printf("══════╦════════════════════════╣\n");
	show_1();
	show_2();
	show_3();
}

void	print_scene_inform(t_scene *scene, int flag)
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
	print_1(scene, flag);
	print_2(scene, flag);
	print_3(scene, flag);
	print_4(scene, flag);
	print_5(scene, flag);
}
