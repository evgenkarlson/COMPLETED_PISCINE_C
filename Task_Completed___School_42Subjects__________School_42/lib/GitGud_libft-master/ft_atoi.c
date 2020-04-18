/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:53:45 by varnaud           #+#    #+#             */
/*   Updated: 2016/09/28 17:45:24 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		n;
	int		sign;

	n = 0;
	while (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\r' ||
			*str == '\n' || *str == '\f')
		str++;
	sign = *str == '-' ? -1 : 1;
	if (sign == -1 || *str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			n = n * 10 + (*str - '0');
		else
			break ;
		str++;
	}
	return (n * sign);
}
