/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 08:48:38 by lseema            #+#    #+#             */
/*   Updated: 2021/05/16 18:24:04 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_vec3	vec3(float x, float y, float z)
{
	return ((t_vec3){.x = x, .y = y, .z = z});
}

t_vec3	vec3_sub(t_vec3 vec1, t_vec3 vec2)
{
	return (vec3(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z));
}

float	vec3_length(t_vec3 vec)
{
	return (sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z)));
}

t_vec3	vec3_normalize(t_vec3 vec)
{
	float	length;

	length = vec3_length(vec);
	return (vec3(vec.x / length, vec.y / length, vec.z / length));
}

float	vec3_dot(t_vec3 vec1, t_vec3 vec2)
{
	return ((vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z));
}
