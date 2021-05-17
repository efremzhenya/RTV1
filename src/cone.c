/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 08:16:06 by lseema            #+#    #+#             */
/*   Updated: 2021/05/17 20:16:30 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "token_actions.h"
#include "geometry.h"

t_vec3	get_normal_cone(t_vec3 ray_dir, float closest_dist,
	struct s_object *obj, t_vec3 cam_origin)
{
	t_cone_data	*data;
	float		m;
	t_vec3		vecs[3];
	float		k;

	data = obj->data;
	data->normal = vec3_normalize(data->normal);
	k = tan(data->angle / 2.0 * (M_PI / 180.0));
	k = k * k + 1;
	m = vec3_dot(ray_dir, vec3_mult_value(data->normal, closest_dist))
		+ vec3_dot(vec3_sub(cam_origin, obj->origin), data->normal);
	 m = m * k;
	vecs[0] = vec3_plus(vec3_mult_value(ray_dir, closest_dist), cam_origin);
	vecs[1] = vec3_sub(vecs[0], obj->origin);
	vecs[2] = vec3_mult_value(data->normal, m);
	return (vec3_normalize(vec3_sub(vecs[1], vecs[2])));
}

void	parse_cone(char const *json, t_jsmntok **tkn, t_scene **scene,
	int size)
{
	t_object	*object;
	t_cone_data	*cone_data;

	cone_data = (t_cone_data *)malloc(sizeof(t_cone_data));
	object = new_object(cone_data, OBJ_CONE, intersect_cone);
	object->get_normal = get_normal_cone;
	while (--size)
	{
		if (!parse_obj(json, tkn, &object))
		{
			if (json_eq(json, **tkn, "normal"))
			{
				++(*tkn);
				cone_data->normal = token_to_vec3(json, tkn);
			}
			else if (json_eq(json, **tkn, "angle"))
				cone_data->angle = token_to_double(json, *(++(*tkn)));
			else
				terminate("Unexpected key in cone");
		}
		(*tkn)++;
	}
	add_object(&(*scene)->objects, object);
}

float	intersect_cone(t_vec3 cam_origin, t_vec3 ray_dir, t_object *cone)
{
	t_vec3			cone_cam;
	t_vec3			cone_dir;
	t_cone_data		*data;
	t_quadric_eq	quadric;
	float			k;

	data = cone->data;
	cone_cam = vec3_sub(cam_origin, cone->origin);
	cone_dir = vec3_normalize(data->normal);
	k = pow(tan(data->angle / 2.0 * (M_PI / 180.0)), 2) + 1;
	quadric.a = vec3_dot(ray_dir, ray_dir) - k
		* pow(vec3_dot(ray_dir, cone_dir), 2);
	quadric.b = 2 * vec3_dot(ray_dir, cone_cam) - 2 * k
		* vec3_dot(ray_dir, cone_dir) * vec3_dot(cone_cam, cone_dir);
	quadric.c = vec3_dot(cone_cam, cone_cam)
		- k * pow(vec3_dot(cone_cam, cone_dir), 2);
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
