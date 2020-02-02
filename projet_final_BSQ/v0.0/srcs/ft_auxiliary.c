/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 13:04:33 by jaleman           #+#    #+#             */
/*   Updated: 2016/08/31 13:04:34 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i += 1;
	}
}

void	ft_putnbr(int nb)
{
	char number;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -1 * (nb);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	number = nb + '0';
	if (number >= '0' && number <= '9')
		write(1, &number, 1);
}

int		ft_atoi(char *str)
{
	int i;
	int number;
	int sign;

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

void	ft_stdin(int file)
{
	char	buffer[BUFFER_SIZE + 1];

	while (read(file, buffer, BUFFER_SIZE))
		ft_putstr(buffer);
}
