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

#include <unistd.h>						/* Подключаем библиотеку содержащую функцию "write" */

/* ************************************************************************** */
void	ft_putchar(char c)				/* Функция печати символа */
{
	write(1, &c, 1);
}
/* ************************************************************************** */
void	ft_putnbr(int nb)				/* Функция печати числа */
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
/* ************************************************************************** */
int				convert(int nbr, char *base, int *nbr_final)
{
	int size_base;
	int i;

	i = 0;
	size_base = 0;
	while (base[size_base])
		size_base++;
	while (nbr)
	{
		nbr_final[i] = nbr % size_base;
		nbr = nbr / size_base;
		i++;
	}
	return (i);
}

unsigned int	ft_active_bits(int value)
{
	int				nbr_final[100];
	char			base[] = "01";
	int				i;
	unsigned int	active_bits;
	int				negativ;

	i = 0;
	negativ = 0;
	active_bits = 0;
	if (value < 0)
	{
		negativ = 1;
		value = -value;
	}
	i = convert(value, base, nbr_final);
	while (--i >= 0)
		active_bits = active_bits + (base[nbr_final[i]] - 48);
	if (negativ == 1)
		return (32 - active_bits + 1);
	return (active_bits);
}

int main(void)
{
	ft_putnbr(ft_active_bits(1323));/* 1323 в двоичной системе счисления будет равен 0101 0010 1011, а
									 * это значит что колличество "активных битов"(единиц) равно шести.
									 * Если вывод программы будет равен шести значит функция работает верно */
    return (0);
}