/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <evgenkarlson@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by exam              #+#    #+#             */
/*   Created: 2020/02/14 12:33:14 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 

Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.
Напишите программу, которая принимает строку и отображает ее последнее слово, за которым следует \ n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.
Слово - это раздел строки, разделенный пробелами / табуляцией или началом / концом строки.

If the number of parameters is not 1, or there are no words, display a newline.
Если количество параметров не равно 1 или нет слов, отобразите новую строку.

Example:
Пример:


$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (!s1[i] && !s2[i])
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 3)
	{
		i = '0' + ft_strcmp(argv[1], argv[2]);
	}

	write(1, &i, 1);
	return (0);
}


