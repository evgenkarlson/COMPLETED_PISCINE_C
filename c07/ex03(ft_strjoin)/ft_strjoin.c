/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/11 18:02:14 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **
**
**
**  - Напишите функцию, которая объединит все строки, на которые указывает 'strs',
**  в одну и разделит эти строки символами из строки 'sep'.
**
**  - 'size' - это количество адресов строк в массиве указателей на строки 'strs'.
**
**  - Если 'size' равен 0, то это должна быть свободная пустая строка.
**
**  - Вот как функция должна быть обьявлена:
**
**		char	*ft_strjoin(int size, char **strs, char *sep);
**
**
**
** ************************************************************************** **
**
**  Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую
**
** ************************************************************************** */
/* ************************************************************************** */


#include <stdlib.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (dest[i])
		i++;
	while (src[x])
	{
		dest[i] = src[x];
		i++;
		x++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;
	int		length;

	i = 0;
	length = 0;
	while (i < size)
	{
		length += ft_strlen(strs[i]);
		i++;
	}
	length += ((size - 1) * ft_strlen(sep));
	if ((str = (char *)malloc(sizeof(char) * (length + 1))) == ((void *)0))
		return ((void *)0);
	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if ((i + 1) < size)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}

/* ************************************************************************** */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep) 
{
	int		i;
	int		j;
	int		z;
	char	*str;
	int		length;

	i = 0;
	length = 0;
	while (i < size)
	{
		length += ft_strlen(strs[i]);
		i++;
	}
	length += ((size - 1) * ft_strlen(sep));
	if ((str = (char *)malloc(sizeof(char) * (length + 1))) == ((void *)0))
		return ((void *)0);
	i = 0;
	j = 0;
	while (j < size)
	{
		z = 0;
		while (strs[j][z])
		{
			str[i] = strs[j][z];
			z++;
			i++;
		}
		if ((j + 1) < size)
		{
			z = 0;
			while (sep[z])
			{
				str[i] = sep[z];
				z++;
				i++;
			}
		}
		j++;
	}
	str[i] = '\0';
	return (str);
}