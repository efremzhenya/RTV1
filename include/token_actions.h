/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_actions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:29:30 by lseema            #+#    #+#             */
/*   Updated: 2021/04/04 09:54:37 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JSMN_USES_H
# define JSMN_USES_H

# include "scene.h"
# include "geometry.h"
# include "../external_libs/jsmn/jsmn.h"

int 					json_eq(const char *json, jsmntok_t token, const char *s);
void					objects_parse_wrapper(char const *json, jsmntok_t **t, t_scene **scene);
void					object_parse_switch(char const *json, jsmntok_t **t, t_scene **scene, int size);
void					parse_cone(char const *json, jsmntok_t **t, t_scene **scene, int size);
char					*token_to_str(const char *json, jsmntok_t tkn);
long long				token_to_num(const char *json, jsmntok_t tkn);
t_vec3					token_to_vec3(char const *json, jsmntok_t **t);

#endif
