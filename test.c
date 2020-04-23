/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */


#include <unistd.h>					/* Подкоючаем библиотеку содержащую функцию для вывода символов(write) */
#include <stdlib.h>					/* Подкоючаем библиотеку содержащую функцию для выделения памяти(malloc) функцию для подсчета размера переменной(sizeof) */


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

void	ft_putchar(char c)		/* функция вывода символа */
{
	write(1, &c, 1);
}

/*#############################################################################*/

void	ft_putstr(char *str)   	/* Функция печати строки */
{
	while(*str)
		ft_putchar(*str++);
}

/*#############################################################################*/


int		ft_is_space(char c)
{
	if((c == ' ' || c == '\t' || c == '\n'))
		return (1);
	return(0);
}

int		ft_num_words(char *str)
{
	int	i;
	int	g_words;

	g_words = 0;
	i = 0;
	while (str[i])
	{
		if (!(g_words) && !(ft_is_space(str[i])))
			g_words++;
		else if (ft_is_space(str[i - 1]) && !(ft_is_space(str[i])))
			g_words++;
		i++;
	}
	return (g_words);
}

char	*createword(char *str, int i, int j)
{
	char	*word;
	int		o;

	o = 0;
	if ((word = (char*)malloc(sizeof(char) * (j - i + 1))) == ((void *)0))
		return ((void *)0);
	while (i < j)
	{
		word[o] = str[i];
		i++;
		o++;
	}
	word[o] = '\0';
	return (word);
}

char	**ft_split_whitespaces(char *str)
{
	char	**arr;
	int		index;
	int		g_j;
	int		g_i;
	int 	g_words;

	g_words = ft_num_words(str);
	g_i = 0;
	g_j = 0;
	index = 0;
	if (g_words)
	{
		if ((arr = (char**)malloc(sizeof(char*) * (g_words + 1))) == ((void *)0))
			return ((void *)0);
		while (index < g_words)
		{
			while (ft_is_space(str[g_i]) && str[g_i])
				g_i++;
			g_j = g_i;
			while (!(ft_is_space(str[g_j]))  && str[g_j])
				g_j++;
			arr[index] = createword(str, g_i, g_j);
			g_i = g_j + 1;
			index++;
		}
	}
	else
		arr = (char**)malloc(sizeof(char*));
	arr[index] = 0;
	return (arr);
}



int     main(void)				/* Основаная функция */
{
	int i;
	int j;
	char **arr_str;

	i = 0;
	if ((arr_str = ft_split_whitespaces(" sebas  sdfds s sdf sdf chapuis wuid ")) == ((void *)0)) /* Запускам функцию нахождения в строке отдельных слов и разбрасываем ихв отдельные строки */
		return (0);
	while(i < 7)				/* Печатаем каждую строку массива со строками */
	{
		j = 0;
		while(arr_str[i][j])
		{
			ft_putchar(arr_str[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);					/* Если дошли до сюда значит основная функция завершается, возвращается ноль и программа завершается */ 
}