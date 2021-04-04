/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:24:52 by lseema            #+#    #+#             */
/*   Updated: 2021/04/04 14:42:32 by lseema           ###   ########.fr       */
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
# define SPOT			"spot"
typedef enum			object_type
{
						OBJ_SPHERE,
						OBJ_CYLINDER,
						OBJ_PLANE,
						OBJ_CONE,
						OBJ_CAMERA,
						OBJ_SPOT
}						object_type;

typedef struct			s_object
{
	int					id;
	object_type			type;
	t_vec3				center;
	void*				data;
	struct s_object		*next;
	struct s_object		*prev;
}						t_object;

typedef struct			s_scene
{
	t_object			*objects;
}						t_scene;

typedef struct			s_sphere_data
{
	int					radius;
}						t_sphere_data;

typedef struct			s_cylinder_data
{
	int					height;
	int					radius;
}						t_cylinder_data;

typedef struct			s_plane_data
{
	int					width;
	int					height;
}						t_plane_data;

typedef struct			s_cone_data
{
	int					radius;
	int					height;
}						t_cone_data;

typedef struct			s_camera_data
{
}						t_camera_data;

struct					s_spot_data
{
}						t_spota_data;


void					parse_json(char const *json, t_scene **scene);
t_object				*new_object();
void					add_object(t_object **objects, t_object *object);
void					free_objects(t_object **objects);


#endif
