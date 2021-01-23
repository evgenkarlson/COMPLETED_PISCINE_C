/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-0____ft_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 15:13:49 by exam              #+#    #+#             */
/*   Updated: 2021/01/21 03:31:39 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** **


Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------


Напишите функцию, которая принимает строку, разбивает ее на слова и возвращает их
в виде массива строк с нулевым символом в конце.

«Слово» определяется как часть строки, разделенная пробелами/табуляциями/новыми 
строками или началом/концом строки.


Ваша функция должна быть объявлена ​​следующим образом:

char    **ft_split(char *str);


/* ************************************************************************** */
/* ************************************************************************** */


#include <stdlib.h>

int		ft_is_space(char to_find, char *str)
{
	while (*str)
	{
		if (to_find == *str++)
			return (1);
	}
	return (0);
}

int		ft_wordcount(char *str, char *charset)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	while (*str)
	{
		if (ft_is_space(*str, charset))
			flag = 1;
		if (!ft_is_space(*str, charset))
		{
			if (flag)
				count++;
			flag = 0;
		}
		str++;
	}
	return (count);
}

/*
int   ft_wordcount(char *str, char *charset)
{
	int		words;

	words = 0;
	while (*str)
	{
		if (!(words) && !(ft_is_space(*str, charset)))
			words++;
		else if (ft_is_space(*(str - 1), charset) && !(ft_is_space(*str, charset)))
			words++;
		str++;
	}
	return (words);
}

int		ft_wordcount(char *str, char *charset)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (ft_is_space(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !(ft_is_space(str[i], charset)))
			i++;
	}
	return (count);
}

int   ft_wordcount(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && (ft_is_space(*str, charset)))
			str++;
		if (*str && !(ft_is_space(*str, charset)))
		{
			count++;
			while (*str && !(ft_is_space(*str, charset)))
				str++;
		}
	}
	return (count);
}

*/

char	*create_word(char *str, int i, int j)
{
	char	*word;
	int		o;

	o = 0;
	if ((word = (char *)malloc(sizeof(char) * (j - i))) == ((void *)0))
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

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		index;
	int		j;
	int		i;
	int		words;

	if ((words = ft_wordcount(str, charset)))
	{
		if (!str || ((arr = (char **)malloc(sizeof(char *) * (words + 1))) == ((void *)0)))
			return ((void *)0);
		i = 0;
		index = 0;
		while (index < words)
		{
			while (ft_is_space(str[i], charset) && (str[i]))
				i++;
			j = i;
			while (!(ft_is_space(str[j], charset)) && (str[j]))
				j++;
			arr[index++] = create_word(str, i, j);
			i = j + 1;
		}
	}
	else
		arr = (char **)malloc(sizeof(char *));
	arr[index] = (void *)0;
	return (arr);
}


/* ************************************************************************** */
/* ************************************************************************** */
