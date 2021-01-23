/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-0____epur_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/01/22 01:11:03 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **


Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Напишите программу, которая принимает строку и отображает эту строку с ровно 
одним пробелом между словами, без пробелов и табуляции ни в начале, ни в 
конце, за которым следует новая строка.

«Слово» определяется как часть строки, разделенная пробелами/табуляцией или 
началом/концом строки.

Если количество аргументов не равно 1 или нет слов для отображения, программа 
отображает новую строку.


Пример:

$> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
vous voyez c'est facile d'afficher la meme chose$
$> ./epur_str " seulement          la c'est      plus dur " | cat -e
seulement la c'est plus dur$
$> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./epur_str "" | cat -e
$
$>


** ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_is_space(char c)
{
	return ((c == ' ') || (c == '\t'));
}

void	ft_epur_str(char *str)
{
	int	flag;

	flag = 0;
	while (ft_is_space(*str))
		str++;
	while (*str)
	{
		if (ft_is_space(*str))
			flag = 1;
		if (!ft_is_space(*str))
		{
			if (flag)
				ft_putchar(' ');
			flag = 0;
			ft_putchar(*str);
		}
		str++;
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		ft_epur_str(argv[1]);
	ft_putchar('\n');
	return (0);
}
