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

int			ft_atoi(char *str)
{
	int		i;
	int		number;
	int		sign;

	i = 0;
	number = 0;
	sign = 1;
	if (str == '\0')
		return (0);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i += 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i += 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i += 1;
	}
	return (number * sign);
}

void		ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void		ft_advanced_do_op(char *argv[])
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (*g_opptab[i].op == argv[2][0] && !argv[2][1])
		{
			ft_putnbr(g_opptab[i].func(ft_atoi(argv[1]), ft_atoi(argv[3])));
			break ;
		}
		i += 1;
	}
	if (i >= 5)
		g_opptab[5].func(ft_atoi(argv[1]), ft_atoi(argv[3]));
	write(1, "\n", 1);
}

int			ft_usage(int a, int b)
{
	write(1, "error : only [ - + * / % ] are accepted.", 39);
	return (a + b);
}

int			main(int argc, char *argv[])
{
	if (argc != 4)
		return (0);
	if (argv[2][0] == '/' && ft_atoi(argv[3]) == 0)
		write(1, "Stop : division by zero\n", 24);
	else if (argv[2][0] == '%' && ft_atoi(argv[3]) == 0)
		write(1, "Stop : modulo by zero\n", 23);
	else
		ft_advanced_do_op(argv);
	return (0);
}
