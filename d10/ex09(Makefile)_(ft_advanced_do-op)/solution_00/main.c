/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 21:27:38 by jaleman           #+#    #+#             */
/*   Updated: 2017/03/30 21:27:39 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_adv_do-op.h"
#include "ft_opp.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while(*str)
		ft_putchar(*str++);
}

void	ft_putnbr(int nb)
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
	int	negativ;
	int	number;

	negativ = 0;
	number = 0;
	while ((*str == ' ') || (*str == '\t') || (*str == '\n')
		|| (*str == '\v') || (*str == '\f') || (*str == '\r'))
		str++;
	if (*str == '-')
		negativ = 1;
	if ((*str == '-') || (*str == '+'))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		number = (number * 10) + ((int)*str - '0');
		str++;
	}
	if (negativ == 1)
		return (-number);
	else
		return (number);
}

int		ft_usage(int a, int b)
{
	write(1, "error : only [ - + * / % ] are accepted.", 39);
	return (a + b);
}

void	ft_advanced_do_op(char *a, char *operator, char *b)
{
	int i;

	i = 0;

	if (operator[0] == '/' && ft_atoi(b) == 0)
		write(1, "Stop : division by zero\n", 24);
	else if (operator[0] == '%' && ft_atoi(b) == 0)
		write(1, "Stop : modulo by zero\n", 23);
	else
		while (i < 5)
		{
			if ((*g_opptab[i].op == operator[0]) && !operator[1])
				ft_putnbr(g_opptab[i].func(atoi(a), atoi(b)));
				break;
			i++;
		}
		if (i >= 5)
			g_opptab[5].func(atoi(a), atoi(b));
		write(1, "\n", 1);
}


int		main(int argc, char *argv[])
{
	if (argc == 4)
		ft_advanced_do_op(argv[1], argv[2], argv[3]);
	return (0);
}
