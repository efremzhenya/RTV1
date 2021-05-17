/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_parser2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:24:41 by mellie            #+#    #+#             */
/*   Updated: 2021/05/17 20:14:48 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "scene.h"
#include "token_actions.h"

int	is_file_format(char *file, char *format)
{
	char	*str;

	str = file;
	while (*str)
		str++;
	return (ft_strcmp(str - 5, format));
}

char	*read_all_text(int fd)
{
	char		*line;
	char		*result;
	char		*json;

	json = NULL;
	while (get_next_line(fd, &line))
	{
		if (json)
			result = ft_strjoin(json, line);
		else
			result = ft_strjoin("", line);
		free(line);
		if (json)
			free(json);
		json = ft_strdup(result);
		free(result);
	}
	return (json);
}

int	parse_obj(char const *json, t_jsmntok **tkn, t_object	**object)
{
	if (json_eq(json, **tkn, "coordinates"))
	{
		++(*tkn);
		(*object)->origin = token_to_vec3(json, tkn);
		return (1);
	}
	else if (json_eq(json, **tkn, "color"))
	{
		++(*tkn);
		(*object)->color = token_to_color(json, tkn);
		return (1);
	}
	else if (json_eq(json, **tkn, "specular"))
	{
		(*object)->specular = token_to_double(json, *(++(*tkn)));
		return (1);
	}
	return (0);
}
