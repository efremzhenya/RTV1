/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 08:01:26 by lseema            #+#    #+#             */
/*   Updated: 2021/04/04 12:18:51 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "token_actions.h"

char		*token_to_str(const char *json, jsmntok_t tkn)
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
	return (dst);
}

long long	token_to_num(const char *json, jsmntok_t tkn)
{
	char		*value;
	long long	result;

	value = NULL;
	if (tkn.type != JSMN_PRIMITIVE)
		terminate("Expected number");
	value = token_to_str(json, tkn);
	result = ft_atoi(value);
	free(value);
	return (result);
}

t_vec3		token_to_vec3(char const *json, jsmntok_t **t)
{
	if ((*t)->type != JSMN_ARRAY)
		terminate("Expected array");
	if (((*t)++)->size != 3)
		terminate("Expected vector");
	return (vec3((int)token_to_num(json, *((*t)++)),
		(int)token_to_num(json, *((*t)++)),
		(int)token_to_num(json, **t)));
}
