/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:00:34 by lkinzel           #+#    #+#             */
/*   Updated: 2017/07/18 18:50:06 by lkinzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	x;
	int total;
	int is_negative;

	is_negative = 0;
	x = 0;
	total = 0;
	while (str[x] == ' ' || str[x] == '\n' || str[x] == '\r' || str[x] == '\f'
			|| str[x] == '\t' || str[x] == '\v' || str[x] == '+')
		x++;
	if (str[x] == '-')
	{
		is_negative = 1;
		x++;
	}
	while (str[x] >= 48 && str[x] <= 57)
	{
		total *= 10;
		total += ((int)str[x] - 48);
		x++;
	}
	if (is_negative)
		return (-total);
	else
		return (total);
}
