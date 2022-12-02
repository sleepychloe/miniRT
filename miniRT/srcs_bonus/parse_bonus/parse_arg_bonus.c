/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:12:07 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/02 00:33:46 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

int	check_extention(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len <= 3)
	{
		err_msg("File extention error");
		return (1);
	}
	if (!(str[len - 3] == '.' && str[len - 2] == 'r' && str[len - 1] == 't'))
	{
		err_msg("File extention error");
		return (1);
	}
	return (0);
}

void	parse_arg(t_scene *scene, char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (!fd || fd < 0)
	{
		err_msg("File open error");
		free_scene(scene);
		close(fd);
		exit(1);
	}
	if (check_extention(argv))
	{
		free_scene(scene);
		close(fd);
		exit(1);
	}
	close(fd);
}
