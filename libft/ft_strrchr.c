/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:34:04 by lseema            #+#    #+#             */
/*   Updated: 2021/05/17 19:34:05 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while ((s[i] != c) && (i >= 0))
		i--;
	if (i == -1)
		return (NULL);
	return ((char *)&s[i]);
}
