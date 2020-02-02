/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 20:07:07 by exam              #+#    #+#             */
/*   Updated: 2017/07/21 20:57:22 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define ABS(nbr) ( nbr > 0 ? nbr : -nbr )
int		calcdigs(unsigned int nbr)
{
	int i = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	char *str;
	if (nbr == 0)
		return ("0");

	unsigned int nb;
	int o  = 0;
	if (nbr < 0)
		o = 1;
	
	if (nbr == -2147483648)
		nb = 2147483648;
	else
		nb = ABS(nbr);
	str = (char*)malloc(sizeof(char) * calcdigs(nb) + 1 + o);
	
	if (o)
		str[0] = '-';
	int i = calcdigs(nb) - 1;
	str[i + o] = '\0';
	while (i >= 0)
	{
		str[i + o] = ABS(nb % 10) + 48;
		nb /= 10;
		i--;
	}
	return (str);
}
