/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 02:42:55 by lseema            #+#    #+#             */
/*   Updated: 2021/05/08 17:23:57 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "scene.h"

float	compute_lightning(t_vec3 P, t_vec3 N, t_vec3 V, float s, t_omnilight *light)
{
	float	i;
	t_vec3	l;
	t_vec3	R;
	float	n_dot_l;

	i = 0.0;
	l = vec3_sub(light->center, P);
	//Диффузность
	n_dot_l = vec3_dot_product(N, l);
	if (n_dot_l > 0)
		i += light->brightness * n_dot_l / (vec3_length(N) * vec3_length(l));
	if (V.x && s && R.x && N.x)
		{}
	//Зеркальность
	if (s > 0)
	{
		R = vec3_sub(vec3_mult_value(vec3_mult_value(N, 2.0), vec3_dot_product(N, l)), l);
		float r_dot_v = vec3_dot_product(R, V);
		if (r_dot_v > 0)
			i += light->brightness * pow(r_dot_v / (vec3_length(R) * vec3_length(V)), s);
	}
	return (i);
}


