/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-0____ft_rrange.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/01/20 03:31:54 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** **


Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Напишите следующую функцию:

int     *ft_rrange(int start, int end);


Она должна выделить (с помощью malloc ()) массив целых чисел, заполнить его 
последовательными значениями, которые начинаются в конце и заканчиваться в 
начале (включая start и end!), А затем возвращать указатель на первое 
значение массива.


Примеры:

- С помощью (1, 3) вы вернете массив, содержащий 3, 2 и 1
- С помощью (-1, 2) вы вернете массив, содержащий 2, 1, 0 и -1.
- С помощью (0, 0) вы вернете массив, содержащий 0.
- С помощью (0, -3) вы вернете массив, содержащий -3, -2, -1 и 0.


** ************************************************************************** */
/* ************************************************************************** */


#include <stdlib.h>

int		*ft_rrange(int start, int end)
{
	int		*rrange;
	int		i;

	if (start > end)
		i = (start - end) + 1;
	else
		i = (end - start) + 1;
	rrange = (int *)malloc(sizeof(int) * i);
	while (i)
	{
		rrange[i--] = start;
		start -= (start > end) ? (-1) : (1);
	}
	rrange[i] = start;
	return (rrange);
}


/* ************************************************************************** */
/* ************************************************************************** */


#include <stdlib.h>

int		*ft_rrange(int start, int end)
{
	int		*rrange;
	int		i;

	if (start > end)
		rrange = (int *)malloc(sizeof(int) * (start - end) + 1);
	else
		rrange = (int *)malloc(sizeof(int) * (end - start) + 1);
	i = 0;
	while (start != end)
	{
		rrange[i++] = end;
		end -= (start > end) ? -1 : 1;
	}
	rrange[i] = end;
	return (rrange);
}


/* ************************************************************************** **
**                               TEST
** ************************************************************************** **

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
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

int		*ft_rrange(int start, int end)
{
	int		*rrange;
	int		i;

	if (start > end)
		i = (start - end) + 1;
	else
		i = (end - start) + 1;
	rrange = (int *)malloc(sizeof(int) * i);
	while (i--)
	{
		rrange[i] = start;
		start -= (start < end) ? (-1) : (1);
	}
	rrange[i] = end;
	return (rrange);
}

int		main(void)
{
	int	*arr;
	int	i;

	i = 10;
	arr = ft_rrange(-10, -1);

	while (i--)
		ft_putnbr(arr[i]);
	ft_putchar('\n');
	return (0);
}

** ************************************************************************** */
