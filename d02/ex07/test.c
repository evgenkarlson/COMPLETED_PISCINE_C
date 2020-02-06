/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/14 12:33:14 by schapuis          #+#    #+#             */
/*   Updated: 2013/08/15 10:51:23 by schapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */


/* Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую */

#include <unistd.h>

int		ft_putchar(char c);


void	ft_check_print(int x[], int n)
{
	int i;
	int yes;

	i = 0;
	yes = 1;
	while (i < n - 1)
	{
		if (!(x[i] < x[i + 1]))
			yes = 0;
		i++;
	}
	if (yes == 1)
	{
		i = 0;
		while (i < n)
		{
			ft_putchar(x[i]);
			i++;
		}
		if (x[0] != 57 - n + 1)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	create_while(int x[], int k, int n)
{
	if (k == n - 1)
	{
		x[k] = 48;
		while (x[k] < 58)
		{
			if (n == 9 && x[0] > 49)
				break ;
			ft_check_print(x, n);
			x[k]++;
		}
	}
	else
	{
		x[k] = 48;
		while (x[k] < 58)
		{
			create_while(x, k + 1, n);
			x[k]++;
		}
	}
}

void	ft_print_combn(int n)
{
	int x[n];

	create_while(x, 0, n);
}


int		ft_putchar(char c)
{
	write(1, &c, 1);

	return (0);
}



int 	main(void)
{	
	ft_print_combn(5);

	return 0;
}
