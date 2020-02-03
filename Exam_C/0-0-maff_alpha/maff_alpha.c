/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <jaleman@student.42.us.org>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 19:28:35 by exam              #+#    #+#             */
/*   Updated: 2016/09/01 19:31:55 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


Assignment name  : maff_alpha
Expected files   : maff_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the alphabet, with even letters in uppercase, and
odd letters in lowercase, followed by a newline.

Напишите программу, которая отображает алфавит с четными буквами в верхнем 
регистре и нечетными буквами в нижнем регистре, за которым следует новая строка.

Example:
Пример:

$> ./maff_alpha | cat -e
aBcDeFgHiJkLmNoPqRsTuVwXyZ$


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include <unistd.h>

int	main(void)
{
	int i;
	char a;
	
	i = 0;
	while (i <= 25)
	{
		if((i % 2) == 0)
		{
			a = i + 97;
			write(1, &a, 1);
			i++;
		}
		else
		{
			a = i + 65;
			write(1, &a, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}


/* ************************************************************************** */
/* ********************************_OR_THAT_:)******************************* */
/* ************************************************************************** */


#include <unistd.h>

int		main(void)
{
	write(1, "aBcDeFgHiJkLmNoPqRsTuVwXyZ\n", 25);
	return (0);
}
