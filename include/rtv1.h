/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:08:48 by lseema            #+#    #+#             */
/*   Updated: 2021/04/20 21:55:56 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "errno.h"
# include "libft.h"

char	*read_all_text(int fd);
int		is_file_format(char *file, char *format);
int		init_sdl(int width, int height);

#endif
