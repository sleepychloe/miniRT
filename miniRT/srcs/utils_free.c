/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:58:07 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/21 04:03:26 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	*ft_realloc(void *old_ptr, size_t old_len, size_t new_len)
{
	char	*new_ptr;

	new_ptr = malloc(new_len);
	if (!new_ptr)
		return (NULL);
	ft_bzero(new_ptr, new_len);
	ft_memcpy(new_ptr, old_ptr, old_len);
	free(old_ptr);
	return (new_ptr);
}

void	ft_free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_free_all_2d(char **token, char **xyz_pos, char **xyz_vec, char **rgb)
{
	if (token != NULL)
		ft_free_2d(token);
	if (xyz_pos != NULL)
		ft_free_2d(xyz_pos);
	if (xyz_vec != NULL)
		ft_free_2d(xyz_vec);
	if (rgb != NULL)
		ft_free_2d(rgb);
}

void	ft_free_struct(t_scene *scene)
{
	int	i;

	free(scene->ambient);
	free(scene->camera);
	free(scene->light);
	i = 0;
	while (scene->sphere[i])
		free(scene->sphere[i++]);
	free(scene->sphere);
	i = 0;
	while (scene->plane[i])
		free(scene->plane[i++]);
	free(scene->plane);
	i = 0;
	while (scene->cylinder[i])
		free(scene->cylinder[i++]);
	free(scene->cylinder);
	free(scene);
}

void	ft_free_3d(char ***str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (*str[i])
			ft_free_2d(str[i++]);
	}
	free(str);
}
