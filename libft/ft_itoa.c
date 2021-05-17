/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 15:06:59 by jpasty            #+#    #+#             */
/*   Updated: 2021/05/17 19:44:32 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cap(int n, int minus)
{
	int	len;

	len = 1;
	n /= 10;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (minus + len);
}

static int	itoa_helper(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		znak;
	int		dig;

	znak = itoa_helper(n);
	len = cap(n, znak);
	str = ft_strnew(len);
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
