/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/05/12 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */


#include "ft_point.h"
#include "unistd.h"


void	ft_putchar(char c)
{
	write(1, &c ,1);
}


void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}


int		main(void)
{
	t_point		point;

	set_point(&point);

	ft_putchar(point.x/10 + '0');
	ft_putchar(point.x%10 + '0');
	ft_putchar(' ');
	ft_putchar(point.y/10 + '0');
	ft_putchar(point.y%10 + '0');

	return (0);
}

