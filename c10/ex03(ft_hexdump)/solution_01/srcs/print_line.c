/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:25:39 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 22:15:19 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	print_line(unsigned char *curr, unsigned char *end, \
					unsigned char *addr, int option)
{
	unsigned int	i;

	print_hex_line(curr, end, (unsigned char*)addr, option);
	if (option)
	{
		print(" |");
		i = 0;
		while (i < 16 && curr + i < end)
		{
			if (curr[i] < 32 || curr[i] > 126)
				ft_putchar('.');
			else
				ft_putchar(curr[i]);
			i++;
		}
		ft_putchar('|');
	}
	ft_putchar('\n');
}
