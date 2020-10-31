/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 19:27:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */


#include <unistd.h>

void	ft_putchar(char c)			/* функция печати символа */
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)				/* функция печати числа */
{
	int	temp;
	int	size;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb == -2147483648)
	{
		ft_putchar('2');
		nb = -147483648;
	}
	size = 1;
	temp = nb;
	while ((temp /= 10) > 0)
	{
		size *= 10;
	}
	temp = nb;
	while (size)
	{
		ft_putchar((char)((temp / size) + 48));
		temp %= size;
		size /= 10;
	}
}

int		ft_bouton(int i, int j, int k)	/* функция принимает параметры параметр состоящий из трех аргументов типа int и будет возвращать среднее значение носителя */
{
	if ((i > j && i < k) || (i > k && i < j))
		return (i);
	if ((k > j && k < i) || (k > i && k < j))
		return (k);
	if ((j > i && j < k) || (j > k && j < i))
		return (j);
	if (i == j)
		return (i);
	if (j == k)
		return (j);
	if (k == i)
		return (k);
	return (0);
}

int		main()							
{
	ft_putnbr(ft_bouton(1,1,2));
	ft_putchar('\n');
	return 0;
}