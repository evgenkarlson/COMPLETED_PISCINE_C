/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/02/16 23:38:04 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **
**
**
**  - Создать функцию, которая возвращает результат преобразования строки 'nbr' 
**  из базового типа 'base_from' в базовый тип 'base_to'. 
**
**  - 'nbr', 'base_from' и 'base_to' могут быть не доступен для записи.
**
**  - 'nbr' будет следовать тем же правилам, что и 'ft_atoi_base' (из другого
**   модуля). Остерегайтесь '+', '-' и пробелов.
**
**  - Число, представленное 'nbr', должно уместиться внутри 'int'.
**
**  - Если база, отражающая систему счисления, неверна, следует вернуть нулевой
**  указатель(NULL).
**
**  - Возвращаемое число может иметь знак минус '-' при необходимости, но оно не
**  должно иметь никаких пробелов и никакого знака '+'.
**
**  - Вот как функция должна быть обьявлена:
**
**		char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
**
**
**
** ************************************************************************** **
**
**  Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую
**
** ************************************************************************** */
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
	if (!base || !base[1])
		return (0);
	while (base[i])
	{
		if (!((base[i] >= '0' && base[i] <= '9') || (base[i] >= 'a' \
				&& base[i] <= 'z') || (base[i] >= 'A' && base[i] <= 'Z')))
			return (0);
		z = i + 1;
		while (base[z])
		{
			if (base[i] >= base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int		num;
	int		negative;
	int		i;
	int		pow;
	int		base_type;

	negative = 1;
	i = 0;
	if((base_type = ft_check_base(base)))
	{
		if (*str == '-')
		{
			i++;
			negative = -1;
		}
		while (str[i])
			i++;
		pow = 0;
		num = 0;
		while (--i >= 0)
		{
			if ((ft_ctoi(str[i]) != -1) && (ft_ctoi(str[i]) < base_type))
				num += ft_ctoi(str[i]) * ft_pow(base_type, pow++);
		}
		return (num * negative);
	}
	return (0);
}

void	*ft_itoa_base(int nbr, char *base)
{
	int		i;
	int		j;
	int		base_type;
	int		n[16];
	char	*final;

	i = 0;
	if ((base_type = ft_check_base(base)))
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			n[i] = '-';
			i++;
		}
		while (nbr)
		{
			n[i] = nbr % base_type;
			nbr /= base_type;
			i++;
		}
		if ((final = malloc(sizeof(char) * (i + 1))) == ((void *)0))
			return (((void *)0));
		if ((n[0] == '-'))
			final[0] = n[0];
		j = 1;
		while (i > 0)
		{
			--i;
			final[j] = base[n[i]];
			j++;
			
		}
		final[j] = '\0';
	}
	return (final);	
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int dec;
	char *final;

	dec = ft_atoi_base(nbr, base_from);
	final = ft_itoa_base(dec, base_to);
	return (final);
}



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

int		ft_atoi_base(char *str, int base_type)
{
	int		num;
	int		negative;
	int		i;
	int		pow;

	negative = 1;
	i = 0;
	if ((base_type >= 2))
	{
		if (*str == '-')
		{
			i++;
			negative = -1;
		}
		while (str[i])
			i++;
		pow = 0;
		num = 0;
		while (--i >= 0)
		{
			if ((ft_ctoi(str[i]) != -1) && (ft_ctoi(str[i]) < base_type))
			{
				num += ft_ctoi(str[i]) * ft_pow(base_type, pow++);
			}
		}
		return (num * negative);
	}
	return (0);
}

char	*ft_itoa_base(int nbr, int base_type)
{
	int		i;
	int		j;
	char	temp[16];
	char	*final;

	i = 0;
	if ((base_type >= 2))
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			temp[i] = '-';
			i++;
		}
		while (nbr)
		{
			temp[i] = nbr % base_type;
			nbr /= base_type;
			i++;
		}
		if ((final = (char *)malloc(sizeof(char) * (i + 1))) == ((void *)0))
			return (((void *)0));
		if ((temp[0] == '-'))
			final[0] = temp[0];
		j = 1;
		while (i > 1)
		{
			--i;
			if (temp[i] < 10)
				final[j] = temp[i] + '0';
			if (temp[i] >= 10)
				final[j] = temp[i] - 10 + 'A';
/* ******************************************************************************** **
** SHORT:       final[j] = (temp[i] < 10) ? (temp[i] + '0') : (temp[i] - 10 + 'A'); **
** ******************************************************************************** **/
			j++;
		}
		final[j] = '\0';
	}
	return (final);	
}


int		ft_check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	if (!base || !base[1])
		return (0);
	while (base[i])
	{
		if (!((base[i] >= '0' && base[i] <= '9') || (base[i] >= 'a' \
				&& base[i] <= 'z') || (base[i] >= 'A' && base[i] <= 'Z')))
			return (0);
		z = i + 1;
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int dec;
	char *final;

	dec = ft_atoi_base(nbr, ft_check_base(base_from));
	final = ft_itoa_base(dec, ft_check_base(base_to));
	return (final);
}




/* ************************************************************************** */
/* ************************************************************************** */




#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
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
