/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
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
 *	• Создайте функцию "ft_list_push_front", которая добавляет новый элемент 
 *	типа "t_list" в начало списка.
 * 
 * 
 *	• Он должен присваивать 'data' данному аргументу.
 * 
 * 
 *	• При необходимости он обновит указатель в начале списка.
 * 
 * 
 *	• Вот как эта функция должна быть объявлена :
 *
 *					void	ft_list_push_front(t_list **begin_list, void *data)
 * 
 * 
 * ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*list;

	if (*begin_list)
	{
		list = ft_create_elem(data);
		list->next = *begin_list;
		*begin_list = list;
	}
	else
		*begin_list = ft_create_elem(data);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*list;

	list = ft_create_elem(data);
	list->next = *begin_list;
	*begin_list = list;
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *list;

	list = ft_create_elem(data);
	if (list)
	{
		list->next = *begin_list;
		*begin_list = list;
	}
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

