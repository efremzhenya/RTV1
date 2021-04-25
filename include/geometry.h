/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:24:41 by lseema            #+#    #+#             */
/*   Updated: 2021/04/25 00:32:07 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H
# include <math.h>

typedef struct	s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

typedef struct	s_ray
{
	t_vec3		origin;
	t_vec3		direction;
}				t_ray;

t_vec3			vec3(float x, float y, float z);
t_vec3			vec3_sub(t_vec3 vec1, t_vec3 vec2);
float			vec3_length(t_vec3 vec);
t_vec3			vec3_normalize(t_vec3 vec);
float			vec3_dot_product(t_vec3 vec1, t_vec3 vec2);

#endif
