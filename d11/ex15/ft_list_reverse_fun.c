/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 03:03:29 by jaleman           #+#    #+#             */
/*   Updated: 2016/11/26 03:03:30 by jaleman          ###   ########.fr       */
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
