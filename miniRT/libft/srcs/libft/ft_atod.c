/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:38:42 by yhwang            #+#    #+#             */
/*   Updated: 2022/09/19 18:27:12 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_init(int *sign, int *nbr, int *cnt_zero, double *decimal_point)
{
	*sign = 1;
	*nbr = 0;
	*cnt_zero = 0;
	*decimal_point = 0.0;
}

double	ft_atod(const char *str)
{
	int		sign;
	int		nbr;
	int		cnt_zero;
	double	decimal_point;

	ft_init(&sign, &nbr, &cnt_zero, &decimal_point);
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
		nbr = nbr * 10 + (*str++ - '0');
	if (*str == '.')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		decimal_point = decimal_point * 10 + (*str++ - '0');
		cnt_zero++;
	}
	while (cnt_zero-- || decimal_point >= 1)
		decimal_point /= 10;
	return (sign * (nbr + decimal_point));
}
