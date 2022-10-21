/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:14:59 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/20 23:58:43 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

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
/*
int	sep_count(char **xyz_pos)
{
	
}
*/
void	err_msg(char *str)
{
	printf("Error\n");
	printf("%s\n", str);
}
