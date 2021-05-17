/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:37:16 by lseema            #+#    #+#             */
/*   Updated: 2021/05/17 19:37:17 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*src_p;
	unsigned char		*dst_p;

	if ((!dst) && (!src))
		return (dst);
	src_p = src;
	dst_p = dst;
	while (n-- > 0)
		*dst_p++ = *src_p++;
	return (dst);
}
