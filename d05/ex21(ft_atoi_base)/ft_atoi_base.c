/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
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


• Create a function that returns a number. This num is shaped as a string of characters.
• The string of characters reveals the number in a specific base, given as a second parameter.
• The function must handle negative numbers.
• The function must handle signs like man atoi.
• If there’s an invalid argument, the function should return 0. Examples of invalid arguments :
	◦ str is an empty string ;
	◦ the base is empty or size of 1;
	◦ str contains characters that aren’t part of the base, or aren’t + nor - ;
	◦ the base contains the same character twice ;
	◦ the base contains + or - ;
	◦ etc.


• Создайте функцию, которая возвращает число. Это число имеет форму строки символов.
• Строка символов показывает число в конкретном базовом типе, заданном во втором параметре.
• Функция должна обрабатывать отрицательные числа.
• Функция должна обрабатывать такие знаки, как man atoi.
• Если указан неверный аргумент, функция должна вернуть 0. Примеры неверных аргументов:
	◦ str - пустая строка;
	◦ база пуста или имеет размер 1;
	◦ str содержит символы, которые не являются частью базы или не + или -;
	◦ база содержит один и тот же символ дважды;
	◦ база содержит + или -;
	◦ и т. Д.


Ваша функция должна быть объявлена ​​следующим образом:
	int		ft_atoi_base(char *str, char *base);


   ***********************************P.S.***********************************
Нужно написать функцию, которая преобразует строковый аргумент str (база N <= 16)
в целое число (основание 10) и возвращает его.

Символы, распознаваемые на входе: 0123456789abcdef
Они, конечно, должны быть урезаны в соответствии с запрошенной базой. Для
Например, база 4 распознает «0123», а база 16 распознает «0123456789abcdef».

Прописные буквы также должны распознаваться: «12fdb3» совпадает с «12FDB3».

Знаки минус ('-') интерпретируются, только если они являются первым символом
строка.
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



int		ft_atoi_base(char *str, char *base)
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




/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */





static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ');
}

static int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_find_char(char c, char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int			ft_atoi_base(char *str, char *base)
{
	int		result;
	int		neg;
	int		base_len;

	result = 0;
	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	while (ft_isspace(*str))
		str++;
	neg = *str == '-';
	str += (*str == '+' || *str == '-') ? 1 : 0;
	while (ft_find_char(*str, base) < base_len)
		result = result * base_len - ft_find_char(*str++, base);
	return (neg ? result : -result);
}




/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int		is_pr3(char c)
{
	return (c >= 32 && c <= 126);
}

int		is_space3(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int		validate_base3(char *base)
{
	char	*ptr;
	int		i;
	int		vals[95];

	ptr = base;
	i = -1;
	while (i++ < 95)
		vals[i] = 0;
	i = 0;
	while (*ptr)
	{
		if (!is_pr3(*ptr))
			return (0);
		if (*ptr == '+' || *ptr == '-')
			return (0);
		if (vals[(*ptr) - 32])
			return (0);
		vals[(*ptr) - 32] = 1;
		i++;
		ptr++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int		parse_positive(char *str, char *base, int basen)
{
	char	*ptr;
	int		i;
	int		v;

	v = 0;
	while (*str)
	{
		i = 0;
		ptr = base;
		while (*ptr)
		{
			if (*str == *ptr)
				break ;
			i++;
			ptr++;
		}
		if (i >= basen)
			break ;
		v *= basen;
		v -= i;
		str++;
	}
	return (v);
}

int		ft_atoi_base(char *str, char *base)
{
	int		basen;
	int		v;
	int		is_positive;

	basen = validate_base3(base);
	if (!basen)
		return (0);
	is_positive = 0;
	while (is_space3(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		is_positive = -1;
		if (*str == '+')
			is_positive = 1;
		str++;
	}
	v = parse_positive(str, base, basen);
	v *= -(is_positive + !is_positive);
	return (v);
}




/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */




static int	ft_isspace(char c)
{
	if (c == '\t' || c == ' ' || c == '\n' || c == '\v' || c == '\f' ||
			c == '\r')
		return (1);
	return (0);
}

static int	_isdigit(char c)
{
	if ((c >= '0' && c <= '9') ||
			(c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}

static char	toupper(char c)
{
	if (c >= 'a' && c <= 'f')
		return (c - 32);
	return (c);
}

int			ft_atoi_base(char *str, int str_base)
{
	int		i;
	int		neg;
	int		ret;

	neg = 1;
	ret = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!_isdigit(toupper(str[i])))
			return (-1);
		ret *= str_base;
		ret += (str[i] <= '9') ? str[i] - '0' : toupper(str[i]) - 55;
		i++;
	}
	return (ret * neg);
}
