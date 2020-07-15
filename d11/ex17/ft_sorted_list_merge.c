/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
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
 *	• 
 *
 * 
 *	• 
 * 
 * 
 *	• Вот как эта функция должна быть объявлена :
 *
 *			
 * 
 * 
 * ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, \
								int (*cmp)())
{
	t_list	*tail;
	t_list	*head1;
	t_list	*head2;
	int		compare;

	if (!*begin_list1 || !begin_list2)
	{
		*begin_list1 = begin_list2 ? begin_list2 : *begin_list1;
		return ;
	}
	compare = (*cmp)(begin_list2->data, (*begin_list1)->data);
	head1 = (compare < 0) ? *begin_list1 : (*begin_list1)->next;
	head2 = (compare < 0) ? begin_list2->next : begin_list2;
	*begin_list1 = (compare < 0) ? begin_list2 : begin_list1;
	tail = *begin_list1;
	while (head1 && head2)
	{
		compare = (*cmp)(head2->data, head1->data);
		tail->next = (compare < 0 ? head2 : head1);
		head1 = compare < 0 ? head1 : head1->next;
		head2 = compare < 0 ? head2->next : head2;
		tail = tail->next;
	}
	tail->next = head2 ? head2 : head1;
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

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

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
	int (*cmp)())
{
	if (*begin_list1)
	{
		while (begin_list2)
		{
			ft_sorted_list_insert(begin_list1, begin_list2->data, cmp);
			begin_list2 = begin_list2->next;
		}
	}
	else
		*begin_list1 = begin_list2;
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_insert(t_list **begin_list, int (*cmp)())
{
	void	*val;

	if (*begin_list == ((void *)0) || (*begin_list)->next == ((void *)0))
		return ;
	else
	{
		if (cmp((*begin_list)->data, ((*begin_list)->next)->data) > 0)
		{
			val = (*begin_list)->data;
			(*begin_list)->data = ((*begin_list)->next)->data;
			((*begin_list)->next)->data = val;
			ft_insert(&((*begin_list)->next), cmp);
		}
		else
			return ;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_list	*liste;

	if (begin_list2 == ((void *)0))
		return ;
	else
	{
		liste = begin_list2->next;
		begin_list2->next = *begin_list1;
		*begin_list1 = begin_list2;
		begin_list2 = liste;
		ft_insert(begin_list1, cmp);
		ft_sorted_list_merge(begin_list1, begin_list2, cmp);
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
