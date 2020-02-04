/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 14:41:40 by jaleman           #+#    #+#             */
/*   Updated: 2016/09/01 15:43:30 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.
Напишите программу с именем repeat_alpha, которая берет строку и отображает ее,
повторяя каждый алфавитный символ столько раз, сколько его алфавитный указатель, 
за которым следует новая строка.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.
Дело остается без изменений.


If the number of arguments is not 1, just display a newline.
Если количество аргументов не равно 1, просто отобразите новую строку.

Examples:
Примеры:


$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>



   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		i;
	int		letter;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			letter = 0;
			if (argv[1][i] >= 'A' && 'Z' >= argv[1][i])
				letter = argv[1][i] - 63;
			else if (argv[1][i] >= 'a' && 'z' >= argv[1][i])
            {
				letter = argv[1][i] - 95;
				while (--letter)
					write(1, &argv[1][i], 1);
            }
            else
                write(1, &argv[1][i], 1);
			i += 1;
		}
	}
	write(1, "\n", 1);
	return (0);
}
