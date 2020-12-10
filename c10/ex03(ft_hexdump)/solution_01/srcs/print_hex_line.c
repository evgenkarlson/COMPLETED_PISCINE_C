/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:25:35 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 22:15:50 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	print_hex_line(unsigned char *curr, unsigned char *end, \
						unsigned char *addr, int option)
{
	unsigned int i;

	i = 0;
	print_hex((unsigned int)(curr - addr), 7 + option);
	ft_putchar(' ');
	if (option)
		ft_putchar(' ');
	while (i < 16)
	{
		if (curr + i < end)
			print_hex((unsigned int)curr[i], 2);
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (i != 15 || option)
			ft_putchar(' ');
		if (i == 7 && option)
			ft_putchar(' ');
		i++;
	}
}
