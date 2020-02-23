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

void	fn_word(char *str, int *i)
{
	while (str[*i] != ' ' && str[*i] != '\t' && str[*i])
		(*i)++;
}

void	print_word(char *str, int start, int end)
{
	int		i;

	i = start;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && end--)
		write(1, &str[i++], 1);
}


void 	ft_last_word(char *str)
{
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	end = 0;
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	while (str[i])
	{
		start = i;
		fn_word(str, &i);
		end = i;
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (!str[i])
			print_word(str, start, end);
	}
}

int		main(int argc, char **argv)
{

	if (argc == 2)
	{
		ft_last_word(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}


