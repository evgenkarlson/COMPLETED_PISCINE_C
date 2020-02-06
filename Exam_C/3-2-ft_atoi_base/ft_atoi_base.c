/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 04:48:29 by jaleman           #+#    #+#             */
/*   Updated: 2016/11/16 04:48:30 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.
Напишите функцию, которая преобразует строковый аргумент str (основание N <= 16)
в целое число (основание 10) и возвращает его.

The characters recognized in the input are: 0123456789abcdef
Символы, распознаваемые на входе: 0123456789abcdef

Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".
Они, конечно, должны быть урезаны в соответствии с запрошенной базой. Например,
база 4 распознает «0123», а база 16 распознает «0123456789abcdef».

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".
Прописные буквы также должны распознаваться: «12fdb3» совпадает с «12FDB3».

Minus signs ('-') are interpreted only if they are the first character of the
string.
Знаки минус ('-') интерпретируются, только если они являются первым символом строки.

Your function must be declared as follows:
Ваша функция должна быть объявлена ​​следующим образом:


int	ft_atoi_base(const char *str, int str_base);


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


int		nbr_inbase(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + base - 10)) || \
	(c >= 'a' && c <= ('a' + base - 10)));
}

int		ft_atoi_base(const char *str, int base)
{
	int		i;
	int		nbr;
	int		sign;

	if (!str[0] || (base < 2 || base > 16))
		return (0);
	nbr = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' || \
		str[i] == ' ' || str[i] == '\r' || str[i] == '\f')
		i += 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] && nbr_inbase(str[i], base))
	{
		if (str[i] >= 'A' && 'F' >= str[i])
			nbr = (nbr * base) + (str[i] - 'A' + 10);
		else if (str[i] >= 'a' && 'f' >= str[i])
			nbr = (nbr * base) + (str[i] - 'a' + 10);
		else
			nbr = (nbr * base) + (str[i] - '0');
		i += 1;
	}
	return (nbr * sign);
}
