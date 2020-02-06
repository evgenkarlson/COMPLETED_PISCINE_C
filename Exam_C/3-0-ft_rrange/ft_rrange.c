/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 19:01:00 by exam              #+#    #+#             */
/*   Updated: 2017/07/21 19:31:42 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:
Напишите следующую функцию:


int     *ft_rrange(int start, int end);


It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.
Он должен выделить (с помощью malloc ()) массив целых чисел, заполнить его последовательными значениями, которые начинаются в конце и заканчиваться в начале (включая start и end!), А затем возвращать указатель на первое значение массива.

Examples:
Примеры:


- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
- С помощью (1, 3) вы вернете массив, содержащий 3, 2 и 1
- С помощью (-1, 2) вы вернете массив, содержащий 2, 1, 0 и -1.
- С помощью (0, 0) вы вернете массив, содержащий 0.
- С помощью (0, -3) вы вернете массив, содержащий -3, -2, -1 и 0.


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <stdlib.h>
#define ABS(c) 	(c > -1 ? c : -c)

int		calcdiff(int a, int b)
{
	if ((a > -1 && b > -1) || (a < 0 && b < 0))
	{
		if (ABS(a) > ABS(b))
			return (ABS(a) - ABS(b));
		else
			return (ABS(b) - ABS(a));
	}
	else
	{
		return (ABS(a) + ABS(b));
	}
}

int		*ft_rrange(int start, int end)
{
	int	*arr;
	
	int i = 0;
	arr = (int*)malloc(sizeof(int) * calcdiff(start, end) + 1);
	if (end > start)
	{
		while (end >= start)
		{
			arr[i] = end;
			end--;
			i++;
		}
	}
	else if (end < start)
	{
		while (end <= start)
		{
			arr[i] = end;
			end++;
			i++;
		}
	}
	else
	{
		arr[0] = start;
	}
	return arr;
}



/* ************************************************************************** */
/* ********************************_OR_THAT_:)******************************* */
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
