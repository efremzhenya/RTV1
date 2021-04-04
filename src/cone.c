/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 08:16:06 by lseema            #+#    #+#             */
/*   Updated: 2021/04/04 14:33:00 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define JSMN_HEADER
#include "token_actions.h"

void		parse_cone(char const *json, jsmntok_t **tkn, t_scene **scene,
	int size)
{
	t_object	*object;
	t_cone_data	*cone_data;

	cone_data = (t_cone_data *)malloc(sizeof(t_cone_data));
	object = new_object(cone_data, OBJ_CONE);
	object->data = cone_data;
	while (--size)
	{
		if (json_eq(json, **tkn, "coordinates"))
		{
			++(*tkn);
			object->center = token_to_vec3(json, tkn);
		}
		else if (json_eq(json, **tkn, "height"))
			cone_data->height = token_to_num(json, *(++(*tkn)));
		else if (json_eq(json, **tkn, "radius"))
			cone_data->radius = token_to_num(json, *(++(*tkn)));
		(*tkn)++;
	}
	add_object(&(*scene)->objects, object);
}
