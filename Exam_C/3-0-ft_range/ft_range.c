/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 00:51:20 by jaleman           #+#    #+#             */
/*   Updated: 2016/11/16 00:51:20 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 


Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:
Напишите следующую функцию:


int     *ft_range(int start, int end);


It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.
Он должен выделить (с помощью malloc ()) массив целых чисел, заполнить его
последовательными значениями, которые начинаются с начала и заканчиваются в конце
(включая начало и конец!), А затем возвращать указатель на первое значение массива.

Examples:
Примеры:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
- С помощью (1, 3) вы вернете массив, содержащий 1, 2 и 3.
- С помощью (-1, 2) вы вернете массив, содержащий -1, 0, 1 и 2.
- С помощью (0, 0) вы вернете массив, содержащий 0.
- С помощью (0, -3) вы вернете массив, содержащий 0, -1, -2 и -3.





/* ************************************************************************** */
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
		range[i++] = start;
		start += (start > end) ? -1 : 1;
	}
	range[i] = start;
	return (range);
}
