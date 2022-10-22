/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:14:59 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/23 00:11:53 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	err_msg(char *str)
{
	printf("Error\n");
	printf("%s\n", str);
}

void	map_err_i(int i, char *id, char *str)
{
	printf("Error\n");
	printf("Map error: ");
	if (i == 1)
		printf("%dst ", i);
	else if (i == 2)
		printf("%dnd ", i);
	else if (i == 3)
		printf("%drd ", i);
	else
		printf("%dth ", i);
	printf("%s: %s\n", id, str);
}

int	token_count(char **token, int cnt)
{
	int		i;

	i = 0;
	while (i < cnt)
	{
		if (!token[i])
			return (1);
		i++;
	}
	if (i >= cnt && token[i])
		return (1);
	return (0);
}
