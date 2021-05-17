/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 08:28:46 by lseema            #+#    #+#             */
/*   Updated: 2021/05/17 22:17:31 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "token_actions.h"

t_camera	*new_camera(void)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	camera->origin = vec3(0, 0, 0);
	camera->direction = vec3(0, 0, 1);
	camera->fov = 60;
	return (camera);
}

void	parse_camera(char const *json, t_jsmntok **tkn, t_scene **scene,
	int size)
{
	(*scene)->camera = new_camera();
	while (--size)
	{
		if (json_eq(json, **tkn, "coordinates"))
		{
			++(*tkn);
			(*scene)->camera->origin = token_to_vec3(json, tkn);
		}
		else if (json_eq(json, **tkn, "lookat"))
		{
			++(*tkn);
			(*scene)->camera->direction = token_to_vec3(json, tkn);
		}
		else if (json_eq(json, **tkn, "fov"))
		{
			(*scene)->camera->fov = token_to_double(json, *(++(*tkn)));
			if (((*scene)->camera->fov) < 1)
				terminate("Invalid data");
		}
		else
			terminate("Unexpected key in camera");
		(*tkn)++;
	}
}
