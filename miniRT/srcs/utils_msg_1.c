/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_msg_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 03:38:52 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/14 05:14:23 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	show_1(void)
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
	printf("║ 1    ║ translate: -x position ║");
	printf(" .    ║ translate: -x position ║");
	printf("      ║                        ║");
	printf(" A    ║ translate: -x position ║");
	printf(" Q    ║ translate: -x position ║\n");
}

void	show_2(void)
{
	printf("║ 2    ║ translate: +x position ║");
	printf(" /    ║ translate: +x position ║");
	printf("      ║                        ║");
	printf(" S    ║ translate: +x position ║");
	printf(" W    ║ translate: +x position ║\n");
	printf("║ 3    ║ translate: -y position ║");
	printf(" ;    ║ translate: -y position ║");
	printf("      ║                        ║");
	printf(" D    ║ translate: -y position ║");
	printf(" E    ║ translate: -y position ║\n");
	printf("║ 4    ║ translate: +y position ║");
	printf(" '    ║ translate: +y position ║");
	printf(" Z    ║ translate: -x position ║");
	printf(" F    ║ translate: +y position ║");
	printf(" R    ║ translate: +y position ║\n");
	printf("║ 5    ║ translate: -z position ║");
	printf(" [    ║ translate: -z position ║");
	printf(" X    ║ translate: +x position ║");
	printf(" G    ║ translate: -z position ║");
	printf(" T    ║ translate: -z position ║\n");
}

void	show_3(void)
{
	printf("║ 6    ║ translate: +z position ║");
	printf(" ]    ║ translate: +z position ║");
	printf(" C    ║ translate: -y position ║");
	printf(" H    ║ translate: +z position ║");
	printf(" Y    ║ translate: +z position ║\n");
	printf("╠══════╬════════════════════════╬");
	printf("══════╩════════════════════════╣");
	printf(" V    ║ translate: +y position ╠");
	printf("══════╬════════════════════════╬");
	printf("══════╬════════════════════════╣\n");
	printf("║      ║                        ║");
	printf("             utils             ║");
	printf(" B    ║ translate: -z position ║");
	printf("      ║                        ║");
	printf("      ║                        ║\n");
	printf("║ 7    ║ rotate: x axis, +30°   ╠");
	printf("══════╦════════════════════════╣");
	printf(" N    ║ translate: +z position ║");
	printf(" J    ║ rotate: x axis, +30°   ║");
	printf(" U    ║ rotate: x axis, +30°   ║\n");
}

void	show_4(void)
{
	printf("║ 8    ║ rotate: y axis, +30°   ║");
	printf(" ESC  ║ exit                   ║");
	printf("      ║                        ║");
	printf(" K    ║ rotate: y axis, +30°   ║");
	printf(" I    ║ rotate: y axis, +30°   ║\n");
	printf("║ 9    ║ rotate: z axis, +30°   ║");
	printf(" UP   ║ zoom in                ║");
	printf("      ║                        ║");
	printf(" L    ║ rotate: z axis, +30°   ║");
	printf(" O    ║ rotate: z axis, +30°   ║\n");
	printf("║      ║                        ║");
	printf(" DOWN ║ zoom out               ║");
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
	show_1();
	show_2();
	show_3();
	show_4();
}
