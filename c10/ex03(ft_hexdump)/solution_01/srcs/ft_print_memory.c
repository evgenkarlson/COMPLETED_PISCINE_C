/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:25:39 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 22:18:45 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	*ft_print_memory(void *addr, unsigned int size, int option)
{
	unsigned char	*curr;
	unsigned char	*end;
	int				asterisk;

	curr = (unsigned char*)addr;
	end = curr + size;
	asterisk = 0;
	while (curr < end && end - curr > 1)
	{
		if (curr + 16 >= end || (ft_memcmp(curr, curr - 16, 16) != 0))
		{
			asterisk = 0;
			print_line(curr, end, addr, option);
		}
		else if (ft_memcmp(curr, curr - 16, 16) == 0 && !asterisk)
			print_asterisk(&asterisk);
		curr += 16;
	}
	if (curr > (unsigned char*)addr)
	{
		print_hex(size, 7 + option);
		ft_putchar('\n');
	}
	return (addr);
}
