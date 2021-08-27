/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-2____ft_atoi_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/01/20 03:27:46 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** **


Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None

--------------------------------------------------------------------------------

Напишите функцию, которая преобразует строковый аргумент str (с основанием N <= 16)
в целое число (с основанием 10) и возвратит его.

Символы, распознаваемые на входе: 0123456789abcdef

Они, конечно, должны быть урезаны в соответствии с запрошенной базой. Например,
база 4 распознает «0123», а база 16 распознает «0123456789abcdef».

Прописные буквы также должны распознаваться: «12fdb3» совпадает с «12FDB3».

Знаки минус ('-') интерпретируются, только если они являются первым символом строки.


Ваша функция должна быть объявлена ​​следующим образом:

int	ft_atoi_base(const char *str, int str_base);


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

int		ft_atoi_base(const char *str, int str_base)
{
	int		num;
	int		negative;
	int		i;
	int		pow;

	negative = 1;
	i = 0;
	if ((str_base >= 2))
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
			if ((ft_ctoi(str[i]) != -1) && (ft_ctoi(str[i]) < str_base))
				num += ft_ctoi(str[i]) * ft_pow(str_base, pow++);
		}
		return (num * negative);
	}
	return (0);
}

/* ************************************************************************** */
/* ************************************************************************** */


int		ft_check_str(char *str, int base)
{
	int	n;

	if (!*str || !*(str + 1) || (base < 2 || base > 16))
		return (0);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			n = (*str - '0');
		if (*str >= 'A' && *str <= 'Z')
			n = (*str - 'A' + 10);
		else if (*str >= 'a' && *str <= 'z')
			n = (*str - 'a' + 10);
		if (n >= base)
			return (0);
		str++;
	}
	return (1);
}


int	ft_atoi_base(const char *str, int str_base)
{
	int		i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	if (!(*str) || !ft_check_str((char *)str, str_base))
		return (0);
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' || \
		str[i] == ' ' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= 'A' && 'F' >= str[i])
			nbr = (nbr * str_base) + (str[i] - 'A' + 10);
		else if (str[i] >= 'a' && 'f' >= str[i])
			nbr = (nbr * str_base) + (str[i] - 'a' + 10);
		else
			nbr = (nbr * str_base) + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}


