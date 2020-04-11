/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 10:55:36 by exam              #+#    #+#             */
/*   Updated: 2017/07/28 11:15:36 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 


Assignment name  : hidenp
Expected files   : hidenp.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.
Напишите программу с именем hidenp, которая принимает две строки и отображает 1,
за которым следует новая строка, если первая строка скрыта во второй, в противном
случае отображается 0, за которой следует новая строка.

Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Пусть s1 и s2 - строки. Мы говорим, что s1 скрыт в s2, если можно найти каждый 
символ из s1 в s2, в том же порядке, в каком они появляются в s1.

Also, the empty string is hidden in any string.
Также пустая строка скрыта в любой строке.

If the number of parameters is not 2, the program displays a newline.
Если количество параметров не равно 2, программа отображает новую строку.

Examples :
Примеры :


$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$>


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	check(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s2[j] != '\0')
	{
		if (s1[i] == s2[j])
			i++;
		if (i == ft_strlen(s1))
			return (49);
		j++;
	}
	return (48);
}

int		main(int argc, char **argv)
{
	if (argc != 3)
		;
	else
	{
		if (argv[1][0] == '\0')
			ft_putchar(49);
		else
			ft_putchar(check(argv[1], argv[2]));
	}
	ft_putchar('\n');
	return (0);
}



/* ************************************************************************** */
/* ********************************_OR_THAT_:)******************************* */
/* ************************************************************************** */



#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	while (*s2 && (*s1 == *s2))
	{
		s1 += 1;
		s2 += 1;
	}
	return (*s1 - *s2);
}

int		main(int argc, char *argv[])
{
	if (argc == 3)
	{
		int		i;
		int		j;
		char	str_hidenp[4096];

		i = 0;
		j = 0;
		while (argv[2][j])
		{
			if (argv[1][i] == argv[2][j])
			{
				str_hidenp[i] = argv[1][i];
				i += 1;
			}
			j += 1;
		}
		if (!ft_strcmp(argv[1], str_hidenp))
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}
