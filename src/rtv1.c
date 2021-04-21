/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 08:07:57 by lseema            #+#    #+#             */
/*   Updated: 2021/04/21 10:24:28 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "scene.h"
#include "token_actions.h"

int		main(int argc, char **argv)
{
	int			fd;
	char		*json;
	t_scene		*scene;

	if (argc != 2)
		terminate(ERR_OPEN);
	if (is_file_format(argv[1], JSON_EXTENSION))
		terminate(ERR_FORMAT);
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		terminate(ERR_READ);
	if ((json = read_all_text(fd)) == NULL)
		terminate(ERR_EMPTY_FILE);
	scene = init_scene();
	parse_json(json, &scene);
	free(json);
	init_sdl(scene->width, scene->height);
	free_scene(&scene);
}
