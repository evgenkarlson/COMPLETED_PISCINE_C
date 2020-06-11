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

unsigned int	ft_active_bits_1(int value)
{
	unsigned int count;

	count = 0;
	while (value)
	{
		count += value & 1;
		value >>= 1;
	}
	return (count);
}


unsigned int	ft_active_bits_2(int value)
{
	int			bits;

	bits = 0;
	while (value > 0)
	{
		if ((value & 1) == 1)
			bits += 1;
		value >>= 1;
	}
	return (bits);
}


unsigned int	*ft_get_bits(int value)
{
	unsigned int	n[32];
	unsigned int	temp;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while(value)
	{
		n[i++] = (value & 1);
		value >>= 1;						/* Сдвигаем биты в переменной "value" на один разряд вправо */
	}
	j = 0;
	while(i > j)
	{
		temp = n[i];
		n[i--] = n[j];
		n[j++] = temp;
	}
	i = 0;
	while (i < 12)
	{
		ft_putnbr(n[i++]);
	}
	return (n);
}

int main(void)
{
	unsigned int	*p;
	
	p = ft_get_bits(1323);
	ft_putchar('\n');

	ft_putnbr(ft_active_bits_1(1323));/* "1323" в двоичной системе счисления будет равен "0101 0010 1011", а
									 * это значит что колличество "активных битов"(единиц) равно шести.
									 * Если вывод программы будет равен шести значит функция работает верно */
	ft_putchar('\n');
    return (0);
}