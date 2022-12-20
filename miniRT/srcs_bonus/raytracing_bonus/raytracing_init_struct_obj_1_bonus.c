/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_init_struct_obj_1_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 07:42:51 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/20 09:36:40 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	put_value_obj_pl_dup_norminette(t_scene *scene,
				t_obj **obj, int n_obj, int i)
{
	obj[n_obj + i]->img_path
		= realloc_img_texture_path(obj[n_obj + i]->img_path,
			scene->plane[i]->img_path);
	obj[n_obj + i]->texture_path
		= realloc_img_texture_path(obj[n_obj + i]->texture_path,
			scene->plane[i]->texture_path);
}

void	put_value_obj_pl_dup(t_scene *scene, t_obj **obj, int n_obj)
{
	int	i;

	i = 0;
	while (i < scene->n_plane)
	{
		obj[n_obj + i]->obj_type = PLANE;
		obj[n_obj + i]->xyz_pos = scene->plane[i]->xyz_pos;
		obj[n_obj + i]->xyz_vec = scene->plane[i]->xyz_vec;
		obj[n_obj + i]->xyz_pos = vec3_sub_vec3(scene->plane[i]->xyz_pos,
				vec3_mul_rn(scene->plane[i]->xyz_vec, DELTA));
		obj[n_obj + i]->xyz_vec.x *= -1;
		obj[n_obj + i]->xyz_vec.y *= -1;
		obj[n_obj + i]->xyz_vec.z *= -1;
		obj[n_obj + i]->diameter = 0;
		obj[n_obj + i]->height = 0;
		obj[n_obj + i]->surface = scene->plane[i]->surface;
		obj[n_obj + i]->fuzz = scene->plane[i]->fuzz;
		obj[n_obj + i]->rgb1 = scene->plane[i]->rgb1;
		obj[n_obj + i]->rgb2 = scene->plane[i]->rgb2;
		put_value_obj_pl_dup_norminette(scene, obj, n_obj, i);
		i++;
	}
}

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

	n_obj = scene->n_sphere + scene->n_plane
		+ scene->n_cylinder + scene->n_cone;
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
	put_value_obj_co(scene, obj);
	put_value_obj_pl_dup(scene, obj, n_obj);
	return (obj);
}
