/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/05/12 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H
#include <unistd.h>				/* Подключаем библиотеку содержащую функцию "write" */

int		sum(int a, int b, int *error);
int		subtract(int a, int b, int *error);
int		mul(int a, int b, int *error);
int		div(int a, int b, int *error);
int		mod(int a, int b, int *error);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_putstr(char *str);


#endif
/* ************************************************************************** */


/* ************************************************************************** */

void	ft_putchar(char c)		/* Функция печати символа */
{
	write(1, &c, 1);
}

/* ************************************************************************** */

void	ft_putstr(char *str)	/* Функция печати строки */
{
	while(*str)
		ft_putchar(*str++);
}

/* ************************************************************************** */

void	ft_putnbr(int nb)		/* Функция печати числа */
{
	int	temp;
	int	size;

	size = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb == -2147483648)
	{	
		ft_putchar('2');
		nb = 147483648;
	}
	temp = nb;
	while ((temp /= 10) > 0)
		size *= 10;
	temp = nb;
	while (size)
	{
		ft_putchar((char)((temp / size)) + 48);
		temp %= size;
		size /= 10;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	negativ;
	int	number;

	i = 0;
	negativ = 0;
	number = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		negativ = 1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + ((int)str[i] - '0');
		i++;
	}
	if (negativ == 1)
		return (-number);
	else
		return (number);
}

/* ************************************************************************** */

int	sum(int a, int b, int *error)
{
	*error = 0;
	return (a + b);
}

int	subtract(int a, int b, int *error)
{
	*error = 0;
	return (a - b);
}

int	mul(int a, int b, int *error)
{
	*error = 0;
	return (a * b);
}

int	div(int a, int b, int *error)
{
	if (b)
		return (a / b);
	ft_putstr("Stop : division by zero");
	*error = 1;
	return (0);
}

int	mod(int a, int b, int *error)
{
	if (b)
		return (a % b);
	ft_putstr("Stop : modulo by zero");
	*error = 1;
	return (0);
}

int	getop(char *c)
{
	if (*c == '+')
		return (0);
	else if (*c == '-')
		return (1);
	else if (*c == '*')
		return (2);
	else if (*c == '/')
		return (3);
	else if (*c == '%')
		return (4);
	else
		return (5);
}

void	ft_do_op(int argc, char **argv)
{
	if (argc == 4)
	{
		int	(*g_p[5]) (int x, int y, int *error);
		int result;
		int op;

		g_p[0] = sum;
		g_p[1] = subtract;
		g_p[2] = mul;
		g_p[3] = div;
		g_p[4] = mod;
		op = getop(argv[2]);
		if (op == 5)
		{
			ft_putchar('0');
			return ;
		}
		result = (*g_p[op])(ft_atoi(argv[1]), ft_atoi(argv[3]), &op);
		if (!op)
			ft_putnbr(result);
	}
}

int		main(int argc, char *argv[])
{
	if (argc > 1)
		ft_do_op(argc, argv);

	ft_putchar('\n');
	return (0);
}