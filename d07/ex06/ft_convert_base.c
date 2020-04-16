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


int		ft_ctoi(char c)				
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (-1);
}

int		ft_pow(int nb, int power)
{
	int	result;

	result = 1;
	if(power < 0)
		return (0);
	if(power == 0)
		return (1);
	while (power--)
		result *= nb;
	return (result);
}

int		ft_check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (!base || !base[1])
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (!((base[i] >= '0' && base[i] <= '9') || (base[i] >= 'a' \
				&& base[i] <= 'z') || (base[i] >= 'A' && base[i] <= 'Z')))
			return (0);
		while (base[z])
			if (base[i] == base[z++])
				return (0);
		i++;
	}
	return (i);
}

int		ft_get_dec(char *str, char *base)
{
	int		num;
	int		negative;
	int		i;
	int		pow;
	int		base_type;

	pow = 0;
	i = 0;
	negative = 1;
	num = 0;
	base_type = ft_check_base(base);
	if(base_type)
	{
		if (*str == '-')
		{
			i++;
			negative = -1;
		}
		while (str[i])
			i++;
		while (--i >= 0)
		{
			if (ft_ctoi(str[i]) != -1 && ft_ctoi(str[i]) < base_type)
				num += ft_ctoi(str[i]) * ft_pow(base_type, pow++);
		}
		return (num * negative);
	}
	return (0);
}

void	*ft_atoi_base(int nbr, char *base)
{
	int		i;
	int		temp;
	int		n[100];
	char	*final;

	i = 0;
	if ((temp = ft_check_base(base)))
	{
		if (nbr < 0)
		{
			nbr *= -1;
			ft_putchar('-');
		}
		while (nbr)
		{
			n[i] = nbr % temp;
			nbr /= temp;
			i++;
		}
		if ((final = malloc(sizeof(char) * (i + 1))) == ((void *)0))
			return (((void *)0));
		temp = 0;
		while (i > 0)
		{
			--i;
			final[temp] = base[n[i]];
			temp++;
		}
	}
	return (final);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int dec;
	char *final;

	dec = ft_get_dec(nbr, base_from);
	final = ft_atoi_base(dec, base_to);
	return (final);
}



/* ************************************************************************** */
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
