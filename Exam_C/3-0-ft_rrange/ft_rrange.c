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
