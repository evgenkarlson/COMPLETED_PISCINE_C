/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <RTFM@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 


Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Напишите программу, которая принимает одну или несколько строк и, для каждого
аргумента, заглавные буквы первого символа каждого слова (если это, очевидно,
буква),помещает остаток в нижний регистр и отображает результат в стандартном
выводе, после которого следует новая строка.

«Слово» определяется как часть строки, разделенная пробелами/табуляцией или
началом/концом строки. Если слово имеет только одну букву, оно должно быть
написано заглавными буквами.

Если аргументов нет, программа должна отображать новую строку.

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
	while (*str)
		ft_putchar(*str++);
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
