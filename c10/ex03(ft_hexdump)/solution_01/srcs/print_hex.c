/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:25:35 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 22:16:07 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	print_hex(unsigned int value, int length)
{
	char	*base;
	int		maxlength;
	char	output[sizeof(int) * 2];
	int		i;

	maxlength = sizeof(int) * 2;
	i = maxlength - 1;
	base = "0123456789abcdef";
	while (value > 0)
	{
		output[i] = base[value % 16];
		value /= 16;
		i--;
	}
	while (i >= 0)
		output[i--] = '0';
	i = maxlength - length;
	while (i < maxlength)
		ft_putchar(output[i++]);
}
