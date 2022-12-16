/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:37:32 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/16 05:24:36 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

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

int	check_comma(char *str)
{
	if (str[0] == ',' || str[ft_strlen(str) - 1] == ',')
		return (1);
	while (str)
	{
		if (*str == ',')
		{
			str++;
			break ;
		}
		str++;
	}
	if (*str == ',')
		return (1);
	while (str)
	{
		if (*str == ',')
		{
			str++;
			break ;
		}
		str++;
	}
	if (*str == ',')
		return (1);
	return (0);
}

int	check_comma_surface_flag(char *str)
{
	if (str[0] == ',' || str[ft_strlen(str) - 1] == ',')
		return (1);
	while (str)
	{
		if (*str == ',')
		{
			str++;
			break ;
		}
		str++;
	}
	if (*str == ',')
		return (1);
	return (0);
}

int	check_texture_img_extention(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len <= 4)
		return (1);
	if (!(str[len - 4] == '.' && str[len - 3] == 'x'
			&& str[len - 2] == 'p' && str[len - 1] == 'm'))
		return (1);
	return (0);
}
