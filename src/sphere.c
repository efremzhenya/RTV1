/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 14:46:15 by lseema            #+#    #+#             */
/*   Updated: 2021/04/04 14:49:29 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define JSMN_HEADER
#include "token_actions.h"

void		parse_sphere(char const *json, jsmntok_t **tkn, t_scene **scene,
	int size)
{
	t_object		*object;
	t_sphere_data	*sphere_data;

	sphere_data = (t_sphere_data *)malloc(sizeof(t_sphere_data));
	object = new_object(sphere_data, OBJ_SPHERE);
	object->data = sphere_data;
	while (--size)
	{
		if (json_eq(json, **tkn, "coordinates"))
		{
			++(*tkn);
			object->center = token_to_vec3(json, tkn);
		}
		else if (json_eq(json, **tkn, "radius"))
			sphere_data->radius = token_to_num(json, *(++(*tkn)));
		(*tkn)++;
	}
	add_object(&(*scene)->objects, object);
}
