/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <adespond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 02:27:02 by adespond          #+#    #+#             */
/*   Updated: 2015/09/20 14:58:00 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colle.h"

int		ft_atoi(char *str)
{
	int		is_negative;
	int		value;

	is_negative = 0;
	value = 0;
	while (*str == ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		is_negative = 1;
		str++;
	}
	while ((*str <= '9') && (*str >= '0'))
	{
		value = (value * 10) - (*str - '0');
		str++;
	}
	if (!is_negative)
		value = -value;
	return (value);
}
