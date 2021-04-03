/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:44:31 by lseema            #+#    #+#             */
/*   Updated: 2021/04/03 23:22:34 by lseema           ###   ########.fr       */
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
	if (is_file_format(argv[1], ".json"))
		terminate(ERR_FORMAT);
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		terminate(ERR_READ);
	if ((json = read_all_text(fd)) == NULL)
		terminate(ERR_EMPTY_FILE);
	scene = NULL;
	parse_json(json, &scene);
	free(json);
}

int		is_file_format(char *file, char *format)
{
	char *str;

	str = file;
	while (*str)
		str++;
	return (ft_strcmp(str - 5, format));
}

char	*read_all_text(int fd)
{
	char		*line;
	char		*result;
	char 		*json;

	json = NULL;
	while (get_next_line(fd, &line))
	{
		result = ft_strjoin(json ? json : "", line);
		free(line);
		if (json)
			free(json);
		json = ft_strdup(result);
		free(result);
	}
	return (json);
}

static int json_eq(const char *json, jsmntok_t token, const char *s)
{
	return (token.type == JSMN_STRING &&
		ft_strlen(s) == (size_t)token.end - token.start &&
		!ft_strncmp(json + token.start, s, token.end - token.start));
}

void	object_parse_switch(char const *json, jsmntok_t **tkn, t_scene **scene, int size)
{
	if (json_eq(json, **tkn, "cone"))
	{
		++(*tkn);
		parse_cone(json, tkn, scene, size);
	}
	else
	{
		++(*tkn);
	}
	// else if (json_eq(json, *(t + 2), "sphere"))
	// 	parse_sphere();
	// else if (json_eq(json, *(t + 2), "camera"))
	// 	parse_camera();
	// else if (json_eq(json, *(t + 2), "cuboid"))
	// 	parse_cuboid();
}

void	objects_parse_wrapper(char const *json, jsmntok_t **tkn, t_scene **scene)
{
	int j;

	if ((++(*tkn))->type != JSMN_ARRAY)
		terminate("Expected array of objects");
	j = ((*tkn)++)->size;
	while (j--)
	{
		if (((*tkn)++)->type != JSMN_OBJECT && (*tkn)->type != JSMN_STRING)
			terminate("Expected string key");
		else if (json_eq(json, **tkn, "type"))
		{
			if (((*tkn)++)->type != JSMN_STRING)
				terminate("Expected string value");
			object_parse_switch(json, tkn, scene, ((*tkn) - 2)->size);
		}
		else
			terminate("Expected 'type' key");
	}
}

void	parse_json(char const *json, t_scene **scene)
{
	int 		count;
	jsmn_parser	p;
	jsmntok_t	*tkn;
	int			size;

	jsmn_init(&p);
	tkn = NULL;
	if ((count = jsmn_parse(&p, json, ft_strlen(json), NULL, 1000)) < 0)
		terminate(ERR_SCENE_PARSE);
	jsmn_init(&p);
	tkn = (jsmntok_t *)malloc(sizeof(jsmntok_t) * count);
	count = jsmn_parse(&p, json, ft_strlen(json), tkn, count);
	if (count == 0 || tkn[0].type != JSMN_OBJECT)
		terminate(ERR_TOP_LVL_OBJ_EXPECTED);
	size = tkn++->size;
	while (size--)
	{
		if (json_eq(json, *tkn, "objects"))
			objects_parse_wrapper(json, &tkn, scene);
		else
			terminate(ERR_JSON_UNEXPCTD_KEY);
	}
	free(tkn - count);
}


void		parse_cone(char const *json, jsmntok_t **tkn, t_scene **scene, int size)
{
	t_object	*object;
	t_cone_data	*cone_data;

	object = (t_object *)malloc(sizeof(t_object));
	cone_data = (t_cone_data *)malloc(sizeof(t_cone_data));
	object->data = cone_data;
	while (--size)
	{
		if (json_eq(json, **tkn, "coordinates"))
		{
			++(*tkn);
			object->center = parse_coordiantes(json, tkn);
		}
		else if (json_eq(json, **tkn, "height"))
			cone_data->height = get_token_value_num(json, *(++(*tkn)));
		else if (json_eq(json, **tkn, "radius"))
			cone_data->radius = get_token_value_num(json, *(++(*tkn)));
		(*tkn)++;
	}
	if (scene != NULL)
	{

	}
}

t_vec3		parse_coordiantes(char const *json, jsmntok_t **t)
{
	t_vec3 vector;

	if ((*t)->type != JSMN_ARRAY)
		terminate("Expected array");
	if (((*t)++)->size != 3)
		terminate("Expected vector");
	vector.x = (int)get_token_value_num(json, *((*t)++));
	vector.y = (int)get_token_value_num(json, *((*t)++));
	vector.z = (int)get_token_value_num(json, **t);
	return vector;
}

char		*get_token_value_str(const char *json, jsmntok_t tkn)
{
	ssize_t		i;
	ssize_t		len;
	const char	*src;
	char		*dst;

	src = json + tkn.start;
	len = tkn.end - tkn.start;
	i = 0;
	dst = (char *)malloc(len + 1);
	while ((i < len) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return dst;
}

long long	get_token_value_num(const char *json, jsmntok_t tkn)
{
	char		*value;
	long long	result;

	value = NULL;
	if (tkn.type != JSMN_PRIMITIVE)
		terminate("Expected number");
	value = get_token_value_str(json, tkn);
	result = ft_atoi(value);
	free(value);
	return (result);
}
