/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:14:38 by lseema            #+#    #+#             */
/*   Updated: 2021/05/17 21:10:11 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	*get_frame(t_scene *scene, int y)
{
	int			x;
	t_vec3		*frame;
	t_view		*view;
	t_ray		ray;

	frame = init_frame(&frame, scene->height, scene->width);
	transform_scene(scene);
	view = init_view(scene->width, scene->height, scene->camera->fov);
	ray.origin.z = -1;
	while (y < scene->height)
	{
		ray.origin.y = ((scene->height / 2.0) - y) * view->y;
		x = 0;
		while (x < scene->width)
		{
			ray.origin.x = ((scene->width / 2.0) * (-1) + x) * view->x;
			ray.direction = vec3_normalize(ray.origin);
			frame[x + scene->width * y] = ray_trace(ray, scene);
			x++;
		}
		y++;
	}
	free(view);
	return (frame);
}

t_vec3	ray_trace(t_ray ray, t_scene *scene)
{
	t_object	*object;
	float		distance;
	float		min_distance;
	t_object	*closest;

	object = scene->objects;
	min_distance = INFINITY;
	closest = NULL;
	while (object)
	{
		distance = object->intersect(scene->camera->origin,
				ray.direction, object);
		if (distance > 0.00001 && distance < min_distance)
		{
			min_distance = distance;
			closest = object;
		}
		object = object->next;
	}
	return (get_color(min_distance, closest, ray, scene));
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

void	transform_obj(t_object **obj, t_scene **scene)
{
	t_cylinder_data	*cyl;
	t_cone_data		*cone;
	t_plane_data	*plane;

	if ((*obj)->type == OBJ_PLANE)
	{
		plane = (*obj)->data;
		(*obj)->origin = mat_mult_vec((*obj)->origin,
				(*scene)->camera->look_at);
		plane->normal = mat_mult_vec(plane->normal, (*scene)->camera->rotation);
	}
	else if ((*obj)->type == OBJ_CYLINDER)
	{
		cyl = (*obj)->data;
		(*obj)->origin = mat_mult_vec((*obj)->origin,
				(*scene)->camera->look_at);
		cyl->normal = mat_mult_vec(cyl->normal, (*scene)->camera->rotation);
	}
	else if ((*obj)->type == OBJ_CONE)
	{
		cone = (*obj)->data;
		(*obj)->origin = mat_mult_vec((*obj)->origin,
				(*scene)->camera->look_at);
		cone->normal = mat_mult_vec(cone->normal, (*scene)->camera->rotation);
	}
}

void	transform_scene(t_scene *scene)
{
	t_object		*obj;

	obj = scene->objects;
	scene->camera->rotation = rotation_matrix(scene->camera->origin,
			scene->camera->direction);
	scene->camera->transform = translation_matrix(scene->camera->origin);
	scene->camera->look_at = mat44f_mult(scene->camera->transform,
			scene->camera->rotation);
	while (obj)
	{
		if (obj->type == OBJ_SPHERE)
			obj->origin = mat_mult_vec(obj->origin,
					scene->camera->look_at);
		else
			transform_obj(&obj, &scene);
		obj = obj->next;
	}
	scene->light->center = mat_mult_vec(scene->light->center,
			scene->camera->look_at);
	scene->camera->origin = mat_mult_vec(scene->camera->origin,
			scene->camera->look_at);
}
