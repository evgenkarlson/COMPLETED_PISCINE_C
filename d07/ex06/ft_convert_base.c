/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************

• Создать функцию, которая возвращает результат преобразования строки nbr из 
  базового типа base_from в базовый тип base_to. 
• Строка должна иметь достаточно выделенной памяти.
• Число, представленное nbr, должно помещаться в int.
• Вот как это должно быть прототипировано:
  char *ft_convert_base(char *nbr, char *base_from, char *base_to);

   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_power(int nb, int power)
{
	int		result;

	result = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (result);
	while (power--)
		result *= nb;
	return (result);
}

int		ft_convert_to_dec(char *str, int basesize, int len)
{
	int		total;
	int		i;
	char	ch;

	i = -1;
	ch = 0;
	total = 0;
	while (str[++i])
	{
		ch = str[i];
		if (str[i] >= 'A' && str[i] <= 'F')
		{
			ch = 10 + (ch - 'A');
			total += ch * ft_power(basesize, len--);
		}
		if (str[i] >= 'a' && str[i] <= 'f')
		{
			ch = 10 + (ch - 'a');
			total += ch * ft_power(basesize, len--);
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			ch -= '0';
			total += ch * ft_power(basesize, len--);
		}
	}
	return (total / basesize);
}

char	*ft_convert_to_base(int nbr, int base_len, char *base_to, int sign)
{
	int		len;
	int		tmp;
	char	*result;

	len = 0;
	tmp = nbr;
	while (tmp)
	{
		tmp /= base_len;
		len++;
	}
	if (!(result = (char *)malloc(sizeof(char) * len)))
		return ((void *)0);
	result[len] = '\0';
	while (nbr)
	{
		result[--len] = base_to[nbr % base_len];
		nbr /= base_len;
	}
	result[0] = (sign == -1) ? '-' : result[0];
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		len;
	int		sign;
	
	len = ft_strlen(nbr);
	while (*nbr)
	{
		if (*nbr++ == '-')
		{
			len--;
			sign = -1;
		}
	}
	return (ft_convert_to_base(\
								ft_get_dec(nbr, ft_strlen(base_from), len),\
								ft_strlen(base_to),\
								base_to,\
								sign											));
}
