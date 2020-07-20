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
/* ************************************************************************** */
/* ************************************************************************** *
 *
 * 
 *	• Создайте функцию «ft_list_reverse_fun», которая меняет порядок элементов
 *	списка. Вы можете использовать только связанные с указателями материалы.
 *
 * 
 *	• Вот как эта функция должна быть объявлена :
 *
 *							void	ft_list_reverse_fun(t_list *begin_list);
 * 
 * 
 * ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

int		ft_list_size(t_list *begin_list)
{
	int		i;

	i = 0;
	while (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*a;
	t_list	*b;
	int		cur;
	int		i;
	void	*tmp;

	a = begin_list;
	b = ((void *)0);
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
		cur--;
	}
	a = begin_list;
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int		ft_list_size(t_list *begin_list)
{
	int		i;

	i = 0;
	while (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*tmp;
	t_list	*next;
	void	*var;
	int		len;
	int		i;

	len = ft_list_size(begin_list);
	if (begin_list == ((void *)0))
		return ;
	while (len > 0)
	{
		i = 0;
		tmp = begin_list;
		next = tmp->next;
		while (next && i < len - 1)
		{
			var = tmp->data;
			tmp->data = next->data;
			tmp->next->data = var;
			tmp = tmp->next;
			next = next->next;
			i++;
		}
		len = len - 1;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int		ft_get_size(t_list *begin_list)
{
	int		i;

	i = 0;
	while (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}

void	ft_swap(void **a, void **b)
{
	void *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*list;

	list = begin_list;
	while (list && nbr > 0)
	{
		list = list->next;
		nbr--;
	}
	return (nbr == 0 ? list : ((void *)0));
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		l;
	t_list	*list;

	l = ft_get_size(begin_list) - 1;
	list = begin_list;
	i = 0;
	while (i < l)
	{
		ft_swap(&((ft_list_at(list, i))->data), &((ft_list_at(list, l))->data));
		i++;
		l--;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int		ft_list_size(t_list *begin_list)
{
	return ((begin_list) ? 1 + ft_list_size(begin_list->next) : 0);
}

void	ft_swap_data(t_list *a, t_list *b)
{
	t_list tmp;

	tmp.data = a->data;
	a->data = b->data;
	b->data = tmp.data;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		j;
	int		len;
	int		len2;
	t_list	*current;

	len = ft_list_size(begin_list);
	len2 = len;
	i = -1;
	while (++i < len)
	{
		current = begin_list;
		j = 0;
		while (++j < len2)
		{
			if (current->next->data)
				ft_swap_data(current, current->next);
			current = current->next;
		}
		len2--;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */