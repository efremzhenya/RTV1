/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:33:28 by lseema            #+#    #+#             */
/*   Updated: 2021/05/17 19:33:31 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	end;
	char	*dst;

	if (!s)
		return (NULL);
	while ((*s == ' ') || (*s == '\n') || (*s == '\t'))
		s++;
	end = ft_strlen(s);
	if (!(end))
		return (ft_strnew(0));
	end = end - 1;
	while (((s[end] == ' ') || (s[end] == '\n') || (s[end] == '\t')))
		end--;
	dst = ft_strnew(end);
	if (!(dst))
		return (NULL);
	i = 0;
	while (i <= end)
		dst[i++] = *s++;
	dst[i] = '\0';
	return (dst);
}
