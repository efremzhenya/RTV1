/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_actions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:29:30 by lseema            #+#    #+#             */
/*   Updated: 2021/05/17 20:12:59 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_ACTIONS_H
# define TOKEN_ACTIONS_H
# include "scene.h"
# include "geometry.h"
# include "../external_libs/jsmn/jsmn.h"

int						json_eq(const char *json, t_jsmntok token,
							const char *s);
int						is_file_format(char *file, char *format);
char					*read_all_text(int fd);
int						parse_obj(char const *json, t_jsmntok **tkn,
							t_object	**object);
void					objects_parse_wrapper(char const *json, t_jsmntok **t,
							t_scene **scene);
void					object_parse_switch(char const *json, t_jsmntok **t,
							t_scene **scene, int size);
char					*token_to_str(const char *json, t_jsmntok tkn);
long long				token_to_num(const char *json, t_jsmntok tkn);
double					token_to_double(const char *json, t_jsmntok tkn);
t_vec3					token_to_vec3(char const *json, t_jsmntok **t);
t_vec3					token_to_color(char const *json, t_jsmntok **t);
void					parse_cone(char const *json, t_jsmntok **t,
							t_scene **scene, int size);
void					parse_sphere(char const *json, t_jsmntok **tkn,
							t_scene **scene, int size);
void					parse_omnilight(char const *json, t_jsmntok **tkn,
							t_scene **scene, int size);
void					parse_cylinder(char const *json, t_jsmntok **tkn,
							t_scene **scene, int size);
void					parse_plane(char const *json, t_jsmntok **tkn,
							t_scene **scene, int size);
void					parse_camera(char const *json, t_jsmntok **tkn,
							t_scene **scene, int size);

#endif
