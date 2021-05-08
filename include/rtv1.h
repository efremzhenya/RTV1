/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:08:48 by lseema            #+#    #+#             */
/*   Updated: 2021/05/08 23:29:00 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "errno.h"
# include "libft.h"
# include "scene.h"
# include <SDL.h>

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
}					t_sdl;

typedef struct	s_view
{
	float	width;
	float	height;
	float	x;
	float	y;
}	t_view;

char		*read_all_text(int fd);
int			is_file_format(char *file, char *format);
t_sdl		*init_sdl(int width, int height);
void		main_loop(t_sdl *sdl, t_scene *scene);
t_vec3		*get_frame(t_scene *scene);
t_vec3		ray_trace(t_ray ray, t_scene *scene);
t_view		*init_view(float width, float height, float fov);

#endif
