/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:24:41 by lseema            #+#    #+#             */
/*   Updated: 2021/03/31 20:03:01 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H
# include <math.h>

typedef struct	s_vec3
{
	int			x;
	int			y;
	int			z;
}				t_vec3;

t_vec3			vec3(int x, int y, int z);

#endif
