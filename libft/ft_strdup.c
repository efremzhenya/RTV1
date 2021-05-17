/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 15:13:24 by jpasty            #+#    #+#             */
/*   Updated: 2021/05/17 16:27:15 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	len;

	len = 0;
	while (src[len] != '\0')
		len++;
	dst = malloc(sizeof(char) * len + 1);
	if (!dst)
		return (NULL);
	else
	{
		len = 0;
		while (src[len] != '\0')
		{
			dst[len] = src[len];
			len++;
		}
		dst[len] = '\0';
		return (dst);
	}
}
