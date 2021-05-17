/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:20:19 by lseema            #+#    #+#             */
/*   Updated: 2021/05/17 19:20:22 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst_p;
	const unsigned char	*src_p;
	unsigned char		ch;

	dst_p = (unsigned char *)dst;
	src_p = (const unsigned char *)src;
	ch = (unsigned char)c;
	while (n-- > 0)
	{
		if (*src_p == ch)
		{
			*dst_p++ = *src_p;
			return (dst_p);
		}
		*dst_p++ = *src_p++;
	}
	return (NULL);
}
