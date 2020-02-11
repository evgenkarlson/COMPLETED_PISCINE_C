/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

int		ft_list_size(t_list *begin_list)
{
	t_list	*list;
	int		count;

	list = begin_list;
	count = 0;
	if (list)
	{
		count = 1;
		while (list->next)
		{
			list = list->next;
			count += 1;
		}
	}
	return (count);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*a;
	t_list	*b;
	int		cur;
	int		i;
	void	*tmp;

	a = begin_list;
	b = NULL;
	cur = ft_list_size(begin_list);
	while (a != b)
	{
		b = begin_list;
		i = 1;
		while (i++ < cur)
			b = b->next;
		if (a == b)
			break ;
		tmp = a->data;
		a->data = b->data;
		b->data = tmp;
		a = a->next ? a->next : a;
		cur -= 1;
	}
	a = begin_list;
}
