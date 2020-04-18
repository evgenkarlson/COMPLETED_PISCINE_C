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


int		calc_nb_words(char *str, int *size_word)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			word++;
		while (str[i] != ' ')
		{
			size_word[word - 1] = size_word[word - 1] + 1;
			i++;
		}
		while (str[i] == ' ')
			i++;
	}
	return (word);
}

void	**ft_split_whitespaces(char *str)
{
	int		nb_words;
	int		tab[10];
	char	*temp;
	char	**string;
	int		i;

	i = 0;
	string = ((void *)0);
	nb_words = calc_nb_words(str, tab);
	string = (char*)malloc(sizeof(**string) * (nb_words + 1));
	while (i < nb_words)
	{
		string[i] = (char*)malloc(sizeof(*temp) * (tab[i] + 1));
		i++;
	}
	return (string);
}





int     main(void)				/* Основаная функция */
{
	int i;
	char **arr_str;

	i = 0;
	arr_str = ft_split_whitespaces(" sebas   chapuis wuid ");/* Запускам функцию нахождения в строке отдельных слов и разбрасываем ихв отдельные строки */
	while(i < 3)
	{
		ft_putstr(arr_str[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);					/* Если дошли до сюда значит основная функция завершается, возвращается ноль и программа завершается */ 
}