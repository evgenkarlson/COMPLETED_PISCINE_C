/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/01/25 00:45:02 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **
**
**  Каталог сдачи задания: ex14/
**  Файлы для сдачи: ft_list_sort.c, ft_list.h
**  Разрешенные функции: Никаких
**
** ************************************************************************** **
 *
 * 
 *	• Создайте функцию «ft_list_sort», которая сортирует содержимое списка 
 *	по возрастанию, сравнивая две ссылки, благодаря функции, которая может
 *	сравнивать данные, содержащиеся в этих двух ссылках.
 * 
 * 
 *	• Вот как эта функция должна быть объявлена :
 *
 *					void	ft_list_sort(t_list **begin_list, int (*cmp)());
 * 
 * 
 *	• Функция, обозначенная как 'cmp', будет использоваться следующим образом:
 * 
 *					(*cmp)(list_ptr->data, list_other_ptr->data);
 *
 * 
 *	• Функцией 'cmp' может быть, например, 'ft_strcmp'.
 * 
 * 
 * ************************************************************************** */
/* ************************************************************************** */

/* * */
/* SORTING THE LIST !WITHOUT! using the "ft_list_size" function */

#include "ft_list.h"

void		ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	t_list	*tmp;
	t_list	*last;

	last = ((void *)0);
	current = *begin_list;
	while (current->next)
	{
		if ((*cmp)(current->data, current->next->data) > 0)
		{
			if (current == *begin_list)
				last = *begin_list = (*begin_list)->next;
			else
				last = last->next = current->next;
			tmp = current->next->next;
			current->next->next = current;
			current->next = tmp;
			current = *begin_list;
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

/* SORTING THE LIST !with! using the "ft_list_size" function */

#include "ft_list.h"

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
void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int i;
	int	n;
	t_list	*next;
	t_list	*prev;
	t_list	*current;

	n = ft_list_size(*begin_list);
	i = 0;
	while (i < n - 1)
	{
		prev = ((void *)0);
		current = *begin_list;
		while (current->next)
		{
			if ((*cmp)(current->data, current->next->data) > 0)
			{
				if (!prev)
					prev = *begin_list = current->next;
				else
					prev = prev->next = current->next;
				next = current->next->next;
				current->next->next = current;
				current->next = next;
			}
			else
			{
				prev = current;
				current = current->next;
			}
		}
		i++;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */

void	ft_swap(void **a, void **b)
{
	void	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *list_i;
	t_list *list_j;

	if (*begin_list)
	{
		list_i = *begin_list;
		while (list_i->next)
		{
			list_j = *begin_list;
			while (list_j->next)
			{
				if ((*cmp)(list_j->data, list_j->next->data) > 0)
					ft_swap(&(list_j->data), &(list_j->next->data));
				list_j = list_j->next;
			}
			list_i = list_i->next;
		}
	}
}

/* ************************************************************************** */
/* ************************************************************************** */

#include "ft_list.h"

int			ft_list_size(t_list *begin_list)
{
	int		len;
	t_list	*atm;

	len = 1;
	atm = begin_list;
	while (atm->next)
	{
		len = len + 1;
		atm = atm->next;
	}
	return (len);
}

t_list		*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (i < nbr && begin_list->next)
	{
		begin_list = begin_list->next;
		i = i + 1;
	}
	return (i == nbr ? begin_list : 0);
}

void		ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		i;
	int		j;
	void	*save;

	i = 0;
	j = 1;
	if (*begin_list)
	{
		while (i < ft_list_size(*begin_list) - 1)
		{
			while (j < ft_list_size(*begin_list))
			{
				if (cmp(ft_list_at(*begin_list, i)->data,
							ft_list_at(*begin_list, j)->data) > 0)
				{
					save = ft_list_at(*begin_list, i)->data;
					ft_list_at(*begin_list, i)->data =
						ft_list_at(*begin_list, j)->data;
					ft_list_at(*begin_list, j)->data = save;
				}
				j = j + 1;
			}
			i = i + 1;
			j = i + 1;
		}
	}
}

/* ************************************************************************** */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list *p;

	p = ((void *)0);
	while (nbr > 0)
	{
		if (p)
		{
			if (p->next)
				p = p->next;
			else
				return (((void *)0));
		}
		else
			p = begin_list;
		nbr--;
	}
	return (p);
}

int			ft_list_size(t_list *begin_list)
{
	t_list	*p;
	int		i;

	i = 0;
	p = begin_list;
	while (p)
	{
		i++;
		p = p->next;
	}
	return (i);
}

void		ft_list_swap(t_list **l1, t_list **l2)
{
	(*l1)->next = (*l2)->next;
	(*l2)->next = *l1;
}

void		ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		i;
	int		j;
	t_list	*l1;
	t_list	*l2;

	i = 0;
	while (i < ft_list_size(*begin_list))
	{
		j = 1;
		while (j < ft_list_size(*begin_list) - i)
		{
			l1 = ft_list_at(*begin_list, j);
			l2 = ft_list_at(*begin_list, j + 1);
			if (cmp(l1->data, l2->data) > 0)
			{
				if (j > 1)
					ft_list_at(*begin_list, j - 1)->next = l2;
				ft_list_swap(&l1, &l2);
				if (j == 1)
					*begin_list = l2;
			}
			j++;
		}
		i++;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_insert(t_list **begin_list, int (*cmp)())
{
	void	*val;

	if (*begin_list || (*begin_list)->next)
	{
		if (cmp((*begin_list)->data, ((*begin_list)->next)->data) > 0)
		{
			val = (*begin_list)->data;
			(*begin_list)->data = ((*begin_list)->next)->data;
			((*begin_list)->next)->data = val;
			ft_insert(&((*begin_list)->next), cmp);
		}
	}
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	if (*begin_list || (*begin_list)->next)
	{
		ft_list_sort(&((*begin_list)->next), cmp);
		ft_insert(begin_list, cmp);
	}
}

/* ************************************************************************** */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap_data(t_list *a, t_list *b)
{
	t_list tmp;

	tmp.data = a->data;
	a->data = b->data;
	b->data = tmp.data;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *current;

	if (*begin_list || (*begin_list)->data)
	{
		current = *begin_list;
		while (current->next)
		{
			if ((*cmp)(current->data, current->next->data) > 0)
			{
				ft_swap_data(current, current->next);
				current = *begin_list;
			}
			else
				current = current->next;
		}
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
