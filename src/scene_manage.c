/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:18:29 by lseema            #+#    #+#             */
/*   Updated: 2021/05/16 17:45:24 by mellie           ###   ########.fr       */
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
	return (scene);
}
