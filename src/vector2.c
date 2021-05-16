/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:58:38 by lseema            #+#    #+#             */
/*   Updated: 2021/05/16 19:02:10 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_vec3	vec3_cross_product(t_vec3 vec1, t_vec3 vec2)
{
	return (vec3(vec1.y * vec2.z - vec1.z * vec2.y,
			vec1.z * vec2.x - vec1.x * vec2.z,
			vec1.x * vec2.y - vec1.y * vec2.x));
}

t_vec3	vec3_plus(t_vec3 vec1, t_vec3 vec2)
{
	return (vec3(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z));
}

t_vec3	vec3_mult_value(t_vec3 vec, float value)
{
	return (vec3(vec.x * value, vec.y * value, vec.z * value));
}

t_vec3	vec3_devide_value(t_vec3 vec, float value)
{
	return (vec3(vec.x / value, vec.y / value, vec.z / value));
}

t_vec3	up_direction(t_vec3 forward)
{
	if (forward.y == 1)
		return (vec3(0, 0, -1));
	else if (forward.y == -1)
		return (vec3(0, 0, 1));
	return (vec3(0, 1, 0));
}
