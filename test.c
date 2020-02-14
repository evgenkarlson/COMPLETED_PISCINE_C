/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
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


int		ft_putchar(char c)
{
	write(1, &c, 1);

	return (0);
}

void	ft_putstr(char *str)		
{
	int	i;						

	i = 0;						
	while (str[i] != '\0')		
	{
		ft_putchar(str[i]);		
		i++;					
	}
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		if (i < size - 1)
			dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}




int 	main(void)
{
	char	r[] = {"muther_fucker_fucking_fuck\n"};
	char	t[20] = {"Hello "};

	ft_strlcpy(t, r, 20);
	ft_putstr(t);
	return 0;
}

