/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/08/17 00:09:07 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **
**  
**  
**  •  Напишите функцию, которая преобразует начальную часть строки, на которую
**  указывает 'str', в целое число 'int'.
**  •  Строка символов 'str' представляет собой число в определенной системе
**  счисления, заданной во втором параметре.
**  •  За исключением базового правила, функция должна работать точно так же, 
**  как и функция 'ft_atoi'.
**  •  Если указан неверный аргумент, функция должна вернуть 0. Примеры неверных
**  аргументов:
**  	◦ Если база, отражающая систему счисления, пуста или имеет размер 1;
**  	◦ Если база, отражающая систему счисления, содержит один и тот же символ
**      дважды;
**  	◦ Если база, отражающая систему счисления, содержит символы '+' или '-';
**  
**   
**  •  Ваша функция должна быть объявлена ​​следующим образом:
**  
**  	int		ft_atoi_base(char *str, char *base);
**  
**  
** ***********************************P.S.***********************************
** 
**   
**  Вас просят написать функцию, которая преобразует строковый аргумент str
**  из любой текущей системы счисления (на котрую укажет строка содержащая 
**  символы конвертируемой системы счисления '*base'(N <= 16)) в целое число 
**  с основанием 10 и возвращает его.
**  
**  Например, система счисления 4 распознает «0123», а система счисления 16
**  распознает «0123456789abcdef».
**  
**  Прописные буквы должны распознаваться: «12fdb3» совпадает с «12FDB3».
**  
**  Символы знака минус '-' интерпретируется, только если он является первым символом
**  строки.
**
**  
** ************************************************************************** **
**
**
**  Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую
**
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
	if (power < 0)
		return (0);
	if (power == 0)
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
		{
			if (base[i] == base[z])
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

	if (!(basen = validate_base3(base)))
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
