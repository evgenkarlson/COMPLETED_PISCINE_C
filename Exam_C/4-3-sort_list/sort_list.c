/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <jaleman@student.42.us.org>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 15:13:49 by exam              #+#    #+#             */
/*   Updated: 2017/03/31 15:14:03 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 


Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following functions:
Напишите следующие функции:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.
Эта функция должна отсортировать список, заданный в качестве параметра,
используя указатель функции cmp, чтобы выбрать применяемый порядок, и возвращает
указатель на первый элемент отсортированного списка.

Duplications must remain.
Дубликаты должны остаться.

Inputs will always be consistent.
Входные данные всегда будут последовательными.

You must use the type t_list described in the file list.h
that is provided to you. You must include that file
(#include "list.h"), but you must not turn it in. We will use our own
to compile your assignment.
Вы должны использовать тип t_list, описанный в предоставленном вам файле list.h.
Вы должны включить этот файл (#include "list.h"), но не должны включать его.
Мы будем использовать наш собственный для компиляции вашего задания.

Functions passed as cmp will always return a value different from
0 if a and b are in the right order, 0 otherwise.
Функции, переданные как cmp, всегда будут возвращать значение, отличное от 0,
если a и b находятся в правильном порядке, 0 в противном случае.

For example, the following function used as cmp will sort the list
in ascending order:
Например, следующая функция, используемая в качестве cmp, будет сортировать список
в порядке возрастания:


int ascending(int a, int b)
{
	return (a <= b);
}
--------------------------------------------------------------------------------
typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include "list.h"
#include <unistd.h>

t_list		*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int		overflow;
	t_list	*tmp;

	tmp = lst;
	while (lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			overflow = lst->data;
			lst->data = lst->next->data;
			lst->next->data = overflow;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}
