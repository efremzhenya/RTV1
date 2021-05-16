/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 04:48:03 by lseema            #+#    #+#             */
/*   Updated: 2021/05/16 18:06:13 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "scene.h"
#include "geometry.h"

t_vec3	correct_color(t_vec3 color)
{
	if (color.x > 255)
		color.x = 255;
	else if (color.x < 0)
		color.x = 0;
	if (color.y > 255)
		color.y = 255;
	else if (color.y < 0)
		color.y = 0;
	if (color.z > 255)
		color.z = 255;
	else if (color.z < 0)
		color.z = 0;
	return (color);
}

int	is_shadowed(t_scene *scene, t_object *object, t_vec3 p)
{
	t_vec3		l;
	t_object	*curr_obj;
	float		closest_dist;

	l = vec3_sub(scene->light->center, p);
	curr_obj = scene->objects;
	while (curr_obj)
	{
		if (curr_obj != object)
		{
			closest_dist = curr_obj->intersect(p, vec3_normalize(l), curr_obj);
			if (closest_dist > 0 && closest_dist < vec3_length(l))
				return (1);
		}
		curr_obj = curr_obj->next;
	}
	return (0);
}

t_vec3	get_color(float closest_dist, t_object *obj, t_ray ray, t_scene *scene)
{
	t_vec3	a[2];
	t_vec3	lighted_color;

	if (obj == NULL)
		return (vec3(0, 0, 0));
	a[0] = vec3_plus(scene->camera->origin,
			vec3_mult_value(ray.direction, closest_dist));
	a[1] = obj->get_normal(ray.direction,
			closest_dist, obj, scene->camera->origin);
	lighted_color = correct_color((vec3_mult_value(obj->color,
					compute_lightning(a, vec3_mult_value(ray.direction, -1.0),
						obj->specular, scene->light))));
	if (is_shadowed(scene, obj, a[0]))
		lighted_color = correct_color(vec3_mult_value(lighted_color, 0.9));
	return (lighted_color);
}
