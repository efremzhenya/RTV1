/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 02:42:55 by lseema            #+#    #+#             */
/*   Updated: 2021/05/16 18:23:03 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "scene.h"

float	compute_lightning(t_vec3 a[2], t_vec3 V,
		float s, t_omnilight *light)
{
	float	i;
	t_vec3	l;
	t_vec3	R;
	float	n_dot_l;
	float	r_dot_v;

	i = 0.0;
	l = vec3_sub(light->center, a[0]);
	n_dot_l = vec3_dot(a[1], l);
	if (n_dot_l > 0)
		i += light->brightness * n_dot_l / (vec3_length(a[1]) * vec3_length(l));
	if (s > 0)
	{
		R = vec3_sub(vec3_mult_value(vec3_mult_value(a[1], 2.0),
					vec3_dot(a[1], l)), l);
		r_dot_v = vec3_dot(R, V);
		if (r_dot_v > 0)
			i += light->brightness * pow(r_dot_v
					/ (vec3_length(R) * vec3_length(V)), s);
	}
	return (i);
}
