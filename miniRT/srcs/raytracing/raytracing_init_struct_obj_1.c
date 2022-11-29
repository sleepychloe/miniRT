/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_init_struct_obj_1.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 07:42:51 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/29 22:53:29 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	norminette_init_obj(t_scene *scene, t_obj **obj, int n_obj)
{
	int	i;

	i = 0;
	while (i < n_obj + scene->n_plane)
	{
		obj[i] = (t_obj *)ft_calloc(sizeof(t_obj), 2);
		if (!obj[i])
		{
			err_msg("Malloc error\n");
			free_obj(obj);
			free_scene(scene);
			exit (1);
		}
		i++;
	}
}

t_obj	**init_obj(t_scene *scene)
{
	t_obj	**obj;
	int		n_obj;

	n_obj = scene->n_sphere + scene->n_plane + scene->n_cylinder;
	obj = (t_obj **)ft_calloc(sizeof(t_obj *),
			n_obj + scene->n_plane + 1);
	if (!obj)
	{
		err_msg("Malloc error");
		free_scene(scene);
		exit (1);
	}
	norminette_init_obj(scene, obj, n_obj);
	put_value_obj_sp(scene, obj);
	put_value_obj_pl(scene, obj);
	put_value_obj_cy(scene, obj);
	put_value_obj_pl_dup(scene, obj, n_obj);
	return (obj);
}
