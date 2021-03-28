/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:08:48 by lseema            #+#    #+#             */
/*   Updated: 2021/03/28 19:36:53 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "errno.h"
//# include "scene.h"
#include "../external_libs/jsmn/jsmn.h"
#include "libft.h"

char	*read_all_text(int fd);
int		is_file_format(char *file, char *format);

#endif
