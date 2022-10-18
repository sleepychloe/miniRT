/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:53:45 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/18 20:27:26 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int     check_id(t_scene *scene, char **line)
{
    char    **s;
    int     err;

    err = 0;
    s = ft_split(*line, ' ');
    if (ft_strncmp(s[0], "A", 1) == 0 && ft_strlen(s[0]) == 1)
        parse_ambient(scene, line);
    else if (ft_strncmp(s[0], "C", 1) == 0 && ft_strlen(s[0]) == 1)
        parse_camera(scene, line);
    else if (ft_strncmp(s[0], "L", 1) == 0 && ft_strlen(s[0]) == 1)
    {
        //parse L
        printf("L\n");
    }
    else if (ft_strncmp(s[0], "sp", 2) == 0 && ft_strlen(s[0]) == 2)
    {
        //parse sp
        printf("sp\n");
    }
    else if (ft_strncmp(s[0], "pl", 2) == 0 && ft_strlen(s[0]) == 2)
    {
        //parse pl
        printf("pl\n");
    }
    else if (ft_strncmp(s[0], "cy", 2) == 0 && ft_strlen(s[0]) == 2)
    {
        //parse cy
        printf("cy\n");
    }
    else
        err = 1;
    ft_free_2d(s);
    if (err)
        return (1);
    return (0);
}

void    parse_map(t_scene *scene, char *argv)
{
    int     fd;
    char    *line;
    char    *line_trim;

    line = NULL;
    fd = open(argv, O_RDONLY);
    init_struct(scene);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break ;
        if (line[ft_strlen(line) - 1] == '\n')
            line_trim = ft_substr(line, 0, ft_strlen(line) - 1);
        else
            line_trim = ft_strdup(line);
        free(line);
        if (check_id(scene, &line_trim))
        {
            free(line_trim);
            err_msg("Map error");
            exit(1);
        }
        free(line_trim);
    }
    close(fd);
}