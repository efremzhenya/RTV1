/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:24:41 by lseema            #+#    #+#             */
/*   Updated: 2021/05/08 05:36:05 by lseema           ###   ########.fr       */
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

typedef struct	s_quadric_eq
{
	float		a;
	float		b;
	float		c;
	float		discr;
	float		root1;
	float		root2;
}				t_quadric_eq;

t_vec3			vec3(float x, float y, float z);
t_vec3			vec3_sub(t_vec3 vec1, t_vec3 vec2);
t_vec3			vec3_plus(t_vec3 vec1, t_vec3 vec2);
float			vec3_length(t_vec3 vec);
t_vec3			vec3_normalize(t_vec3 vec);
float			vec3_dot_product(t_vec3 vec1, t_vec3 vec2);
t_vec3			vec3_cross_product(t_vec3 vec1, t_vec3 vec2);
t_vec3			vec3_mult_value(t_vec3 vec, float value);
t_vec3			vec3_devide_value(t_vec3 vec, float value);

#endif
