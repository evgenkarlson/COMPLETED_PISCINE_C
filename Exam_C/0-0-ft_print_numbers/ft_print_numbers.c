/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <jaleman@student.42.us.org>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 16:44:37 by exam              #+#    #+#             */
/*   Updated: 2017/04/15 16:44:38 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************

Assignment name  : ft_print_numbers
Expected files   : ft_print_numbers.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that displays all digits in ascending order.
Напишите функцию, которая отображает все цифры в порядке возрастания.

Your function must be declared as follows:
Ваша функция должна быть объявлена ​​следующим образом:

void	ft_print_numbers(void);

   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include <unistd.h>

int	main(void)
{
	int i;
	char a;
	
	i = 48;
	while (i <= 57)
	{
		a = i;
		write(1, &a, 1);
		i++;
	}
	return (0);
}


/* ************************************************************************** */
/* ********************************_OR_THAT_:)******************************* */
/* ************************************************************************** */




#include <unistd.h>

void	ft_print_numbers(void)
{
	write(1, "0123456789", 10);
}
