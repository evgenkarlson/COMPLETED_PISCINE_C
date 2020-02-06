/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 09:03:27 by jaleman           #+#    #+#             */
/*   Updated: 2016/12/27 10:03:26 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 


Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.
Напишите программу, которая принимает строку в качестве параметра и
печатает ее слова в обратном порядке.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.
«Слово» - это часть строки, ограниченная пробелами и / или символами
табуляции, или начало / конец строки.

If the number of parameters is different from 1, the program will display '\n'.
Если количество параметров отличается от 1, программа отобразит '\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).
В параметрах, которые будут проверяться, не будет никаких «дополнительных»
пробелов (это означает, что в начале или в конце строки не будет дополнительных
пробелов, а слова всегда будут разделены ровно одним Космос).

Examples:
Примеры:


$> ./rev_wstr "le temps du mepris precede celui de l'indifference" | cat -e
l'indifference de celui precede mepris du temps le$
$> ./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "il contempla le mont" | cat -e
mont le contempla il$
$> ./rev_wstr | cat -e
$
$>



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		num;
	char	words[256][4096];

	if (argc == 2)
	{
		i = 0;
		j = 0;
		num = 0;
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] == ' ')
			{
				num += 1;
				i += 1;
				j = 0;
			}
			words[num][j] = argv[1][i];
			i += 1;
			j += 1;
		}
		j = 0;
		while (num >= 0)
		{
			if (words[num][j] == '\0')
			{
				if (num > 0)
					write(1, " ", 1);
				if (num == 0 && words[num][j] == '\0')
					break ;
				num -= 1;
				j = 0;
			}
			write(1, &words[num][j], 1);
			j += 1;
		}
	}
	write(1, "\n", 1);
	return (0);
}
