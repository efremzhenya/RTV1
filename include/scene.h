/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:24:52 by lseema            #+#    #+#             */
/*   Updated: 2021/04/03 22:18:27 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "geometry.h"
# include "../external_libs/jsmn/jsmn.h"

typedef enum			object_type
{
						SPHERE,
						CYLINDER,
						PLANE,
						CONE,
						CAMERA,
						SPOT
}						object_type;

typedef struct			s_object
{
	int					id;
	object_type			object;
	t_vec3				center;
	void*				data;
}						t_object;

typedef struct			s_scene
{
	t_object			**objects;
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


void					parse_sphere();


void					parse_json(char const *json, t_scene **scene);
void					objects_parse_wrapper(char const *json, jsmntok_t **t, t_scene **scene);
void					object_parse_switch(char const *json, jsmntok_t **t, t_scene **scene, int size);
void					parse_cone(char const *json, jsmntok_t **t, t_scene **scene, int size);
char					*get_token_value_str(const char *json, jsmntok_t tkn);
long long				get_token_value_num(const char *json, jsmntok_t tkn);
t_vec3					parse_coordiantes(char const *json, jsmntok_t **t);

#endif
