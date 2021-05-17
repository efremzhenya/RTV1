/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:38:04 by lseema            #+#    #+#             */
/*   Updated: 2021/05/17 19:38:05 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cap(int n, int minus, char *str)
{
	int	len;

	len = 1;
	n /= 10;
	while (n)
	{
		n /= 10;
		len++;
	}
	len += minus;
	str = ft_strnew(len);
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		znak;
	int		dig;

	znak = 0;
	if (n < 0)
		znak = 1;
	len = cap(n, znak, &str);
	if (str)
	{
		str[len--] = '\0';
		while (len >= znak)
		{
			dig = n % 10;
			if (dig < 0)
				str[len--] = dig * -1 + '0';
			else
				str[len--] = dig + '0';
			n /= 10;
		}
		if (znak)
			str[0] = '-';
	}
	return (str);
}
