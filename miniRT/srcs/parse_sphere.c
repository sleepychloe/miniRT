/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 02:42:21 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/19 06:47:54 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	parse_sphere(t_scene *scene, char **line, char ***s)
{
	int	i;

	i = 0;
	while (1)
	{
		if (scene->sphere[i]->check)
			i++;
		else
		{
			if (i > 0)
			{
				scene->sphere[i] = (t_sphere *)malloc(sizeof(t_sphere));
			}
			break ;
		}
	}
	if (!(scene->sphere[i]))
	{
		ft_free_struct(scene);
		ft_free_2d(***s);
	}
}

int	parse_sphere(t_scene *scene, char **line)
{
}
