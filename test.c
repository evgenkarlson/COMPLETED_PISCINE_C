/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
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

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	z;
	int	to_find_size;

	i = 0;
	z = 0;
	to_find_size = 0;
	while (to_find[to_find_size])
		to_find_size++;
	if (to_find_size == 0)
		return (str);
	while (str[i])
	{
		while (to_find[z] == str[i + z])
		{
			if (z == to_find_size - 1)
				return (str + i);
			z++;
		}
		z = 0;
		i++;
	}
	return (0);
}


int 	main(void)
{
	char	r[] = {"Fuckin.Good.day.coming"};
	char	t[20] = {"Good"};
	char	*p;


	p = ft_strstr(r, t);

	ft_putstr(p);
	return 0;
}

