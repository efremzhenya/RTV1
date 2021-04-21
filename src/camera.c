/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 08:28:46 by lseema            #+#    #+#             */
/*   Updated: 2021/04/21 10:16:04 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "token_actions.h"

void	parse_camera(char const *json, jsmntok_t **tkn, t_scene **scene,
	int size)
{
	(*scene)->camera = (t_camera*)malloc(sizeof(t_camera));
	while (--size)
	{
		if (json_eq(json, **tkn, "coordinates"))
		{
			++(*tkn);
			(*scene)->camera->center = token_to_vec3(json, tkn);
		}
		else if (json_eq(json, **tkn, "orientation"))
		{
			++(*tkn);
			(*scene)->camera->orientation = token_to_vec3(json, tkn);
		}
		else if (json_eq(json, **tkn, "fov"))
			(*scene)->camera->fov = token_to_double(json, *(++(*tkn)));
		else
			terminate("Unexpected key in camera");
		(*tkn)++;
	}
}

t_camera *new_camera(t_vec3 center, t_vec3 orientation, float fov)
{
	t_camera *camera;

	camera = (t_camera*)malloc(sizeof(t_camera));
	camera->center = center;
	camera->orientation = orientation;
	camera->fov = fov;
	return (camera);
}
