/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 19:16:26 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */


#include "ft_point.h"
#include "unistd.h"


void	ft_putchar(char c)		/* Функция печати символа */
{
	write(1, &c ,1);
}

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

void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}


int		main(void)
{
	t_point		point;

	set_point(&point);

	ft_putnbr(point.x);
	ft_putchar(' ');
	ft_putnbr(point.y);

/*	ИЛИ так
	ft_putchar(point.x/10 + '0');
	ft_putchar(point.x%10 + '0');
	ft_putchar(' ');
	ft_putchar(point.y/10 + '0');
	ft_putchar(point.y%10 + '0');
*/
	return (0);
}

