/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
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
 *
 * 
 *	• Напишите функцию "ft_join", которая объединит в одну символьную строку 
 *	массив, переданный в параметре. Аргумент разделитель будет служить 
 *	«связующим звеном» между элементами
 * 
 *	• Эта функция будет прототипирована следующим образом:
 * 									char	*ft_join(char **tab, char *sep)
 * 
 * 	P.S  Активный бит = 1
 * 
 * #########################################################################
 * P.S Про операции с побитовыми сдвигами читать тут:
 * 									https://metanit.com/cpp/tutorial/2.8.php
 * 								https://learnc.info/c/bitwise_operators.html
 * #########################################################################
 * 
 * 
 * ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}


static int	ft_size(char **tab, char *sep)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	size = 0;
	while (tab[i])
	{
		size += ft_strlen(tab[i]);
		i++;
	}
	j = 0;
	while(sep[j])
		j++;
	size += j * (i - 1);
	return (size);
}


char		*ft_join(char **tab, char *sep)
{
	int		i;
	int		s;
	int		k;
	int		size;
	char	*str;

	if (!tab || !*tab || !sep)
		return ((void *)0);
	i = 0;
	k = 0;
	s = 0;
	size = ft_size(tab, sep);
	if ((str = (char*)malloc(sizeof(char) * size + 1)) == ((void *)0))
		return ((void *)0);
	while ((s < size) && tab[i])
	{
		
		k = 0;
		while ((s < size) && tab[i][k])
			str[s++] = tab[i][k++];
		k = 0;
		while((s < size) && sep[k] && tab[i + 1])
			str[s++] = sep[k++];
		i++;
	}
	str[s] = '\0';
	return (str);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

void	ft_strcat(char *dest, char *src)
{
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;	
	*dest = '\0';
}

char	*ft_join(char **tab, char *sep)
{
	char	*str;
	int		i;
	int		y;
	int		x;

	i = 0;
	x = 1;
	if (!tab || !*tab || !sep)
		return ((void *)0);
	while (tab[i++])
	{
		y = 0;
		while (tab[i][y++])
			x++;
	}
	if (!(str = (char*)malloc(((i - 1) * ft_strlen(sep) + x) * sizeof(char))))
		return ((void *)0);
	i = 0;
	while (tab[i++])
	{
		ft_strcat(str, tab[i]);
		if (tab[i + 1])
			ft_strcat(str, sep);
	}
	return (str);
}