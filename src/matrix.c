/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 02:12:55 by lseema            #+#    #+#             */
/*   Updated: 2021/05/12 22:10:47 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_mat44f	translation_matrix(const t_vec3 from)
{
	t_mat44f translation;

	translation = new_matrix44f();
	translation.data[0][0] = 1;
	translation.data[1][1] = 1;
	translation.data[2][2] = 1;
	translation.data[3][3] = 1;
	translation.data[0][3] = -(from.x);
	translation.data[1][3] = -(from.y);
	translation.data[2][3] = -(from.z);
	return (translation);
}

t_mat44f	rotation_matrix(const t_vec3 from, const t_vec3 to)
{
	t_mat44f rotation;
	t_vec3 forward;
	t_vec3 right;
	t_vec3 up;

	forward = vec3_normalize(vec3_sub(from, to));
	right = vec3_normalize(vec3_cross_product(up_direction(forward), forward));
	up = vec3_cross_product(forward, right);
	rotation = new_matrix44f();
	rotation.data[0][0] = right.x;
	rotation.data[0][1] = right.y;
	rotation.data[0][2] = right.z;
	rotation.data[1][0] = up.x;
	rotation.data[1][1] = up.y;
	rotation.data[1][2] = up.z;
	rotation.data[2][0] = forward.x;
	rotation.data[2][1] = forward.y;
	rotation.data[2][2] = forward.z;
	rotation.data[3][3] = 1;
	return (rotation);
}

t_mat44f	new_matrix44f()
{
	t_mat44f matrix;

	matrix.data[0][0] = 0;
	matrix.data[0][1] = 0;
	matrix.data[0][2] = 0;
	matrix.data[0][3] = 0;
	matrix.data[1][0] = 0;
	matrix.data[1][1] = 0;
	matrix.data[1][2] = 0;
	matrix.data[1][3] = 0;
	matrix.data[2][0] = 0;
	matrix.data[2][1] = 0;
	matrix.data[2][2] = 0;
	matrix.data[2][3] = 0;
	matrix.data[3][0] = 0;
	matrix.data[3][1] = 0;
	matrix.data[3][2] = 0;
	matrix.data[3][3] = 0;
	return (matrix);
}

t_vec3		up_direction(t_vec3 forward)
{
	if (forward.y == 1)
		return vec3(0, 0, -1);
	else if (forward.y == -1)
		return vec3(0, 0, 1);
	return vec3(0, 1, 0);
}

t_vec3	mat44f_mult_vec3f(t_vec3 vec, t_mat44f mat)
{
	int i;
	float	vec4[4];
	float	result[4];

	vec4[0] = vec.x;
	vec4[1] = vec.y;
	vec4[2] = vec.z;
	vec4[3] = 1.0;
	i = 0;
	while (i < 4)
	{
		result[i] =
			vec4[0] * mat.data[i][0] +
			vec4[1] * mat.data[i][1] +
			vec4[2] * mat.data[i][2] +
			vec4[3] * mat.data[i][3];
		i++;
	}
	return (vec3(result[0], result[1], result[2]));
}

t_mat44f	mat44f_mult(t_mat44f right_matrix, t_mat44f left_matrix)
{
	t_mat44f	result;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			result.data[i][j] = (left_matrix.data[i][0] * right_matrix.data[0][j])
				+ (left_matrix.data[i][1] * right_matrix.data[1][j])
				+ (left_matrix.data[i][2] * right_matrix.data[2][j])
				+ (left_matrix.data[i][3] * right_matrix.data[3][j]);
			j++;
		}
		i++;
	}
	return (result);
}
