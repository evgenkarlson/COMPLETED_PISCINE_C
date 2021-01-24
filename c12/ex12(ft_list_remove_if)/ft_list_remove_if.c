/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/01/24 15:04:09 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **
**
**  Каталог сдачи задания: ex12/
**  Файлы для сдачи: ft_list_remove_if.c, ft_list.h
**  Разрешенные функции: Никаких
**
** ************************************************************************** **
 *
 * 
 *	• Создайте функцию ft_list_remove_if, которая удаляет из списка связанных
 *  между собой структур все элементы, у которых данные в 'data' будут «равны» 
 *  справочным данным в 'data_ref'. 
 *  Сравнение производиться с помощью 'cmp', если данные «равны» то 'cmp' должна
 *  вернуть 0.
 *
 * 
 *	• Данные из элемента, который нужно стереть, нужно освободить с помощью
 *  'free_fct'.
 * 
 * 
 *	• Вот как эта функция должна быть объявлена:
 *
 *	void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
 * 
 * 
 *	• Функции, обозначенные как 'cmp' и 'free_fct', будут использоваться
 *  следующим образом:
 * 
 *											(*cmp)(list_ptr->data, data_ref);
 * 											(*free_fct)(list_ptr->data);
 *
 *
 * ************************************************************************** */
/* ************************************************************************** */


#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*last;
	t_list	*current;

	last = ((void *)0);
	current = *begin_list;
	while (current)
	{
		if ((*cmp)(current->data, data_ref) == 0)
		{
			if (current == *begin_list)
				*begin_list = current->next;
			else
				last->next = current->next;
			last = current;
			current = current->next;
			free_fct(last);
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


#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*last;
	t_list	*next;

	current = *begin_list;
	last = ((void *)0);
	while (current)
	{
		next = current->next;
		if (cmp(current->data, data_ref) == 0)
		{
			if (last)
				last->next = current->next;
			else
				*begin_list = current->next;
			free_fct(current);
			current = ((void *)0);
		}
		last = current;
		current = next;
	}	
}


/* ************************************************************************** */
/* ************************************************************************** */
