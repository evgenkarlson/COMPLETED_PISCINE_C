/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:26:10 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/23 13:26:11 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "io.h"
#include "ft_list.h"

void	print_ll(t_list *ll)
{
	while (ll)
	{
		ft_putchar('[');
		ft_putstr(ll->str);
		ft_putstr("]->");
		ll = ll->next;
	}
	ft_putchar('\n');
}

t_list	*ft_create_elem(char *data)
{
	t_list *e;

	e = malloc(sizeof(t_list));
	if (e)
	{
		e->str = data;
		e->next = NULL;
	}
	return (e);
}

void	ft_list_push_back(t_list **begin_list, char *data)
{
	t_list *e;

	if (*begin_list)
	{
		e = *begin_list;
		while (e->next)
			e = e->next;
		e->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}

int		ft_list_size(t_list *begin_list)
{
	int len;

	len = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		len++;
	}
	return (len);
}

void	ft_list_delete_next(t_list *node)
{
	t_list *next2;

	next2 = node->next->next;
	free(node->next);
	node->next = next2;
}
