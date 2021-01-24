/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-2____ft_list_remove_if.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/01/25 00:08:36 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* ************************************************************************** */
/* ************************************************************************** **


Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Напишите функцию с именем ft_list_remove_if, которая удаляет из переданного
списка любой элемент, данные которого «равны» справочным данным.

Будет объявлено следующее:


void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());


cmp принимает два void * и возвращает 0, когда оба параметра равны.

Вы должны использовать файл ft_list.h, который будет содержать:


$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$>


** ************************************************************************** */
/* ************************************************************************** */


#include <stdlib.h>
#include "ft_list.h"
/* 'ft_list.h' contains:
 
#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;

#endif

*/

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
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
			free(current);
			current = ((void *)0);
		}
		last = current;
		current = next;
	}	
}


/* ************************************************************************** */
/* ************************************************************************** */



#include <stdlib.h>
#include "ft_list.h"
/* 'ft_list.h' contains:
 
#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;

#endif

*/

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
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
			free(last);
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
/* 'ft_list.h' contains:
 
#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;

#endif

*/

void 	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*i;

	while (*begin_list && !cmp((*begin_list)->data, data_ref))
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	i = *begin_list;
	while (i && i->next)
	{
		if (!(cmp(i->next->data, data_ref)))
		{
			tmp = i->next;
			i->next = tmp->next;
			free(tmp);
		}
		if (i->next)
			i = i->next;
	}
}

