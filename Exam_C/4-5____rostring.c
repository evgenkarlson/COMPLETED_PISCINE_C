/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-5____rostring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/01/25 02:15:18 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** **


Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Напишите программу, которая берет строку и отображает эту строку после поворота 
ее на одно слово влево.

Таким образом, первое слово становится последним, а остальные остаются в том 
же порядке.

«Слово» определяется как часть строки, разделенная пробелами/табуляцией или 
началом/концом строки.

Слова будут разделены только одним пробелом в выводе.

Если аргументов меньше одного, программа отображает символ перевода на 
новую строку ('\n').


Пример:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring | cat -e
$
$>


** ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>

void	rostring(char *str)
{
	int		i;
	int		k;

	if (*str)
	{
		i = 0;
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		k = i;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
		while (str[i])
		{
			if (str[i] && (str[i] != ' ' && str[i] != '\t') \
				&& (str[i - 1] == ' ' || str[i - 1] == '\t'))
			{
				while (str[i] && (str[i] != ' ' && str[i] != '\t'))
					write(1, &str[i++], 1);
				write(1, " ", 1);
			}
			i++;
		}
		while (str[k] && (str[k] != ' ' && str[k] != '\t'))
			write(1, &str[k++], 1);
	}
}

int		main(int argc, char *argv[])
{
	if (argc > 1)
		rostring(argv[1]);
	write(1, "\n", 1);
	return (0);
}


/* ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

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

	index = 0;
	if ((words = ft_wordcount(str, charset)))
	{
		if (!str || ((arr = (char **)malloc(sizeof(char *) * (words + 1))) == ((void *)0)))
			return ((void *)0);
		i = 0;
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
 
void	ft_rostring(char *str, char *charset)
{
	int 	i;
	int		wcount;
	char	**words;

	words = ft_split(str, charset);
	wcount = ft_wordcount(str,charset);
	i = 1;
	while (i < wcount)
	{
		ft_putstr(words[i]);
		free(words[i]);
		if (i > 0)
			write(1, " " ,1);
		i++;
	}
	ft_putstr(words[0]);
	free(words[0]);
}

int		main(int argc, char *argv[])
{
	if (argc > 1)
		ft_rostring(argv[1], " \t\n");
	write(1, "\n" ,1);
	return (0);
}


/* ************************************************************************** */
/* ************************************************************************** */
