/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 08:07:57 by lseema            #+#    #+#             */
/*   Updated: 2021/04/04 14:36:49 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "scene.h"

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
	scene = (t_scene *)malloc(sizeof(t_scene));
	scene->objects = NULL;
	parse_json(json, &scene);
	free(json);
	free_objects(&(scene->objects));
	free(scene);
}
