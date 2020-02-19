/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */

/* 
 * В примере в строке «Fuckin.Good.day.coming», с помощью функции ft_strstr, ищется
 * первое вхождение строки: «Good». На консоль выводится номер первого элемента 
 * найденной строки.
 */

#include <unistd.h>

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


void	ft_putchar(char c)			/* функция вывода символа */
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
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

void	ft_putstr(char *str)		
{
	int	i;						

	i = 0;						
	while (str[i] != '\0')		
	{
		ft_putchar(str[i]);		
		i++;					
	}
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	z;
	int	lenght;

	i = 0;
	z = 0;
	lenght = 0;
	while (to_find[lenght])
		lenght++;
	if (lenght == 0)
		return (str);
	while (str[i])
	{
		while (to_find[z] == str[i + z])
		{
			if (z == lenght - 1)
				return (str + i);
			z++;
		}
		z = 0;
		i++;
	}
	return (0);
}


int 	main(void)
{
	char	r[] = {"Fuckin.Good.day.coming"};
	char	*p;


	p = ft_strstr(r, "Good"); 	/* Написать строку в двойных кавычка в аргументах где ожидается адресс массива
								 * тоже можно!
								 * Всё потому что перед передачей строки в функцию компилятор выделяет для нее 
								 * память и уже сам меняет саму эту строку на адрес который хранит строку "Good" 
								 */


	if ( p == NULL)
    	ft_putstr("Строка не найдена\n");
   else
    {
		ft_putstr("Искомая строка начинается с символа: ");
		ft_putnbr(p - r + 1);	/* Так вычислем позицию первого элемента найденной строки. */
		ft_putchar('\n');
	}

	return (0);
}

