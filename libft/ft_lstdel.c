/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:37:54 by lseema            #+#    #+#             */
/*   Updated: 2021/05/17 19:37:55 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cur;

	if (!del || !alst)
		return ;
	cur = *alst;
	while (cur != NULL)
	{
		del(cur->content, cur->content_size);
		free(cur);
		cur = cur->next;
	}
	*alst = NULL;
}
