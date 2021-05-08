/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 08:16:06 by lseema            #+#    #+#             */
/*   Updated: 2021/05/08 20:00:54 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "token_actions.h"

void		parse_cone(char const *json, t_jsmntok **tkn, t_scene **scene,
	int size)
{
	t_object	*object;
	t_cone_data	*cone_data;

	cone_data = (t_cone_data *)malloc(sizeof(t_cone_data));
	object = new_object(cone_data, OBJ_CONE, intersect_cone);
	while (--size)
	{
		if (json_eq(json, **tkn, "coordinates"))
		{
			++(*tkn);
			object->origin = token_to_vec3(json, tkn);
		}
		else if (json_eq(json, **tkn, "color"))
		{
			++(*tkn);
			object->color = token_to_color(json, tkn);
		}
		else if (json_eq(json, **tkn, "height"))
			cone_data->height = token_to_double(json, *(++(*tkn)));
		else if (json_eq(json, **tkn, "radius"))
			cone_data->radius = token_to_double(json, *(++(*tkn)));
		else if (json_eq(json, **tkn, "specular"))
			object->specular =  token_to_double(json, *(++(*tkn)));
		else
			terminate("Unexpected key in cone");
		(*tkn)++;
	}
	add_object(&(*scene)->objects, object);
}

float	intersect_cone(t_vec3 cam_origin, t_vec3 ray_dir, t_object *sphere)
{
	if (cam_origin.x && ray_dir.x && sphere)
	{
		//заглушка
	}
	return(INFINITY);
}
