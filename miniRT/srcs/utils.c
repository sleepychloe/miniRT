/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:14:59 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/19 23:04:21 by yhwang           ###   ########.fr       */
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

void	ft_free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_free_struct(t_scene *scene)
{
	int	i;

	free(scene->ambient);
	free(scene->camera);
	free(scene->light);
	i = -1;
	if (scene->sphere[++i])
		free(scene->sphere[i]);
	if (scene->sphere)
		free(scene->sphere);
	i = -1;
	if (scene->plane[++i])
		free(scene->plane[i]);
	free(scene->plane);
	i = -1;
	if (scene->cylinder[++i])
		free(scene->cylinder[i]);
	free(scene->cylinder);
	free(scene);
}
