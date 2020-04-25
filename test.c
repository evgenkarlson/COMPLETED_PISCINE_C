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


static int	ft_wordcount(char *s)
{
	int		i;
	int		w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != '\t' && s[i] != ' ' && s[i] != '\n')
			w++;
		while (s[i + 1] && s[i] != '\t' && s[i] != ' ' && s[i] != '\n')
			i++;
		i++;
	}
	return (w);
}

static int	ft_wordlen(char *s)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] == '\t' || s[i] == ' ' || s[i] == '\n')
		i += 1;
	while (s[i] && s[i] != '\t' && s[i] != ' ' && s[i++] != '\n')
		len += 1;
	return (len);
}

char		**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**w;

	i = 0;
	k = 0;
	if (!str || !(w = (char **)malloc(sizeof(char*) * (ft_wordcount(str) + 1))))
		return ((void*)0);
	while (i < ft_wordcount(str))
	{
		if (!(w[i] = (char *)malloc(sizeof(char) * (ft_wordlen(&str[k]) + 1))))
			return ((void*)0);
		j = 0;
		while (str[k] == '\t' || str[k] == ' ' || str[k] == '\n')
			k += 1;
		while (str[k] && str[k] != '\t' && str[k] != ' ' && str[k] != '\n')
			w[i][j++] = str[k++];
		w[i][j] = '\0';
		i += 1;
	}
	w[i] = ((void*)0);
	return (w);
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