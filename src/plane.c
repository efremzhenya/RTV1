/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 14:53:33 by lseema            #+#    #+#             */
/*   Updated: 2021/04/04 08:06:20 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define JSMN_HEADER
#include "token_actions.h"

void		parse_plane(char const *json, jsmntok_t **tkn, t_scene **scene,
	int size)
{
	t_object		*object;
	t_plane_data	*plane_data;

	plane_data = (t_plane_data *)malloc(sizeof(t_plane_data));
	object = new_object(plane_data, OBJ_PLANE);
	object->data = plane_data;
	while (--size)
	{
		if (json_eq(json, **tkn, "coordinates"))
		{
			++(*tkn);
			object->center = token_to_vec3(json, tkn);
		}
		else if (json_eq(json, **tkn, "height"))
			plane_data->height = token_to_num(json, *(++(*tkn)));
		else if (json_eq(json, **tkn, "width"))
			plane_data->width = token_to_num(json, *(++(*tkn)));
		else if (json_eq(json, **tkn, "length"))
			plane_data->length = token_to_num(json, *(++(*tkn)));
		(*tkn)++;
	}
	add_object(&(*scene)->objects, object);
}
