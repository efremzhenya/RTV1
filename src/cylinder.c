/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 14:50:58 by lseema            #+#    #+#             */
/*   Updated: 2021/05/08 16:34:35 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "token_actions.h"

t_vec3	get_normal_cylinder(t_vec3 ray_dir, float closest_dist,
	struct s_object *obj, t_vec3 cam_origin)
{
	t_cylinder_data *data;
	float m;
	t_vec3 vecs[3];

	data = obj->data;
	data->normal = vec3_normalize(data->normal);

	m = vec3_dot_product(ray_dir, vec3_mult_value(data->normal, closest_dist)) +
	 vec3_dot_product(vec3_sub(cam_origin, obj->origin), data->normal);
	vecs[0] = vec3_plus(vec3_mult_value(ray_dir, closest_dist), cam_origin);
	vecs[1] = vec3_sub(vecs[0], obj->origin);
	vecs[2] = vec3_mult_value(data->normal, m);
	return (vec3_normalize(vec3_sub(vecs[1], vecs[2])));
}

void		parse_cylinder(char const *json, jsmntok_t **tkn, t_scene **scene,
	int size)
{
	t_object		*object;
	t_cylinder_data	*cylinder_data;

	cylinder_data = (t_cylinder_data *)malloc(sizeof(t_cylinder_data));
	object = new_object(cylinder_data, OBJ_CYLINDER, intersect_cylinder);
	object->get_normal = get_normal_cylinder;
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
			cylinder_data->normal = token_to_vec3(json, tkn);
		}
		else if (json_eq(json, **tkn, "color"))
		{
			++(*tkn);
			object->color = token_to_color(json, tkn);
		}
		else if (json_eq(json, **tkn, "radius"))
			cylinder_data->radius = token_to_double(json, *(++(*tkn)));
		else if (json_eq(json, **tkn, "specular"))
			object->specular =  token_to_double(json, *(++(*tkn)));
		else
			terminate("Unexpected key in cylinder");
		(*tkn)++;
	}
	add_object(&(*scene)->objects, object);
}

float		intersect_cylinder(t_vec3 cam_origin, t_vec3 ray_dir, t_object *cylinder)
{
	t_vec3	cyl_cam;
	t_vec3	direction;
	t_cylinder_data *data;
	t_quadric_eq quadric;

	data = cylinder->data;
	cyl_cam = vec3_sub(cam_origin, cylinder->origin);
	direction = vec3_normalize(data->normal);
	quadric.a = vec3_dot_product(ray_dir, ray_dir)
		- pow(vec3_dot_product(ray_dir, direction), 2);
	quadric.b = 2 * (vec3_dot_product(ray_dir, cyl_cam)
		- vec3_dot_product(ray_dir, direction)
		* vec3_dot_product(cyl_cam, direction));
	quadric.c = vec3_dot_product(cyl_cam, cyl_cam)
		- pow(vec3_dot_product(cyl_cam, direction), 2) - pow(data->radius, 2);
	quadric.discr = quadric.b * quadric.b - 4 * quadric.a * quadric.c;
	if (quadric.discr < 0)
		return (0);
	quadric.root1 = ((-quadric.b) + sqrt(quadric.discr)) / (2 * quadric.a);
	quadric.root2 = ((-quadric.b) - sqrt(quadric.discr)) / (2 * quadric.a);
	if (quadric.root1 < quadric.root2)
		return (quadric.root1);
	else
		return (quadric.root2);
}
