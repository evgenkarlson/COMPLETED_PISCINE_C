/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
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

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


void	ft_putchar(char c)			/* функция вывода символа */
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)		/* функция печати строки */
{
	while(*str)
	{
		ft_putchar(*str);
		str++;
	}
}


char	*ft_strncat(char *dest, char *src, int nb)
{
	int i;
	int lenght;

	i = 0;
	lenght = 0;
	while (dest[lenght])
		lenght++;
	while (i < nb && src[i])
	{
		dest[lenght] = src[i];
		lenght++;
		i++;
	}
	dest[lenght] = '\0';
	return (dest);
}



int 	main(void)
{
	char	r[] = {"muther_fucker_fucking_fuck\n"};
	char	t[20] = {"Hello "};

	ft_strncat(t, r, 12);
	ft_putstr(t);
	return 0;
}

