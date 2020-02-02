/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/14 12:33:14 by schapuis          #+#    #+#             */
/*   Updated: 2013/08/15 10:51:23 by schapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                       */
/*                                                                            */
/*      gcc test.c && chmod +x ./a.out && ./a.out	                      */
/* ************************************************************************** */


/* Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую */

#include <unistd.h>

int		ft_putchar(char c);






void	ft_commas(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}



void	ft_print_comb2(void)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (i < 100)
	{
		k = i + 1;
		while (k < 100)
		{
			ft_putchar(i / 10 + '0');
			ft_putchar(i % 10 + '0');
			ft_putchar(' ');
			ft_putchar(k / 10 + '0');
			ft_putchar(k % 10 + '0');
			if ((i / 10 != 9) || (i % 10 != 8))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			k++;
		}
		i++;
	}
}




int		ft_putchar(char c)
{
	write(1, &c, 1);

	return (0);
}

int		main(void)
{	
	ft_print_comb2();

	return 0;
}
