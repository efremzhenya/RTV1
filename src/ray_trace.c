/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:14:38 by lseema            #+#    #+#             */
/*   Updated: 2021/05/08 16:56:41 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	*get_frame(t_scene *scene)
{
	int			x;
	int			y;
	t_vec3		*frame;
	t_view		*view;
	t_ray		ray;

	frame = (t_vec3 *)malloc(sizeof(t_vec3) * scene->height * scene->width);
	if (!frame)
		terminate(ERR_MALLOC);
	view = init_view(scene->width, scene->height, scene->camera->fov);
	ray.origin.z = -1;
	y = 0;
	while (y < scene->height)
	{
		ray.origin.y = ((scene->height / 2) - y) * view->y;
		x = 0;
		while (x < scene->width)
		{
			frame[x + scene->width * y] = ray_trace(x, view->y, ray, scene);
			x++;
		}
		y++;
	}
	return (frame);
}

t_vec3	ray_trace(int x, float view_y, t_ray ray, t_scene *scene)
{
	t_object	*object;
	float		distance;
	float		min_distance;
	t_object	*closest;

	ray.origin.x = ((scene->width / 2) * (-1) + x) * view_y;
	ray.direction = vec3_normalize(ray.origin);
	object = scene->objects;
	min_distance = INFINITY;
	closest = NULL;
	while (object)
	{
		distance = object->intersect(scene->camera->origin, ray.direction, object);
		if (distance > 0.00001 && distance < min_distance)
		{
			min_distance = distance;
			closest = object;
		}
		object = object->next;
	}
	return get_color(min_distance, closest, ray, scene);
}

t_view	*init_view(float width, float height, float fov)
{
	t_view	*view;
	float	aspect_ratio;
	float	theta_radians;

	view = (t_view *)malloc(sizeof(t_view));
	if (!view)
		terminate(ERR_MALLOC);
	aspect_ratio = width / height;
	theta_radians = fov / 2.0 * (M_PI / 180.0);
	view->width = tan(theta_radians) * 2;
	view->height = view->width / aspect_ratio;
	view->x = view->width / width;
	view->y = view->height / height;
	return (view);
}
