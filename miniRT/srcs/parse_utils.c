/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sucho <sucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:49:44 by sucho             #+#    #+#             */
/*   Updated: 2022/09/15 16:30:29 by sucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	check_token_counter(char *str, char delim, int count)
{
	int		i;
	char	**tokens;
	
	i = 0;
    tokens = ft_split(str, delim);
	while (tokens + i)
	{
		if (! *(tokens + i))
			break ;
		i++;
	}
	if (i != count)
		return (0);
	return (1);
}

int	check_identifier(char *str, char *head)
{
	char	**tokens;
	
    tokens = ft_split(str, ' ');
	if (ft_strncmp(tokens[0], head, ft_strlen(head)) == 0 && 
			(ft_strlen(tokens[0]) == ft_strlen(head)))
		return (0);
	return (1);
}

void	free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
