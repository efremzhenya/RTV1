/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:24:52 by lseema            #+#    #+#             */
/*   Updated: 2021/05/13 23:36:22 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "geometry.h"
# define JSON_EXTENSION	".json"
# define CONE			"cone"
# define SPHERE			"sphere"
# define PLANE			"plane"
# define CYLINDER		"cylinder"
# define CAMERA			"camera"
# define OMNILIGHT		"omnilight"
typedef enum			object_type
{
						OBJ_SPHERE,
						OBJ_CYLINDER,
						OBJ_PLANE,
						OBJ_CONE
}						object_type;

typedef struct			s_camera
{
	int					id;
	t_vec3				origin;
	t_vec3				direction;
	float				fov;
}						t_camera;
typedef struct			s_object
{
	int					id;
	object_type			type;
	t_vec3				origin;
	t_vec3				color;
	float				specular;
	void*				data;
	float				(*intersect)(t_vec3 cam_origin, t_vec3 ray_dir, struct s_object *);
	t_vec3				(*get_normal)(t_vec3 ray_dir, float closest_dist,
		struct s_object *obj, t_vec3 origin_cam);
	struct s_object		*next;
	struct s_object		*prev;
}						t_object;

typedef struct			s_omnilight
{
	int					id;
	t_vec3				center;
	t_vec3				color;
	float				brightness;
}						t_omnilight;

typedef struct			s_scene
{
	t_object			*objects;
	t_camera			*camera;
	t_omnilight			*light;
	int					width;
	int					height;
}						t_scene;

typedef struct			s_sphere_data
{
	float				radius;
}						t_sphere_data;

typedef struct			s_cylinder_data
{
	float				radius;
	t_vec3				normal;
}						t_cylinder_data;

typedef struct			s_plane_data
{
	t_vec3				normal;
}						t_plane_data;

typedef struct			s_cone_data
{
	float				angle;
	t_vec3				normal;
}						t_cone_data;

typedef struct			s_hit
{
	float				distance;
	t_object			*object;
}						t_hit;


t_scene					*init_scene();
void					free_scene(t_scene **scene);
void					parse_json(char const *json, t_scene **scene);
t_object				*new_object(void* data, object_type type,
float (*intersect)(t_vec3 cam_origin, t_vec3 ray_dir, struct s_object *));
void					add_object(t_object **objects, t_object *object);
void					free_objects(t_object **objects);
float					intersect_sphere(t_vec3 cam_origin, t_vec3 ray_dir, t_object *sphere);
float					intersect_plane(t_vec3 cam_origin, t_vec3 ray_dir, t_object *plane);
float					intersect_cylinder(t_vec3 cam_origin, t_vec3 ray_dir, t_object *cylinder);
float					intersect_cone(t_vec3 cam_origin, t_vec3 ray_dir, t_object *sphere);
float					compute_lightning(t_vec3 P, t_vec3 N, t_vec3 V, float s, t_omnilight *light);
t_vec3					get_color(float closest_dist, t_object *object, t_ray ray, t_scene *scene);
t_vec3					get_normal_sphere(t_vec3 ray_dir, float closest_dist, struct s_object *obj, t_vec3 cam_origin);
t_vec3					get_normal_cone(t_vec3 ray_dir, float closest_dist,struct s_object *obj, t_vec3 cam_origin);

#endif
