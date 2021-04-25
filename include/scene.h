/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:24:52 by lseema            #+#    #+#             */
/*   Updated: 2021/04/25 18:38:00 by lseema           ###   ########.fr       */
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
	void*				data;
	float				(*intersect)(t_camera *, t_ray, struct s_object *);
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
	float				height;
	float				radius;
}						t_cylinder_data;

typedef struct			s_plane_data
{
	float				width;
	float				height;
	float				length;
}						t_plane_data;

typedef struct			s_cone_data
{
	float				radius;
	float				height;
}						t_cone_data;

t_scene					*init_scene();
void					free_scene(t_scene **scene);
void					parse_json(char const *json, t_scene **scene);
t_object				*new_object();
void					add_object(t_object **objects, t_object *object);
void					free_objects(t_object **objects);
float					intersect_sphere(t_camera *cam, t_ray ray, t_object *sphere);

#endif
