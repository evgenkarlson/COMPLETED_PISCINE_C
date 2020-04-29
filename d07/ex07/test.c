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
	char	*sptr;

	sptr = str;
	while (*sptr != '\0')
		if (to_find == *sptr++)
			return (1);
	return (0);
}

int		ft_wc(char *str, char *charset)
{
	int		i;

	i = 0;
	while (*str)
		if (ft_strchar(*str, charset))
			++str;
		else
		{
			++i;
			++str;
			while (*str && !ft_strchar(*str, charset))
				++str;
		}
	return (i);
}

char	*ft_split_w(char **str, char *charset)
{
	char	*bptr;
	char	*bsptr;
	char	*sptr;

	sptr = *str;
	while (ft_strchar(*sptr, charset))
		++sptr;
	*str = sptr;
	while (!ft_strchar(*sptr, charset))
		++sptr;
	bptr = malloc(sptr - *str);
	if (!bptr)
		return (NULL);
	bsptr = bptr;
	while (sptr > *str)
		*bsptr++ = *((*str)++);
	*bsptr = '\0';
	while (**str && ft_strchar(**str, charset))
		++*str;
	return (bptr);
}

char	**ft_split(char *str, char *charset)
{
	char	**buffer;
	char	**bptr;
	int		i;

	i = ft_wc(str, charset);
	if (!(buffer = malloc((i + 1) * sizeof(char *))))
		return (NULL);
	bptr = buffer;
	while (i--)
		if (!(*bptr++ = ft_split_w(&str, charset)))
			return (NULL);
	*bptr = (NULL);
	return (buffer);
}



int     main(void)				/* Основаная функция */
{
	char	**arr_str;			/* Обьявляем указатель на указатель, в который мы сохраним адресс массива с адресами строк */
	int 	i;					/* Обьявляем счетчик для перемещения по строкам */

	
	if ((arr_str = ft_split_whitespaces(" param pam pam  muther fucker ")) == ((void *)0)) /* Запускам функцию нахождения в строке отдельных слов и разбрасываем ихв отдельные строки */
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