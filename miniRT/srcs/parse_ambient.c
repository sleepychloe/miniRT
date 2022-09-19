/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sucho <sucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:35:58 by sucho             #+#    #+#             */
/*   Updated: 2022/09/15 16:37:07 by sucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"



int parse_ambient_ratio(t_scene *scene, char *s)
{
	scene->ambient->ratio = s;
    return (1);
}

int	parse_ambient_rgb(t_scene *scene, char *s)
{
	char **c;

	c = ft_split(s, ',');
	if (!(0 <= ft_atoi(c[0]) && ft_atoi(c[0]) <= 255)
			|| !(0 <= ft_atoi(c[1]) && ft_atoi(c[1]) <= 255)
			|| !(0 <= ft_atoi(c[2]) && ft_atoi(c[2]) <= 255))
		return (0);
	scene->ambient->r = ft_atoi(c[0]);
	scene->ambient->g = ft_atoi(c[1]);
	scene->ambient->b = ft_atoi(c[2]);
	return (1);
}

void parse_ambient(t_scene *scene, char *s)
{
    char    **str;

	if (check_identifier(s, "A"))
		print_error_and_exit("Ambient identifier error");
	if (!check_token_counter(s, ' ', 3))
		print_error_and_exit("Ambient token error");
   	str = ft_split(s, ' ');
	if (!check_token_counter(str[2], ',', 3))
    	print_error_and_exit("Ambient token error (rgb)");
	scene->ambient = (t_ambient *)malloc(sizeof(t_ambient));
	if (!parse_ambient_ratio(scene, str[1]))
		print_error_and_exit("Ambient value error (ratio)");
	if (!parse_ambient_rgb(scene, str[2]))
		print_error_and_exit("Ambient value error (rgb)");
}
