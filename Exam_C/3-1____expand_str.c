/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <RTFM@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* ************************************************************************** */
/* ************************************************************************** **


Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Напишите программу, которая берет строку и отображает ее ровно с тремя пробелами 
между каждым словом, без пробелов и табуляций ни в начале, ни в конце, после чего 
следует новая строка.

Слово - это часть строки, разделенная пробелами/табуляцией или началом/концом строки.

Если количество параметров не 1 или нет слов, просто отобразите новую строку.


Пример:

$> ./expand_str "See? It's easy to print the same thing" | cat -e
See?   It's   easy   to   print   the   same   thing$
$> ./expand_str " this        time it      will     be    more complex  " | cat -e
this   time   it   will   be   more   complex$
$> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./expand_str "" | cat -e
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
	return (((c == ' ') || (c == '\t')) ? 1 : 0);
}

void	ft_expand_str(char *str)
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
			{
				ft_putchar(' ');
				ft_putchar(' ');
				ft_putchar(' ');
			}
			flag = 0;
			ft_putchar(*str);
		}
		str++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_expand_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}



/* ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>

int		ft_word_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		i++;
	return (i);
}


void	ft_expand_str(char *str)
{
	int len;
	int first_word;

	first_word = 1;
	while (*str)
	{
		while (*str == ' ' || *str == '\t')
			str++;
		
		len = ft_word_len(str);
		if (len > 0 && first_word == 0)  
			write(1, "   ", 3);
		first_word = 0;
		write(1, str, len);
		str = str + len;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_expand_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}

/* ************************************************************************** */
/* ************************************************************************** */

