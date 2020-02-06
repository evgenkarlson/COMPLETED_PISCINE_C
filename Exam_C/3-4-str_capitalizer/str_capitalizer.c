/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 19:38:17 by exam              #+#    #+#             */
/*   Updated: 2017/07/21 20:02:27 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 


Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.
Напишите программу, которая принимает одну или несколько строк и, для каждого
аргумента, заглавные буквы первого символа каждого слова (если это, очевидно,
буква),помещает остаток в нижний регистр и отображает результат в стандартном
выводе, после которого следует \ п.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.
«Слово» определяется как часть строки, разделенная пробелами / табуляцией или
началом / концом строки. Если слово имеет только одну букву, оно должно быть
написано заглавными буквами.

If there are no arguments, the progam must display \n.
Если аргументов нет, программа должна отображать \ n.

Example:
Пример:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "Premier PETIT TesT" | cat -e
Premier Petit Test$
$> ./str_capitalizer "DeuxiEmE tEST uN PEU moinS  facile" "   attention C'EST pas dur QUAND mEmE" "ALLer UN DeRNier 0123456789pour LA rouTE    E " | cat -e
Deuxieme Test Un Peu Moins  Facile$
   Attention C'est Pas Dur Quand Meme$
Aller Un Dernier 0123456789pour La Route    E $
$>


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>
#define ISLETTER(c) ((c > 64 && c < 91) || (c > 96 && c < 123)) ? 1 : 0

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

char high(char c)
{
	if (c > 96 && c < 123)
		c = c - 32;
	return (c);
}

char low(char c)
{
	if (c > 64 && c < 91)
		c+=32;
	return (c);
}

char *cap(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if ((i == 0) && (str[i] > 96 && str[i] < 123))
			str[i] = str[i] - 32;
		else if ((ISLETTER(str[i])) && (str[i -1] == ' ' || str[i-1] == '\t'))
			str[i] = high(str[i]);
		else if ((ISLETTER(str[i])) && (str[i - 1] != ' ' || str[i -1] != '\t'))
		{
			if (i != 0)
				str[i] = low(str[i]);
		}
		i++;
	}
	return (str);
}

int main(int argc, char **argv)
{
	if (argc == 1) {
		ft_putchar('\n');
		return (0);
	}

	int i = 1;
	while (i < argc)
	{
		ft_putstr(cap(argv[i]));
		ft_putchar('\n');
		i++;
	}
	return (0);

}




/* ************************************************************************** */
/* ********************************_OR_THAT_:)******************************* */
/* ************************************************************************** */



#include <unistd.h>

void	str_capitalizer(char *str)
{
	int		i;

	i = 0;
	if (str[i] >= 'a' && 'z' >= str[i])
		str[i] -= 32;
	write(1, &str[i], 1);
	while (str[++i])
	{
		if (str[i] >= 'A' && 'Z' >= str[i])
			str[i] += 32;
		if ((str[i] >= 'a' && 'z' >= str[i]) && (str[i - 1] == ' ' || \
		str[i] == '\t'))
			str[i] -= 32;
		write(1, &str[i], 1);
	}
}

int		main(int argc, char *argv[])
{
	int		i;

	if (argc < 1)
		write(1, "\n", 1);
	else
	{
		i = 1;
		while (i < argc)
		{
			str_capitalizer(argv[i]);
			write(1, "\n", 1);
			i += 1;
		}
	}
	return (0);
}
