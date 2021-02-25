/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-2____str_maxlenoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/02/26 02:01:48 by evgenkarlson     ###   ########.fr       */
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
#include <stdlib.h>

int ft_strlen(char *s)
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
int get_min_index(int ac, char *av[])
{

	int minLen;
	int minIdx;
	int	lenght;
	int i;
	
	/* 
	** Устанавливаем в переменную 'minLen' максимально возможное значение 
	** для сравнения с другими строками и поиска индекса строки с наименьшей длинной.
	** https://stackoverflow.com/questions/26555159/what-does-the-assignment-of-0u-to-a-variable-mean-in-c
	*/
	minLen = (~0u >> 1); 
	minIdx = 1;
	i = 0;
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

int unfit(char *a, char *b, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (a[i] != b[i])
		{
			if (*(b + 1))
			{
				b++;
				i = -1;
			}
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int find_largest_match_size(char *key, int ac, char *av[])
{

	int	len;
	int	i;

	len = ft_strlen(key);
	i = 0;
	while (i < ac)
	{
		if (unfit(key, av[i], len))
		{
			if (len > 1)
			{
				len--;
				i = -1;
			}
			else
				return (-1);
		}
		i++;
	}
	return (len);
}

void	ft_swap(char *a, char *b)
{
	char *temp;

	temp = a;
	a = b;
	b = temp;
}

int main(int ac, char *av[])
{
	int		minIdx;
	char	*key;
	int		currIdx;
	int		maxLen;
	int		maxIdx;
	int		tmp;
	int		i;

	if (ac <= 2)
	{
		if (ac == 2)
			write(1, av[1], ft_strlen(av[1]));
	}
	else
	{
		minIdx = get_min_index(ac, av);
		if (minIdx != 1)
			ft_swap(av[1], av[minIdx]);
		key = av[1];
		currIdx = 0;
		maxLen = -1;
		maxIdx = -1;
		i = 2;
		while (i < ac)
		{
			tmp = find_largest_match_size(key + currIdx, ac - 2, av + 2);
			if (maxLen < tmp)
			{
				maxLen = tmp;
				maxIdx = currIdx;
			}
			currIdx++;
			i = 1;
			if (!(key[currIdx]))
				break;
			i++;
		}
		if (maxIdx > -1)
			write(1, key + maxIdx, maxLen);
	}
	write(1, "\n", 1);
	return (0);
}
