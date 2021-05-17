/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:34:21 by lseema            #+#    #+#             */
/*   Updated: 2021/05/17 19:34:22 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 && s2)
	{
		if (n == 0)
			return (1);
		while (s1[i] == s2[i] && i < n)
		{
			if ((s1[i] == '\0' || i + 1 >= n))
				return (1);
			i++;
		}
	}
	return (0);
}
