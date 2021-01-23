/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-1____tab_mult.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/01/19 12:12:25 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** **


Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Напишите программу, которая отображает таблицу умножения чисел.

Параметр всегда будет строго положительным числом, которое помещается в int,
и указанное число, умноженное на 9, также будет соответствовать int.

Если параметров нет, программа отображает новую строку.


Примеры:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>


** ************************************************************************** */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)			/* функция вывода символа */
{
	write(1, &c, 1);
}


void			ft_putnbr(int n)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

int				ft_atoi(char *s)
{
	int		num;
	int		sign;

	sign = 1;
	num = 0;
	while (*s == '\t' || *s == '\n' || *s == '\v' || \
			*s == '\f' || *s == '\r' || *s == ' ')
		s++;
	if (*s == '-')
		sign = -1;
	while ((*s == '-') || (*s == '+'))
		s++;
	while (*s && *s >= '0' && *s <= '9')
		num = (num * 10) + ((int)(*(s++)) - '0');
	return (num * sign);
}

void	ft_tabmult(int nbr)
{
	int		i;

	i = 1;
	while (i <= 9)
	{
		ft_putnbr(i);
		ft_putchar('x');
		ft_putnbr(nbr);
		
		ft_putchar(' ');
		ft_putchar('=');
		ft_putchar(' ');

		ft_putnbr(i * nbr);
		ft_putchar('\n');
		i++;
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		ft_tabmult(ft_atoi(argv[1]));
	else
		ft_putchar('\n');
	return (0);
}

/* ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>

void	ft_putchar(char c)			/* функция вывода символа */
{
	write(1, &c, 1);
}


void			ft_putnbr(int n)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

int				ft_atoi(char *s)
{
	int		num;
	int		sign;

	sign = 1;
	num = 0;
	while (*s == '\t' || *s == '\n' || *s == '\v' || \
			*s == '\f' || *s == '\r' || *s == ' ')
		s++;
	if (*s == '-')
		sign = -1;
	while ((*s == '-') || (*s == '+'))
		s++;
	while (*s && *s >= '0' && *s <= '9')
		num = (num * 10) + ((int)(*(s++)) - '0');
	return (num * sign);
}

void	ft_tabmult(int nbr)
{
	int		i;

	i = 1;
	while (i <= 9)
	{
		ft_putnbr(i);
		ft_putchar('x');
		ft_putnbr(nbr);
		
		ft_putchar(' ');
		ft_putchar('=');
		ft_putchar(' ');

		ft_putnbr(nbr);
		ft_putchar('\n');
		nbr += nbr;
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		ft_tabmult(ft_atoi(argv[1]));
	else
		ft_putchar('\n');
	return (0);
}
