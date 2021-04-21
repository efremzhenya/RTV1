/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   omnilight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 08:07:18 by lseema            #+#    #+#             */
/*   Updated: 2021/04/21 10:12:58 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "token_actions.h"

void		parse_omnilight(char const *json, jsmntok_t **tkn, t_scene **scene,
	int size)
{
	(*scene)->light = (t_omnilight *)malloc(sizeof(t_omnilight));
	while (--size)
	{
		if (json_eq(json, **tkn, "coordinates"))
		{
			++(*tkn);
			(*scene)->light->center = token_to_vec3(json, tkn);
		}
		else if (json_eq(json, **tkn, "color"))
		{
			++(*tkn);
			(*scene)->light->color = token_to_color(json, tkn);
		}
		else if (json_eq(json, **tkn, "brightness"))
			(*scene)->light->brightness = token_to_double(json, *(++(*tkn)));
		else
			terminate("Unexpected key in omnilight");
		(*tkn)++;
	}
}
