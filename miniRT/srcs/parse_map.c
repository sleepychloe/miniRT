/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:53:45 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/23 00:53:17 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	finish_gnl(t_scene *scene, char **line, int fd, int err)
{
	if (err == 1)
	{
		err_msg("Map error: invalid character or string exists");
		free(*line);
		ft_free_struct(scene);
		while (1)
		{
			*line = get_next_line(fd);
			if (*line == NULL)
				break ;
			free(*line);
		}
		close(fd);
		exit(1);
	}
}

void	check_id(t_scene *scene, char **line, int fd)
{
	int		err;

	err = 0;
	if (ft_strncmp(*line, "A", 1) == 0)
		parse_a(scene, line);
	else if (ft_strncmp(*line, "C", 1) == 0)
		parse_c(scene, line);
	else if (ft_strncmp(*line, "L", 1) == 0)
		parse_l(scene, line);
	else if (ft_strncmp(*line, "sp", 2) == 0)
		parse_sp(scene, line);
	else if (ft_strncmp(*line, "pl", 2) == 0)
		parse_pl(scene, line);
	else if (ft_strncmp(*line, "cy", 2) == 0)
		parse_cy(scene, line);
	else
		err = 1;
	if (err)
		finish_gnl(scene, line, fd, err);
}

void	parse_map(t_scene *scene, char *argv)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(argv, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (*line == '\n' || *line == '#')
		{
			free(line);
			continue ;
		}
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		check_id(scene, &line, fd);
		free(line);
	}
	close(fd);
}
