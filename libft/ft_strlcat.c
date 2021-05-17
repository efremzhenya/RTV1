/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:34:57 by lseema            #+#    #+#             */
/*   Updated: 2021/05/17 19:34:58 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	k;
	size_t	end_str;

	k = 0;
	while (dst[k] && k < size)
		k++;
	end_str = k;
	if (size)
	{
		while ((k < size - 1) && (src[k - end_str]))
		{
			dst[k] = src[k - end_str];
			k++;
		}
	}
	if (end_str < size)
		dst[k] = '\0';
	k = 0;
	while (src[k])
		k++;
	return (end_str + k);
}
