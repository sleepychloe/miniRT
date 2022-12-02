/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_msg_1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 03:38:52 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/02 06:10:49 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	show_guide_1(void)
{
	printf("╔═════════════════════════════════════╦");
	printf("═════════════════════════════════════╦");
	printf("═════════════════════════════════════╗\n");
	printf("║                camera               ║");
	printf("                light                ║");
	printf("                sphere               ║\n");
	printf("╠══════════╦══════════════════════════╬");
	printf("══════════╦══════════════════════════╬");
	printf("══════════╦══════════════════════════╣\n");
	printf("║ %sF1%s       ║ translate: -x position   ║", BLUE, B);
	printf(" %s.%s        ║ translate: -x position   ║", BLUE, B);
	printf(" %sZ%s        ║ translate: -x position   ║\n", BLUE, B);
	printf("║ %sF2%s       ║ translate: +x position   ║", BLUE, B);
	printf(" %s/%s        ║ translate: +x position   ║", BLUE, B);
	printf(" %sX%s        ║ translate: +x position   ║\n", BLUE, B);
	printf("║ %sF3%s       ║ translate: -y position   ║", BLUE, B);
	printf(" %s;%s        ║ translate: -y position   ║", BLUE, B);
	printf(" %sC%s        ║ translate: -y position   ║\n", BLUE, B);
	printf("║ %sF4%s       ║ translate: +y position   ║", BLUE, B);
	printf(" %s'%s        ║ translate: +y position   ║", BLUE, B);
	printf(" %sV%s        ║ translate: +y position   ║\n", BLUE, B);
	printf("║ %sF5%s       ║ translate: -z position   ║", BLUE, B);
	printf(" %s[%s        ║ translate: -z position   ║", BLUE, B);
	printf(" %sB%s        ║ translate: -z position   ║\n", BLUE, B);
}

void	show_guide_2(void)
{
	printf("║ %sF6%s       ║ translate: +z position   ║", BLUE, B);
	printf(" %s]%s        ║ translate: +z position   ║", BLUE, B);
	printf(" %sN%s        ║ translate: +z position   ║\n", BLUE, B);
	printf("║ %sF7%s       ║ rotate: x axis, -%d°     ║",
		BLUE, B, ROTATE_ANGLE);
	printf(" %sCTRL(L)%s  ║ show info: light +1      ║", BLUE, B);
	printf(" %sSHIFT(L)%s ║ show info: sphere +1     ║\n", BLUE, B);
	printf("║ %sF8%s       ║ rotate: y axis, -%d°     ║",
		BLUE, B, ROTATE_ANGLE);
	printf("══════════╩══════════════════════════╣");
	printf("══════════╩══════════════════════════╣\n");
	printf("║ %sF9%s       ║ rotate: z axis, -%d°     ║",
		BLUE, B, ROTATE_ANGLE);
	printf("                utils                ║");
	printf("                 zoom                ║\n");
	printf("║          ║                          ║");
	printf("══════════╦══════════════════════════╣");
	printf("══════════╦══════════════════════════╣\n");
	printf("║          ║                          ║");
	printf(" %sESC%s      ║ exit                     ║", BLUE, B);
	printf(" %sUP%s       ║ zoom in                  ║\n", BLUE, B);
	printf("║          ║                          ║");
	printf("          ║                          ║");
	printf(" %sDOWN%s     ║ zoom out                 ║\n", BLUE, B);
}

void	show_guide_3(void)
{
	printf("╚══════════╩══════════════════════════╩");
	printf("══════════╩══════════════════════════╩");
	printf("══════════╩══════════════════════════╝\n");
	printf("╔═════════════════════════════════════╦");
	printf("═════════════════════════════════════╦");
	printf("═════════════════════════════════════╗\n");
	printf("║                plane                ║");
	printf("              cylinder               ║");
	printf("                cone                 ║\n");
	printf("╠══════════╦══════════════════════════╬");
	printf("══════════╦══════════════════════════╬");
	printf("══════════╦══════════════════════════╣\n");
	printf("║ %sA%s        ║ translate: -x position   ║", BLUE, B);
	printf(" %sQ%s        ║ translate: -x position   ║", BLUE, B);
	printf(" %s1%s        ║ translate: -x position   ║\n", BLUE, B);
	printf("║ %sS%s        ║ translate: +x position   ║", BLUE, B);
	printf(" %sW%s        ║ translate: +x position   ║", BLUE, B);
	printf(" %s2%s        ║ translate: +x position   ║\n", BLUE, B);
	printf("║ %sD%s        ║ translate: -y position   ║", BLUE, B);
	printf(" %sE%s        ║ translate: -y position   ║", BLUE, B);
	printf(" %s3%s        ║ translate: -y position   ║\n", BLUE, B);
	printf("║ %sF%s        ║ translate: +y position   ║", BLUE, B);
	printf(" %sR%s        ║ translate: +y position   ║", BLUE, B);
	printf(" %s4%s        ║ translate: +y position   ║\n", BLUE, B);
}

void	show_guide_4(void)
{
	printf("║ %sG%s        ║ translate: -z position   ║", BLUE, B);
	printf(" %sT%s        ║ translate: -z position   ║", BLUE, B);
	printf(" %s5%s        ║ translate: -z position   ║\n", BLUE, B);
	printf("║ %sH%s        ║ translate: +z position   ║", BLUE, B);
	printf(" %sY%s        ║ translate: +z position   ║", BLUE, B);
	printf(" %s6%s        ║ translate: +z position   ║\n", BLUE, B);
	printf("║ %sJ%s        ║ rotate: x axis, -%d°     ║", BLUE, B,
		ROTATE_ANGLE);
	printf(" %sU%s        ║ rotate: x axis, -%d°     ║", BLUE, B,
		ROTATE_ANGLE);
	printf(" %s7%s        ║ rotate: x axis, -%d°     ║\n", BLUE, B,
		ROTATE_ANGLE);
	printf("║ %sK%s        ║ rotate: y axis, -%d°     ║", BLUE, B,
		ROTATE_ANGLE);
	printf(" %sI%s        ║ rotate: y axis, -%d°     ║", BLUE, B,
		ROTATE_ANGLE);
	printf(" %s8%s        ║ rotate: y axis, -%d°     ║\n", BLUE, B,
		ROTATE_ANGLE);
	printf("║ %sL%s        ║ rotate: z axis, -%d°     ║", BLUE, B,
		ROTATE_ANGLE);
	printf(" %sO%s        ║ rotate: z axis, -%d°     ║", BLUE, B,
		ROTATE_ANGLE);
	printf(" %s9%s        ║ rotate: z axis, -%d°     ║\n", BLUE, B,
		ROTATE_ANGLE);
}

void	show_guide(void)
{
	show_guide_1();
	show_guide_2();
	show_guide_3();
	show_guide_4();
	printf("║ %sCAPSLOCK%s ║ show info: plane +1      ║", BLUE, B);
	printf(" %sTAB%s      ║ show info: cylinder +1   ║", BLUE, B);
	printf(" %s`%s        ║ show info: cone +1       ║\n", BLUE, B);
	printf("╚══════════╩══════════════════════════╩");
	printf("══════════╩══════════════════════════╩");
	printf("══════════╩══════════════════════════╝\n");
}
