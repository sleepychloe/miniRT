/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:17:22 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/18 20:23:58 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int check_line_token(char **line, int cnt)
{
    int     i;
    char    **s;

    i = 0;
    s = ft_split(*line, ' ');
    while (s[i])
    {
        i++;
    }
    ft_free_2d(s);
    if (i != cnt)
        return (1);
    return (0);
}

int check_small_token(char *token)
{
    int     i;
    char    **s;

    i = 0;
    s = ft_split(token, ',');
    while (s[i])
    {
        i++;
    }
    ft_free_2d(s);
    if (i != 3)
        return (1);
    return (0);
}