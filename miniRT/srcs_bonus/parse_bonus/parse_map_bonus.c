/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:53:45 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/30 21:44:28 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	finish_gnl(t_scene *scene, char **line, int fd, int err)
{
	if (err == 9)
		err_msg("Map error: invalid character or string exists");
	free(*line);
	free_scene(scene);
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

char	**check_line(char **line)
{
	int		i;
	char	*new;

	i = 0;
	new = NULL;
	if (*line[i] == ' ')
	{
		while ((*line)[i] && (*line)[i] == ' ')
			i++;
		new = ft_substr(*line, i, ft_strlen(*line) - i);
		free(*line);
		*line = new;
	}
	return (line);
}

int	check_id(t_scene *scene, char **line)
{
	int		err;

	err = 0;
	check_line(line);
	if (**line == '\0')
		return (0);
	if (ft_strncmp(*line, "A", 1) == 0)
		err = parse_a(scene, line);
	else if (ft_strncmp(*line, "C", 1) == 0)
		err = parse_c(scene, line);
	else if (ft_strncmp(*line, "L", 1) == 0)
		err = parse_l(scene, line);
	else if (ft_strncmp(*line, "sp", 2) == 0)
		err = parse_sp(scene, line);
	else if (ft_strncmp(*line, "pl", 2) == 0)
		err = parse_pl(scene, line);
	else if (ft_strncmp(*line, "cy", 2) == 0)
		err = parse_cy(scene, line);
	else
		return (9);
	return (err);
}

void	parse_map(t_scene *scene, char *argv)
{
	int		fd;
	int		err;
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
		err = check_id(scene, &line);
		if (err)
			finish_gnl(scene, &line, fd, err);
		free(line);
	}
	close(fd);
}
