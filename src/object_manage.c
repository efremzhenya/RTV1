/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 08:00:32 by lseema            #+#    #+#             */
/*   Updated: 2021/05/17 22:09:35 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "scene.h"

t_object	*new_object(void *data, t_object_type type,
	float (*intersect)(t_vec3 cam_orig, t_vec3 ray_dir, struct s_object *))
{
	t_object	*object;

	object = (t_object *)malloc(sizeof(t_object));
	if (!(object))
		terminate("Allocate error");
	object->origin = vec3(0, 0, 0);
	object->color = vec3(0, 0, 0);
	object->specular = 0;
	object->data = data;
	object->type = type;
	object->intersect = intersect;
	object->next = NULL;
	object->prev = NULL;
	object->id = 0;
	return (object);
}

void	add_object(t_object **objects, t_object *object)
{
	t_object	*temp;

	if (*objects == NULL)
		(*objects) = object;
	else
	{
		temp = *objects;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = object;
		object->prev = temp;
		object->id = temp->id + 1;
	}
}

void	free_objects(t_object **objects)
{
	t_object	*temp;

	if (objects == NULL || *objects == NULL)
		return ;
	temp = *objects;
	while (temp->next != NULL)
	{
		if (temp->data != NULL)
			free(temp->data);
		temp = temp->next;
		free(temp->prev);
	}
	if (temp->data != NULL)
		free(temp->data);
	free(temp);
}
