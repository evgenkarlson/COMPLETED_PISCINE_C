/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-2____str_maxlenoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/03/02 19:05:02 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **


Assignment name  : str_maxlenoc 
Expected files   : str_maxlenoc.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------


Напишите программу, которая принимает одну или несколько строк и отображает с 
последующим переводом строки самую длинную строку, которая появляется в каждом 
параметре. Если подходит более одной строки, будет отображена та, которая 
появляется первой в первом параметре. Обратите внимание, что пустая строка 
технически появляется в любой строке.

Если параметров нет, программа отображает новую строку ('\n').

Examples:

$>./str_maxlenoc ab bac abacabccabcb
a
$>./str_maxlenoc bonjour salut bonjour bonjour
u
$>./str_maxlenoc xoxAoxo xoxAox  oxAox oxo  A ooxAoxx oxooxo Axo | cat -e
$
$>./str_maxlenoc bosdsdfnjodur atehhellosd afkuonjosurafg headfgllosf fghellosag afdfbosnjourafg
os
$>./str_maxlenoc | cat -e
$


** ************************************************************************** */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

/*
** Поиск в массиве строк строки с наименьшей длинной и возвращение ее индекса.
*/
int		find_indx_min_str(int ac, char *av[])
{

	int minLen;
	int minIdx;
	int	lenght;
	int i;
	
	/* 
	** Устанавливаем в переменную 'minLen' максимально возможное значение 
	** ( https://stackoverflow.com/questions/26555159/what-does-the-assignment-of-0u-to-a-variable-mean-in-c )
	** для сравнения с другими строками и поиска индекса строки с наименьшей длинной.
	*/
	minLen = (~0u >> 1); 
	minIdx = 1;
	i = 1;
	while (i < ac)
	{
		lenght = ft_strlen(av[i]);
		if (minLen > lenght)
		{
			minLen = lenght;
			minIdx = i;
		}
		i++;
	}
	return (minIdx);
}

/* Функция ищет идентичный фрагмент строки в другой строке */
int		find_fragment(char *fragment, char *str, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (fragment[i] != str[i])
		{
			if (!str[1])
				return (0);
			str++;
			i = -1;
		}
	}
	return (1);
}

/* Функция ищет идентичный фрагмент строки в массиве строк
** Если фрагмент строки в массиве строк не найден то фрагмент
** уменьшается с конца и поиск начинается заново */
int		largest_match_size(char *fragment, int ac, char *av[])
{

	int	len;
	int	i;

	len = ft_strlen(fragment);
	i = -1;
	while (++i < ac)
	{
		if (!find_fragment(fragment, av[i], len))
		{
			if (len <= 1)
				return (-1);
			len--;
			i = -1;
		}
	}
	return (len);
}

void	ft_swap(char **a, char **b)
{
	char *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		ft_str_maxlenoc(int ac, char *av[])
{
	char	*fragment;
	int		index;
	int		max_len;
	int		max_index;
	int		tmp;

	if (ac == 1)
		write(1, av[0], ft_strlen(av[0]));
	else
	{
		tmp = find_indx_min_str(ac, av);
		if (tmp != 1)
			ft_swap(&av[0], &av[tmp]);
		fragment = av[0];
		index = 0;
		max_index = 0;
		max_len = -1;
		ac--;
		av++;
		while (*(fragment + index))
		{
			/* Цикл запускает функцию 'largest_match_size', которая
			** ищет идентичный фрагмент строки в массиве строк
			** Если совпадения с фрагментом строки в массиве строк
			** не найдено то фрагмент уменьшается с вначале и цикл
			** начинается заново */
			tmp = largest_match_size(fragment + index, ac, av);
			if (max_len < tmp)
			{
				max_len = tmp;
				max_index = index;
			}
			index++;
		}
		if (max_index > -1)
			write(1, fragment + max_index, max_len);
	}
	write(1, "\n", 1);
	return (0);
}

int		main(int ac, char *av[])
{
	if (ac >= 2)
		ft_str_maxlenoc(ac - 1, av + 1);
	else
		write(1, "\n", 1);
	return (0);
}
