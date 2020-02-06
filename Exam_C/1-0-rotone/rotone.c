/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 10:10:52 by exam              #+#    #+#             */
/*   Updated: 2017/07/28 10:32:20 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.
'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.
The output will be followed by a \n.
Напишите программу, которая берет строку и отображает ее, заменяя каждую
из ее букв на следующую в алфавитном порядке.
«z» становится «a», а «Z» становится «A». Дело остается без изменений.
За выходом последует \ n.


If the number of arguments is not 1, the program displays \n.
Если количество аргументов не равно 1, программа отображает \ n.

Example:
Пример:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		i;
	char	letter;
	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			letter = argv[1][i];
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Y')
				letter += 1;
			if (argv[1][i] >= 'a' && argv[1][i] <= 'y')
				letter += 1;
			if (argv[1][i] == 'z' || argv[1][i] == 'Z')
				letter -= 25;
			write(1, &letter, 1);
			i += 1;
		}
	}
	write(1, "\n", 1);
	return (0);
}


/* ************************************************************************** */
/* ********************************_OR_THAT_:)******************************* */
/* ************************************************************************** */


#include <unistd.h>

int		main(int argc, char **argv)
{
	int i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] > 64 && argv[1][i] < 90)
				argv[1][i]++;
			else if (argv[1][i] > 96 && argv[1][i] < 122)
				argv[1][i]++;
			else if (argv[1][i] == 90 || argv[1][i] == 122)
				argv[1][i] -= 25;
			i++;
		}
		i = 0;
		while (argv[1][i] != '\0')
		{
			write(1, argv[1][i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
}