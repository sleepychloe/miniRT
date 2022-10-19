/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:38:31 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/19 22:41:52 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_valid_atoi(int c)
{
	return (c == '-' || ('0' <= c && c <= '9'));
}

int	check_valid_str_atoi(const char *str)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(str))
	{
		if (!check_valid_atoi(str[i++]))
			return (1);
	}
	return (0);
}

int	ft_atoi_start(const char *str)
{
	long	sign;
	long	nbr;
	size_t	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	nbr = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (sign * nbr);
}

int	ft_atoi(const char *str)
{
	if (check_valid_str_atoi(str))
		return (-9999);
	else
		return (ft_atoi_start(str));
}