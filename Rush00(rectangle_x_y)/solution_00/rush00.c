/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/19 15:08:43 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_line(int width, char begin_symbol, char middle_symbol, char end_symbol)
{
	int		i;
	
	i = 1;
	while(i <= width)
	{
		if(i == 1 )
			ft_putchar(begin_symbol);
		if(i <= (width -1))
			ft_putchar(middle_symbol);
		if(i == width)
			ft_putchar(end_symbol);
		i++;
	}
}

void	rush(int x, int y)
{
	int		i;

	i = 1;
	while(i <= y)
	{
		if (i == 1)
			ft_print_line(x, 'o', '-', 'o');
		if(i <= (y - 1))
			ft_print_line(x, '|', ' ', '|');
		if(i == y)
			ft_print_line(x, 'o', '-', 'o');
		ft_putchar('\n');
		i++;
	}
}

