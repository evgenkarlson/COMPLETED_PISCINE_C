/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/05/12 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */

#include <unistd.h>				/* Подключаем библиотеку содержащую функцию "write" */
#include <stdlib.h>				/* Подключаем библиотеку содержащую функцию "malloc" */

/* ************************************************************************** */
void		ft_putchar(char c)	/* Функция печати символа */
{
	write(1, &c, 1);
}
/* ************************************************************************** */
void		ft_putstr(char *str)/* Функция печати числа */
{
	while(*str)
		ft_putchar(*str++);
}
/* ************************************************************************** */
void		ft_putnbr(int nb)	/* Функция печати числа */
{
	int	temp;
	int	size;

	size = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb == -2147483648)
	{	
		ft_putchar('2');
		nb = 147483648;
	}
	temp = nb;
	while ((temp /= 10) > 0)
		size *= 10;
	temp = nb;
	while (size)
	{
		ft_putchar((char)((temp / size)) + 48);
		temp %= size;
		size /= 10;
	}
}
/* ************************************************************************** */



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
// first_line/+++/second_line/+++/third_line/+++/fourth_line
char		*ft_join(char **tab, char *sep)
{
	int		i;
	int		s;
	int		k;
	int		size;
	char	*str;

	i = 0;
	k = 0;
	s = 0;
	if (!tab || !*tab || !sep)
		return ((void *)0);
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


int 		main(void)
{
	char	*arr[5] = {"first_line","second_line","third_line","fourth_line"};
	char	*space = "/+++/";
	
	ft_putstr(ft_join(arr, space));
	
	ft_putchar('\n');
    return (0);					/* Возвращаем 0 и завершаем программу */
}