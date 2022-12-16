/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:14:59 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/15 18:38:20 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	err_msg(char *str)
{
	printf("Error\n");
	printf("%s\n", str);
}

void	map_err_i(int i, char *id, char *str)
{
	printf("Error\n");
	printf("Map error: ");
	if ((i % 10) == 1)
		printf("%dst ", i);
	else if ((i % 10) == 2)
		printf("%dnd ", i);
	else if ((i % 10) == 3)
		printf("%drd ", i);
	else
		printf("%dth ", i);
	printf("%s: %s\n", id, str);
}
