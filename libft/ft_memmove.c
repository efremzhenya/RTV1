/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:37:04 by lseema            #+#    #+#             */
/*   Updated: 2021/05/17 19:37:05 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;

	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	if ((!dst) && (!src))
		return (dst);
	if (src >= dst)
		while (len--)
			*p_dst++ = *p_src++;
	else
	{
		p_dst = p_dst + len - 1;
		p_src = p_src + len - 1;
		while (len--)
			*p_dst-- = *p_src--;
	}
	return (dst);
}
