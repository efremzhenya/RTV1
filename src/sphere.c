/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 14:46:15 by lseema            #+#    #+#             */
/*   Updated: 2021/04/25 18:38:09 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
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
			object->origin = token_to_vec3(json, tkn);
		}
		else if (json_eq(json, **tkn, "color"))
		{
			++(*tkn);
			object->color = token_to_color(json, tkn);
		}
		else if (json_eq(json, **tkn, "radius"))
			sphere_data->radius = token_to_double(json, *(++(*tkn)));
		else
			terminate("Unexpected key on sphere");
		(*tkn)++;
	}
	object->intersect = intersect_sphere;
	add_object(&(*scene)->objects, object);
}

float		intersect_sphere(t_camera *cam, t_ray ray, t_object *sphere)
{
	float b;
	float c;
	float discrim;
	float distance1;
	float distance2;
	t_vec3 cam_sphere;
	t_sphere_data	*params;

	params = sphere->data;
	distance1 = 0;
	distance2 = 0;
	cam_sphere = vec3_sub(cam->origin, sphere->origin);
	b = 2 * (vec3_dot_product(cam_sphere, ray.direction));
	c = vec3_dot_product(cam_sphere, cam_sphere) - (params->radius * params->radius);
	discrim = (b * b) - (4 * c);
	if (discrim >= 0)
	{
		b *= -1;
		distance1 = (b - sqrt(discrim)) / 2.0;
		distance2 = (b + sqrt(discrim)) / 2.0;
		if (distance1 > 0)
			return (distance1);
	}
	return (0);
}
