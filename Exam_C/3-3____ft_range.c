/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-3____ft_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/01/20 03:35:28 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** **


Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc

-- -------------------------------------------------------------------------- --

Напишите следующую функцию:

int     *ft_range(int start, int end);


Она должна выделить (с помощью malloc ()) массив целых чисел, заполнить его 
последовательными значениями, которые начинаются в конце и заканчиваться в 
начале (включая start и end!), А затем возвращать указатель на первое 
значение массива.


Примеры:

- С помощью (1, 3) вы вернете массив, содержащий 1, 2 и 3.
- С помощью (-1, 2) вы вернете массив, содержащий -1, 0, 1 и 2.
- С помощью (0, 0) вы вернете массив, содержащий 0.
- С помощью (0, -3) вы вернете массив, содержащий 0, -1, -2 и -3.


** ************************************************************************** */
/* ************************************************************************** */


#include <stdlib.h>

int		*ft_range(int start, int end)
{
	int		*range;
	int		i;

	if (start > end)
		i = (start - end) + 1;
	else
		i = (end - start) + 1;
	range = (int *)malloc(sizeof(int) * i);
	while (i)
	{
		range[i--] = start;
		start -= (start > end) ? (-1) : (1);
	}
	range[i] = start;
	return (range);
}


/* ************************************************************************** */
/* ************************************************************************** */


#include <stdlib.h>

int		*ft_range(int start, int end)
{
	int		*range;
	int		i;

	if (start > end)
		range = (int *)malloc(sizeof(int) * (start - end) + 1);
	else
		range = (int *)malloc(sizeof(int) * (end - start) + 1);
	i = 0;
	while (start != end)
	{
		range[i++] = end;
		end -= (start > end) ? -1 : 1;
	}
	range[i] = end;
	return (range);
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

int		*ft_range(int start, int end)
{
	int		*range;
	int		i;

	if (start > end)
		i = (start - end) + 1;
	else
		i = (end - start) + 1;
	range = (int *)malloc(sizeof(int) * i);
	while (i--)
	{
		range[i] = start;
		start -= (start < end) ? (-1) : (1);
	}
	range[i] = end;
	return (range);
}

int		main(void)
{
	int	*arr;
	int	i;

	i = 10;
	arr = ft_range(-10, -1);

	while (i--)
		ft_putnbr(arr[i]);
	ft_putchar('\n');
	return (0);
}

** ************************************************************************** */