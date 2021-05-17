/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:33:47 by lseema            #+#    #+#             */
/*   Updated: 2021/05/17 19:33:49 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;
	size_t		j;
	long int	pos;

	j = 0;
	i = 0;
	if (needle[0] == '\0')
		return ((char *)&haystack[0]);
	pos = -1;
	while (haystack[i] != '\0' && needle[j] != '\0')
	{
		while (haystack[i] == needle[j] && haystack[i] != '\0')
		{
			if (pos == -1)
				pos = i;
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[pos]);
		i = (i - j) + 1;
		j = 0;
		pos = -1;
	}
	return (NULL);
}
