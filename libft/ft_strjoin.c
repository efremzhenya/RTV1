/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:35:04 by lseema            #+#    #+#             */
/*   Updated: 2021/05/17 19:35:05 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	k;
	char	*res;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i] != '\0')
		i++;
	while (s2[k] != '\0')
		k++;
	res = (char *)malloc(sizeof(char) * (k + i) + 1);
	if (!(res))
		return (NULL);
	i = 0;
	k = 0;
	while (s1[i] != '\0')
		res[k++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		res[k++] = s2[i++];
	res[k] = '\0';
	return (res);
}
