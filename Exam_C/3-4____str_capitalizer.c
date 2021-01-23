/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-4____str_capitalizer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/01/20 21:34:48 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* ************************************************************************** */
/* ************************************************************************** **


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


** ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int		ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

void	str_capitalizer(char *str)
{
	int		i;

	i = 0;
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] += 'A' - 'a';
	i++;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
		if ((str[i] >= 'a' && str[i] <= 'z') && (ft_is_space(str[i - 1])))
			str[i] += 'A' - 'a';
		i++;
	}
}

void	ft_apply_to_arr(char **arr, int lenght, void (*applly_f)(char *))
{
	int i;

	i = 0;
	while (i < lenght)
	{
		applly_f(arr[i]);
		ft_putstr(arr[i]);
		ft_putchar('\n');
		i++;
	}
}

int		main(int argc, char *argv[])
{
	if (argc > 1)
		ft_apply_to_arr(&argv[1], argc - 1, str_capitalizer);
	else
		ft_putchar('\n');
	return (0);
}
