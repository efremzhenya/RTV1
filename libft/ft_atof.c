/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:43:56 by lseema            #+#    #+#             */
/*   Updated: 2021/04/18 19:18:33 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_skip_char(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

int	get_sign(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

double	ft_atof(const char *s)
{
	size_t	i;
	double	sign;
	double	res;
	int		isDot;

	i = 0;
	res = 0;
	isDot = 0;
	while (s[i] != '\0' && is_skip_char(s[i]))
		i++;
	sign = get_sign(s[i]);
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] != '\0' && (ft_isdigit(s[i]) || (s[i] == '.' && !isDot)))
	{
		if (s[i] == '.' && i++)
			isDot = 1;
		else
		{
			if (isDot)
				sign /= 10;
			res = res * 10 + s[i++] - 48;
		}
	}
	return (sign * res);
}
