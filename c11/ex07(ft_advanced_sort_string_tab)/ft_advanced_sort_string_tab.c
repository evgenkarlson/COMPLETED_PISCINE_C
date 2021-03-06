/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/02/16 23:40:32 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */ 
/* ************************************************************************** **
**
**  Каталог сдачи задания: ex04/
**  Файлы для сдачи: ft_advanced_sort_string_tab.c	
**  Разрешенные функции: Никакие
**
** ************************************************************************** **
**
** 
**	• Создайте функцию "ft_advanced_sort_string_tab", которая сортирует, в 
**	зависимости от возврата функции, заданной в качестве аргумента, слова, 
**	полученные с помощью "ft_split_whitespaces".
** 
** 
**	• Сортировка будет выполняться путем обмена указателями массива.
** 
** 
**	• Вот как эта функция должна быть объявлена :
 -------------------------------------------------------------------------------
 |  void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *)) |
 -------------------------------------------------------------------------------
** 
** 
***************************************************************************** **
**
**   Вызов 'ft_advanced_sort_string_tab()' с 'ft_strcmp' в качестве второго
**   аргумента вернет тот же результат, что и 'ft_sort_string_tab()'.
** 
 * ************************************************************************** */ 
/* ************************************************************************** */


void	ft_swap(char **x, char **y)
{
	char *temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

int		getlength(char **tab)
{
	int i;

	i = 0;
	while (*tab++)
		i++;
	return (i);
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int i;
	int j;
	int size;

	i = 0;
	size = getlength(tab);
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
			{
				ft_swap(&tab[j], &tab[j + 1]);
			}
			j++;
		}
		i++;
	}
}



/* ************************************************************************** */
/* ************************************************************************** */


void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int		length;
	int		i;
	char	*tmp;

	length = 0;
	while (tab[length])
		length++;
	i = 0;
	while (i < (length - 1))
	{
		if (cmp(tab[i], tab[i + 1]) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}


/* ************************************************************************** */
/* ************************************************************************** */


void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int		i;
	int		sorted;
	char	*tmp;

	sorted = 0;
	while (!sorted)
	{
		i = 0;
		sorted = 1;
		while (tab[i + 1])
		{
			if ((*cmp)(tab[i], tab[i + 1] > 0))
			{
				sorted = 0;
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i += 1;
		}
	}
}



/* ************************************************************************** */
/* ************************************************************************** */
