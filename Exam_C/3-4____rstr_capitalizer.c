/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-4____rstr_capitalizer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/01/20 21:32:10 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** **


Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Напишите программу, которая принимает одну или несколько строк и для каждого 
аргумента помещает последний символ каждого слова (если это буква) в верхний 
регистр, а остальные - в нижний регистр, а затем отображает результат, 
после которого идет новая строка.

Слово - это раздел строки, разделенный пробелами/табуляцией или началом/концом 
строки. Если слово содержит одну букву, оно должно быть написано заглавными 
буквами.

Если параметров нет, отобразите новую строку.


Примеры:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
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
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
		if ((str[i] >= 'a' && str[i] <= 'z') && (ft_is_space(str[i + 1])))
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

