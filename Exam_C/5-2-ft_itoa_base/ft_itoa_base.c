/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 05:13:49 by jaleman           #+#    #+#             */
/*   Updated: 2017/01/03 05:19:03 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


Assignment name  : ft_itoa_base
Expected files   : ft_itoa_base.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that converts an integer value to a null-terminated string
using the specified base and stores the result in a char array that you must
allocate.
Напишите функцию, которая преобразует целочисленное значение в строку с нулевым
символом в конце, используя указанную базу, и сохраняет результат в массиве char,
который вы должны выделить.

The base is expressed as an integer, from 2 to 16. The characters comprising
the base are the digits from 0 to 9, followed by uppercase letter from A to F.
Основание выражается в виде целого числа от 2 до 16. Символами, составляющими
основание, являются цифры от 0 до 9, за которыми следует заглавная буква от A до F.

For example, base 4 would be "0123" and base 16 "0123456789ABCDEF".
Например, основание 4 будет «0123», а основание 16 «0123456789ABCDEF».

If base is 10 and value is negative, the resulting string is preceded with a
minus sign (-). With any other base, value is always considered unsigned.
Если base равен 10, а значение отрицательное, результирующей строке предшествует
знак минус (-). Для любой другой базы значение всегда считается без знака.

Your function must be declared as follows:
Ваша функция должна быть объявлена ​​следующим образом:


char	*ft_itoa_base(int value, int base);


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <stdlib.h>

char		*ft_itoa_base(int value, int base)
{
	int		len;
	long	nbr;
	char	*pointer;
	char	*base_string = "0123456789ABCDEF";

	if (value == 0)
		return ("0");
	len = 0;
	nbr = value;
	while (nbr)
	{
		nbr /= base;
		len += 1;
	}
	nbr = value;
	if (nbr < 0)
	{
		if (base == 10)
			len += 1;
		nbr *= -1;
	}
	if (!(pointer = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	pointer[len] = '\0';
	while (nbr)
	{
		pointer[--len] = base_string[nbr % base];
		nbr /= base;
	}
	if (value < 0 && base == 10)
		pointer[0] = '-';
	return (pointer);
}
