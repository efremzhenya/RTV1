/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 08:28:46 by lseema            #+#    #+#             */
/*   Updated: 2021/04/04 08:42:14 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define JSMN_HEADER
#include "token_actions.h"

void		parse_camera(char const *json, jsmntok_t **tkn, t_scene **scene,
	int size)
{
	t_object		*object;
	t_camera_data	*camera_data;

	camera_data = (t_camera_data *)malloc(sizeof(t_camera_data));
	object = new_object(camera_data, OBJ_CAMERA);
	object->data = camera_data;
	while (--size)
	{
		if (json_eq(json, **tkn, "coordinates"))
		{
			++(*tkn);
			object->center = token_to_vec3(json, tkn);
		}
		(*tkn)++;
	}
	add_object(&(*scene)->objects, object);
}
