/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/07 23:25:59 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **
**
**
**  - Создайте функцию, которая возвращает 1, если строка, заданная в качестве 
**  параметра, содержит только строчные буквенные символы, и 0, если она содержит 
**  любой другой символ.
**
**
**  - Функция должна возвращать 1, если строка 'str' пуста(не содержит др символов).
**
**
**  - Вот как это должно быть обьявлено:
**
**       int	ft_str_is_lowercase(char *str);
**
**
** ************************************************************************** **
**
**
** Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую
**
**
** ************************************************************************** */
/* ************************************************************************** */


int		ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= 'a') && (str[i] <= 'z')))
			return (0);
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


int		iss_lowercase(char c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (1);
	return (0);
}

int		ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(iss_lowercase(str[i])))
			return (0);
		i++;
	}
	return (1);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int		ft_str_is_lowercase(char *str)
{
	int	i;
	int	b;

	b = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			b = 1;
		else
			return (0);
		i++;
	}
	return (b);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


int		ft_str_is_lowercase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 97 && str[i] <= 122))
			return (0);
		i++;
	}
	return (1);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
