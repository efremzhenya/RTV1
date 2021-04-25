/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:14:38 by lseema            #+#    #+#             */
/*   Updated: 2021/04/25 18:38:15 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3		*ray_trace(t_scene *scene)
{
	int			x;
	int			y;
	t_view		*view;
	t_ray		ray;
	t_vec3		*framebuffer;
	t_object	*object;
	float		t;
	float		t_min;
	t_vec3		t_color;

	view = init_view(scene->width, scene->height, scene->camera->fov);
	ray.origin.z = -1;
	framebuffer = (t_vec3 *)malloc(sizeof(t_vec3) * scene->height * scene->width);
		y = 0;
		while (y < scene->height)
		{
			ray.origin.y = ((scene->height / 2) - y) * view->y;
			x = 0;
			while (x < scene->width)
			{
				ray.origin.x = ((scene->width / 2) * (-1) + x) * view->y;
				ray.direction = vec3_normalize(ray.origin);
				object = scene->objects;
				t_min = INFINITY;
				t_color = vec3(0, 0, 0);
				while (object)
				{
					t = object->intersect(scene->camera, ray, object);
					if (t > 0 && t < t_min)
					{
						t_min = t;
						t_color = object->color;
					}
					object = object->next;
				}
				framebuffer[x + scene->width * y] = t_color;
				x++;
			}
			y++;
	}
	return (framebuffer);
}

t_view	*init_view(float width, float height, float fov)
{
	t_view	*view;
	float	aspect_ratio;

	view = (t_view*)malloc(sizeof(t_view));
	if (!view)
		terminate(ERR_MALLOC);
	aspect_ratio = width / height;
	view->width = tan(fov / 2 * (M_PI / 180)) * 2;
	view->height = view->width / aspect_ratio;
	view->x = view->width / width;
	view->y = view->height / height;
	return (view);
}
