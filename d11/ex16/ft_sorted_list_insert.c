/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
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
 *	• Создайте функцию «ft_sorted_list_insert», которая создает новый элемент
 *	и вставляет его в отсортированный список, чтобы он оставался в порядке 
 *	возрастания.
 * 
 * 
 *	• Вот как эта функция должна быть объявлена :
 *
 *	void	ft_sorted_list_insert(t_list **begin_list,void*data,int(*cmp)());
 * 
 * 
 * ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*link;
	t_list	*new_link;

	link = *begin_list;
	new_link = ft_create_elem(data);
	if (!link || (*cmp)(data, link->data) < 0)
	{
		*begin_list = new_link;
		new_link->next = link ? link : NULL;
		return ;
	}
	while (link->next)
	{
		if ((*cmp)(data, link->data) > 0 && (*cmp)(data, link->next->data) <= 0)
		{
			new_link->next = link->next;
			link->next = new_link;
			return ;
		}
		link = link->next;
	}
	link->next = new_link;
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*current;
	t_list	*next;
	t_list	*elem;
	int		cont;

	elem = ft_create_elem(data);
	current = *begin_list;
	cont = (current == ((void *)0)) ? 0 : 1;
	*begin_list = (current == 0) ? elem : *begin_list;
	*begin_list = (cont && cmp(data, current->data) <= 0) ? elem : *begin_list;
	elem->next = (cont && cmp(data, current->data) <= 0) ? current : elem->next;
	cont = (cont && cmp(data, current->data) <= 0) ? 0 : 1;
	while (cont && current)
	{
		next = current->next;
		current->next = (next == 0) ? elem : current->next;
		cont = (next == 0) ? 0 : 1;
		if (cont && cmp(data, next->data) <= 0)
		{
			current->next = elem;
			elem->next = next;
			return ;
		}
		current = current->next;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	insert(t_list **begin_list, t_list *elem, t_list *prev, t_list *list)
{
	if (prev)
		prev->next = elem;
	else
		*begin_list = elem;
	elem->next = list;
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *elem;
	t_list *list;
	t_list *prev;

	elem = ft_create_elem(data);
	list = *begin_list;
	prev = ((void *)0);
	if (list)
		while (list)
		{
			if ((*cmp)(list->data, elem->data) > 0)
			{
				insert(begin_list, elem, prev, list);
				break ;
			}
			else if ((*cmp)(list->data, elem->data) < 0 && list->next == ((void *)0))
			{
				list->next = elem;
				break ;
			}
			prev = list;
			list = list->next;
		}
	else
		*begin_list = elem;
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_list.h"

void	ft_swap_data(t_list *a, t_list *b)
{
	t_list tmp;

	tmp.data = a->data;
	a->data = b->data;
	b->data = tmp.data;
}

void	ft_list_sort_123456(t_list **begin_list, int (*cmp)())
{
	t_list *current;
	t_list *next;

	current = *begin_list;
	while (current->next)
	{
		next = current->next;
		if ((*cmp)(current->data, next->data) > 0)
		{
			ft_swap_data(current, next);
			current = *begin_list;
		}
		else
			current = next;
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *head;

	head = *begin_list;
	if (!head)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	while (head->next)
		head = head->next;
	head->next = ft_create_elem(data);
	ft_list_sort_123456(begin_list, (*cmp));
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */