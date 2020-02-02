/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 06:03:12 by adespond          #+#    #+#             */
/*   Updated: 2015/09/17 06:19:53 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *list_ptr;
	t_list *list_parent;
	t_list *tmp;

	list_ptr = *begin_list;
	list_parent = 0;
	while (list_ptr != 0)
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

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*last;
	t_list	*current;
	t_list	*tmp;

	last = NULL;
	current = *begin_list;
	tmp = NULL;
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
