/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
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
 *	• Создайте функцию ft_list_remove_if, которая удаляет из списка все элемен-
 *	ты, данные которых «равны» справочным данным.
 * 
 * 
 *	• Вот как эта функция должна быть объявлена :
 *
 *	void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
 * 
 *
 * ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*last;
	t_list	*current;
	t_list	*tmp;

	last = ((void *)0);
	current = *begin_list;
	tmp = ((void *)0);
	while (current)
	{
		if ((*cmp)(current->data, data_ref) == 0)
		{
			if (current == *begin_list)
				*begin_list = current->next;
			else
				last->next = current->next;
			tmp = current;
			current = current->next;
			free(tmp);
		}
		else
		{
			last = current;
			current = current->next;
		}
	}
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *list_ptr;
	t_list *list_parent;
	t_list *tmp;

	list_ptr = *begin_list;
	list_parent = ((void *)0);
	while (list_ptr)
	{
		tmp = list_ptr;
		if ((*cmp)(list_ptr->data, data_ref) == 0)
		{
			if (list_parent != 0)
				list_parent->next = list_ptr->next;
			free(list_ptr);
		}
		list_parent = list_ptr;
		list_ptr = tmp->next;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
