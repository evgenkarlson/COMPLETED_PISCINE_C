/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-3____sort_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/01/25 00:16:19 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** **

Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions:
--------------------------------------------------------------------------------

Напишите следующую функцию:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));


Эта функция должна отсортировать список, заданный в качестве параметра,
используя указатель функции cmp, чтобы выбрать применяемый порядок, и
возвращает указатель на первый элемент отсортированного списка.

Дубликаты должны остаться.

Входные данные всегда будут последовательными.

Вы должны использовать тип t_list, описанный в предоставленном вам файле list.h.
Вы должны включить этот файл (#include "list.h"), но не должны включать его.
Мы будем использовать наш собственный для компиляции вашего задания.

Функции, переданные как cmp, всегда будут возвращать значение, отличное от 0,
если a и b находятся в правильном порядке, 0 в противном случае.

Например, следующая функция, используемая в качестве cmp, будет сортировать
список в порядке возрастания:


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


** ************************************************************************** */
/* ************************************************************************** */

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

void	ft_swap(int *num1, char *num2)
{
	int	temp;

	temp = *num1;
	*num1 = num2;
	*num2 = temp;
	
}

t_list		*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*tmp;

	tmp = lst;
	while (lst->next)
	{
		if (!((*cmp)(lst->data, lst->next->data)))
		{
			ft_swap(&lst->data, &lst->next->data);
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	return (lst);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** **
**                            the file 'test.c' ...                           **
** ************************************************************************** **
** ************************************#************************************* **
** ************************************#************************************* **
** ************************************#************************************* **
** *********************************#######********************************** **
** ***********************************###************************************ **
** ************************************#************************************* **
** ************************************************************************** **


#include <unistd.h>
#include <stdlib.h>

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

void	ft_putchar(char c);
void	ft_putnbr(int nbr);
t_list	*ft_create_elem(int data);
int		ft_strcmp(int n1, int n2);
void	ft_swap(int *num1, int *num2);
t_list	*sort_list(t_list* lst, int (*cmp)(int, int));
void    ft_list_foreach(t_list *begin_list, void (*f)(int));


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}

int		ascending(int a, int b)
{
	return (a <= b);
}

t_list	*ft_create_elem(int data)
{
	t_list *new;
	
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return ((void *)0);
	new->data = data;
	new->next = ((void *)0);
	return (new);
}

void    ft_list_foreach(t_list *begin_list, void (*f)(int))
{
	while (begin_list)
	{
		if (begin_list->data)
		{
			(*f)(begin_list->data);
			ft_putchar(' ');
		}
		begin_list = begin_list->next;
	}
}

void	ft_swap(int *num1, int *num2)
{
	int	temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;	
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*tmp;

	tmp = lst;
	while (lst->next)
	{
		if (!((*cmp)(lst->data, lst->next->data)))
		{
			ft_swap(&lst->data, &lst->next->data);
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	return (tmp);
}


int		main(void)
{
	t_list *test_list;

	test_list = ft_create_elem(32);
	test_list->next = ft_create_elem(21);
	test_list->next->next = ft_create_elem(97);
	test_list->next->next->next = ft_create_elem(219);
	test_list->next->next->next->next = ft_create_elem(71);
	test_list->next->next->next->next->next = ft_create_elem(54);
	test_list->next->next->next->next->next->next = ft_create_elem(101);

    ft_list_foreach(test_list, (void *)ft_putnbr);
	sort_list(test_list, ascending);
	write(1, "\n", 1);
    ft_list_foreach(test_list, (void *)ft_putnbr);
	write(1, "\n", 1);
    return (0);
}

** ************************************************************************** */
/* ************************************************************************** */
