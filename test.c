/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
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


int		ft_strchar(char to_find, char *str)
{
	while (*str)
		if (to_find == *str++)
			return (1);
	return (0);
}


/*
int   ft_wordcount(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && (ft_strchar(*str, spacechar)))
			str++;
		if (*str && !(ft_strchar(*str, spacechar)))
		{
			count++;
			while (*str && !(ft_strchar(*str, spacechar)))
				str++;
		}
	}
	return (count);
}
*/
int		ft_wordcount(char *str, char *spacechar)
{
	int		words;

	words = 0;
	while (*str)
	{
		if (!(words) && !(ft_strchar(*str, spacechar)))
			words++;
		else if (ft_strchar(*(str - 1), spacechar) && !(ft_strchar(*str, spacechar)))
			words++;
		str++;
	}
	return (words);
}

int		ft_len_word(char *str, int i, char *spacechar)
{
	int count;

	count = 0;
	while (!(ft_strchar(str[i], spacechar)) && str[i])
	{
		count++;
		i++;
	}
	return (count);
}

char	**ft_split(char *str, char *spacechar)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if ((res = malloc(sizeof(char*) * (ft_wordcount(str, spacechar) + 1))) == NULL)
		return (NULL);
	while (str[i])
	{
		while (ft_strchar(str[i], spacechar) && str[i])
			i++;
		if (str[i])
		{
			k = 0;
			if ((res[j] = malloc(sizeof(char) * ft_len_word(str, i, spacechar) + 1)) == NULL)
				return (NULL);
			while (!ft_strchar(str[i], spacechar) && str[i])
				res[j][k++] = str[i++];
			res[j++][k] = '\0';
		}
	}
	res[j] = NULL;
	return (res);
}






int     main(void)				/* Основаная функция */
{
	char	**arr_str;			/* Обьявляем указатель на указатель, в который мы сохраним адресс массива с адресами строк */
	int 	i;					/* Обьявляем счетчик для перемещения по строкам */

	if ((arr_str = ft_split("fuckingfuckingfuckingfucking", "in")) == ((void *)0)) /* Запускам функцию нахождения в строке 
								 * отдельных слов и разбрасываем ихв отдельные строки */
		return (0);
	i = 0;						/* Инициализируем счетчик для перемещения по строкам нулем чтобы начать с нулевой строки */
	while (arr_str[i] != ((void *)0))/* Проверяем есть ли по этому адресу строка. Если есть то спускаемся ниже и печатаем ее символы */
	{
		ft_putstr(arr_str[i]);	/* Печатаем текущую строку */
		ft_putchar('\n');		/* После, печатаем символ перехода на новую строку */
		i++;					/* Переходим к след ячейке хранящей адрес другой строки */
	}
	return (0);					/* Если дошли до сюда значит основная функция завершается, возвращается ноль и программа завершается */ 
}