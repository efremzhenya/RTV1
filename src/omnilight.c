/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   omnilight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 08:07:18 by lseema            #+#    #+#             */
/*   Updated: 2021/04/04 08:26:56 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define JSMN_HEADER
#include "token_actions.h"

void		parse_omnilight(char const *json, jsmntok_t **tkn, t_scene **scene,
	int size)
{
	t_object			*object;
	t_ominlight_data	*light_data;

	light_data = (t_ominlight_data *)malloc(sizeof(t_ominlight_data));
	object = new_object(light_data, OBJ_OMNILIGHT);
	object->data = light_data;
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
