/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <jaleman@student.42.us.org>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 18:38:41 by exam              #+#    #+#             */
/*   Updated: 2016/08/29 19:31:32 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.
Напишите программу, которая берет строку и отображает ее, заменяя каждую из
ее букв на 13 букв вперед в алфавитном порядке.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.
«z» становится «m», а «Z» становится «M». Дело остается без изменений.

The output will be followed by a newline.
За выходом последует новая строка.

If the number of arguments is not 1, the program displays a newline.
Если количество аргументов не равно 1, программа отображает новую строку.

Example:
Пример:


$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	ft_rot_13(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'M')
		{
			ft_putchar(str[i] + 13);
		}
		else if (str[i] >= 'N' && str[i] <= 'Z')
		{
			ft_putchar(str[i] - 13);
		}
		else if (str[i] >= 'a' && str[i] <= 'm')
		{
			ft_putchar(str[i] + 13);
		}
		else if (str[i] >= 'n' && str[i] <= 'z')
		{
			ft_putchar(str[i] - 13);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
	ft_putchar('\n');
	return (*str);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_rot_13(argv[1]);
	}
	else
	{
		ft_putchar('\n');
	}
	return (0);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		i;
	char	mvup;
	char	mvdwn;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			mvup = argv[1][i] + 13;
			mvdwn = argv[1][i] - 13;
			if (('A' <= argv[1][i] && 'M' >= argv[1][i])
				|| ('a' <= argv[1][i] && 'm' >= argv[1][i]))
				write(1, &mvup, 1);
			else if (('N' <= argv[1][i] && 'Z' >= argv[1][i])
				|| ('n' <= argv[1][i] && 'z' >= argv[1][i]))
				write(1, &mvdwn, 1);
			else
				write(1, &argv[1][i], 1);
			i += 1;
		}
	}
	write(1, "\n", 1);
	return (0);
}
