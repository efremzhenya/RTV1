/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 14:53:33 by lseema            #+#    #+#             */
/*   Updated: 2021/05/08 16:35:01 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define JSMN_HEADER
#include "token_actions.h"

t_vec3	get_normal_plane(t_vec3 ray_dir, float closest_dist, struct s_object *obj, t_vec3 cam_origin)
{
	t_plane_data *data;

	ray_dir.x = ray_dir.x;
	closest_dist = closest_dist + 1;
	cam_origin.x = cam_origin.x;
	data = obj->data;
	return (vec3_normalize(data->normal));
}

void		parse_plane(char const *json, jsmntok_t **tkn, t_scene **scene,
	int size)
{
	t_object		*object;
	t_plane_data	*plane_data;

	plane_data = (t_plane_data *)malloc(sizeof(t_plane_data));
	object = new_object(plane_data, OBJ_PLANE, intersect_plane);
	object->get_normal = get_normal_plane;
	while (--size)
	{
		if (json_eq(json, **tkn, "coordinates"))
		{
			++(*tkn);
			object->origin = token_to_vec3(json, tkn);
		}
		else if (json_eq(json, **tkn, "normal"))
		{
			++(*tkn);
			plane_data->normal = token_to_vec3(json, tkn);
		}
		else if (json_eq(json, **tkn, "color"))
		{
			++(*tkn);
			object->color = token_to_color(json, tkn);
		}
		else if (json_eq(json, **tkn, "specular"))
			object->specular =  token_to_double(json, *(++(*tkn)));
		else
			terminate("Unexpected key on plane");
		(*tkn)++;
	}
	add_object(&(*scene)->objects, object);
}

float	intersect_plane(t_vec3 cam_origin, t_vec3 ray_dir, t_object *plane)
{
	float distance;
	float denom;
	float projection;
	t_plane_data *data;

	data = plane->data;
	denom = vec3_dot_product(data->normal, ray_dir);
	projection = vec3_dot_product(cam_origin, data->normal)
		- vec3_dot_product(data->normal, plane->origin);
	if (denom < 0.0001 && denom > -0.0001)
		return (0);
	distance = projection / denom * -1;
	if (distance < 0)
		return (0);
	return (distance);
}
