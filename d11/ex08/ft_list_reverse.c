/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 15:45:25 by schapuis          #+#    #+#             */
/*   Updated: 2013/08/28 17:26:22 by schapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*list;
	t_list	*tmp;
	t_list	*tmp2;

	tmp = NULL;
	list = *begin_list;
	if (!list || !(list->next))
		return;
	tmp = list->next;
	tmp2 = tmp->next;
	list->next = NULL;
	tmp->next = list;
	while (tmp2)
	{
		list = tmp;
		tmp = tmp2;
		tmp2 = tmp2->next;
		tmp->next = list;
	}
	*begin_list = tmp;
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

void	ft_list_reverse(t_list **begin_list)
{
	t_list *tmp;
	t_list *tmp2;
	t_list *list;

	list = *begin_list;
	if (list == 0 || list->next == 0)
		return ;
	tmp = list->next;
	tmp2 = tmp->next;
	list->next = 0;
	tmp->next = list;
	while (tmp2)
	{
		list = tmp;
		tmp = tmp2;
		tmp2 = tmp2->next;
		tmp->next = list;
	}
	*begin_list = tmp;
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


void	ft_list_reverse(t_list **begin_list)
{
	t_list	*new_start;
	t_list	*tmp;

	new_start = NULL;
	while (*begin_list)
	{
		tmp = (*begin_list)->next;
		(*begin_list)->next = new_start;
		new_start = *begin_list;
		*begin_list = tmp;
	}
	*begin_list = new_start;
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

