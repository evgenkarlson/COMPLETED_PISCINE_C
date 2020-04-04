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
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */

#include <unistd.h>


static int	ft_isspace(int c)				/* Функция принимает в аргументы символ и проверяет является ли он "пустым" символом */
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ');
}

static int	ft_strlen(char *str)			/* функция принимает адресс массива символов(строки) и возвращает его длинну */
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_find_char(char c, char *str)	/* функция принимает символ и адресс массива симолов(строку), и ищет этот символ в массиве,
											 * Если функция нашла там такой символ то она возвращает номер позиции этого символа в массиве */
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





int		ft_ctoi(char c)				/* Функция переводит символ в число и возвращает его. Если символ условиям не соответствует то вохвращается (-1)*/
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (-1);
}

double	ft_pow(double x, double y)	/* Функция возведения в степень */
{
	double	r;						/* обьявляем переменную для хранения добытого результата */

	r = 1;							/* инициализируем ее единицей для начала вычислений результата возведения в степень */
	if(y < 0)						/* Проверяем соответствует ли число в степени условиям */
		return (0);					/* Если не соответствует то завершаем функцию и возвращаем ноль */
	if(y == 0)						/* Проверяем соответствует ли число в степени условиям */
		return (0);					/* Если не соответствует то завершаем функцию и возвращаем ноль */
	while (y--)				/* Запускаем цикл который умножит переменную 'r' на 'x' столько раз сколько записано в 'y'. Возведет в 'x' в степень 'y'. */
		r *= x;				/* Умножая 'r' на 'x' и сохраняя результат в той же переменной 'r' столько раз сколько записано в 'y'  
							 * мы сможем получить результат возведения в степень 'y' числа 'x'. */
	return (r);						/* Завершаем функцию и возвращаем результат возведения в степень */
}

int		ft_atoi_base(char *s, int b)
{
	int		n;
	int		negative;
	int		i;
	int		exp;

	exp = 0;
	i = 0;
	negative = 1;
	n = 0;
	if (*s == '-')
	{
		i++;
		negative = -1;
	}
	while (s[i])
		i++;
	while (--i >= 0)
	{
		if (ft_ctoi(s[i]) != -1 && ft_ctoi(s[i]) < b)
			n += ft_ctoi(s[i]) * ft_pow(b, exp++);
	}
	return (n * negative);
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
