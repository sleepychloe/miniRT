/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:53:45 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/19 06:49:55 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	free_and_finish_gnl(t_scene *scene, char **line, int fd, int id_err)
{
	if (id_err == 1)
	{
		err_msg("Identifier error");
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
	char	**s;
	int		id_err;

	id_err = 0;
	s = ft_split(*line, ' ');
	if (ft_strncmp(s[0], "A", 1) == 0)
		parse_ambient(scene, line);
	else if (ft_strncmp(s[0], "C", 1) == 0)
		parse_camera(scene, line);
	else if (ft_strncmp(s[0], "L", 1) == 0)
		parse_light(scene, line);
	else if (ft_strncmp(s[0], "sp", 2) == 0)
		printf("sp\n");
	else if (ft_strncmp(s[0], "pl", 2) == 0)
		printf("pl\n");
	else if (ft_strncmp(s[0], "cy", 2) == 0)
		printf("cy\n");
	else
		id_err = 1;
	ft_free_2d(s);
	if (id_err)
		free_and_finish_gnl(scene, line, fd, id_err);
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
		if (*line == '\n')
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
