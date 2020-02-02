/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 21:27:38 by jaleman           #+#    #+#             */
/*   Updated: 2017/03/30 21:27:39 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i += 1;
	return (i);
}

static int	ft_power(int nb, int power)
{
	int		result;

	result = 1;
	if (power < 0)
		return (0);
	while (power--)
		result *= nb;
	return (result);
}

static int	ft_calculate_dec(char *str, int basesize, int size)
{
	int		total;
	int		i;
	char	c;

	i = -1;
	c = 0;
	total = 0;
	while (str[++i])
	{
		c = str[i];
		if (str[i] >= 'A' && str[i] <= 'F')
		{
			c = 10 + (c - 'A');
			total += c * ft_power(basesize, size--);
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			c -= '0';
			total += c * ft_power(basesize, size--);
		}
	}
	return (total / basesize);
}

static char	*ft_itoa_from_base(int nbr, int base_len, char *base_to, int sign)
{
	int		len;
	int		tmp;
	char	*result;

	len = 0;
	tmp = nbr;
	while (tmp)
	{
		tmp /= base_len;
		len += 1;
	}
	if (!(result = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	result[len] = '\0';
	while (nbr)
	{
		result[--len] = base_to[nbr % base_len];
		nbr /= base_len;
	}
	result[0] = (sign == -1) ? '-' : result[0];
	return (result);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		a;
	int		b;
	int		i;
	int		len;
	int		sign;

	a = 0;
	b = 0;
	i = 0;
	len = ft_strlen(nbr);
	while (nbr[i] != '\0')
	{
		if (nbr[i] == '-')
		{
			len -= 1;
			sign = -1;
		}
		i += 1;
	}
	return (ft_itoa_from_base(ft_calculate_dec(nbr, ft_strlen(base_from), len),\
			ft_strlen(base_to), base_to, sign));
}
