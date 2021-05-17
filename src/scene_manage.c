/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:18:29 by lseema            #+#    #+#             */
/*   Updated: 2021/05/17 22:25:55 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "scene.h"

void	free_scene(t_scene **scene)
{
	free_objects(&(*scene)->objects);
	free((*scene)->camera);
	free((*scene)->light);
	free(*scene);
	*scene = NULL;
}

t_scene	*init_scene(void)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	scene->objects = NULL;
	scene->camera = NULL;
	scene->light = NULL;
	scene->height = 0;
	scene->width = 0;
	return (scene);
}

t_vec3	*init_frame(t_vec3 **frame, int height, int width)
{
	*frame = (t_vec3 *)malloc(sizeof(t_vec3) * height * width);
	if (!*frame)
		terminate(ERR_MALLOC);
	return (*frame);
}
