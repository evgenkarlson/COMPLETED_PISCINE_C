/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 19:27:40 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */


#include <stdio.h>


void	ft_takes_place(int hour)
{
	if ((hour >= 0) && (hour <= 24))
	{
		int h1;
		int h2;
		char	am_pm_1;
		char	am_pm_2;

		h1 = ((hour == 12) ? hour : (hour % 12));
		h2 = (((hour + 1) == 12) ? (hour + 1) : ((hour + 1) % 12));
		am_pm_1 = (((hour < 12) || (hour > 23)) ? 'A' : 'P');
		am_pm_2 = ((((hour + 1) < 12) || ((hour + 1) > 23)) ? 'A' : 'P');
		printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 %c.M. AND %d.00 %c.M.\n", h1, am_pm_1, h2, am_pm_2);
	}
	else
		printf("Number is wrong");
}


int		main(void)				/* Основаная функция */
{
	ft_takes_place(23);
	return (0);
}