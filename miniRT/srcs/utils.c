/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sucho <sucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:29:37 by sucho             #+#    #+#             */
/*   Updated: 2022/09/15 16:26:45 by sucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void print_error_and_exit(char *str)
{
	printf("Error\n");
	printf("%s\n", str);
	exit(1);
}

int	check_file_extention(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len <= 3)
		return (0);
	if (!(str[len - 3] == '.' && str[len - 2] == 'r' && str[len - 1] == 't'))
		return (0);
	return (1);
}
