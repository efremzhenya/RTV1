/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:24:41 by lseema            #+#    #+#             */
/*   Updated: 2021/05/16 18:23:49 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H
# include <math.h>

typedef struct s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

typedef struct s_ray
{
	t_vec3		origin;
	t_vec3		direction;
}				t_ray;

typedef struct s_mat44f
{
	float		data[4][4];
}				t_mat44f;

typedef struct s_quadric_eq
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
float			vec3_dot(t_vec3 vec1, t_vec3 vec2);
t_vec3			vec3_cross_product(t_vec3 vec1, t_vec3 vec2);
t_vec3			vec3_mult_value(t_vec3 vec, float value);
t_vec3			vec3_devide_value(t_vec3 vec, float value);
t_vec3			mat44f_mult_vec3f(t_vec3 vec, t_mat44f mat);
t_vec3			up_direction(t_vec3 forward);
t_mat44f		new_matrix44f(void);
t_mat44f		rotation_matrix(const t_vec3 from, const t_vec3 to);
t_mat44f		translation_matrix(const t_vec3 from);
t_mat44f		mat44f_mult(t_mat44f right_matrix, t_mat44f left_matrix);

#endif
