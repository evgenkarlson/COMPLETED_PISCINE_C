/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
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


char	*ft_strcapitalize(char *str)
{
	int		i;
	char	c;
	int		space;

	i = 0;
	while (str[i] != '\0')
	{
		space = 1;
		if (i == 0)
			c = ';';
		else
			c = str[i - 1];
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
			space = 0;
		if (c >= '0' && c <= '9')
			space = 0;
		if (space == 1 && str[i] >= 'a' && str[i] <= 122)
			str[i] = str[i] - 32;
		if (space == 0 && str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

int 	main(void)
{
	char	r[] = {"welcome to hogwarts\n"};
	char	*p;


	p = ft_strcapitalize(r);
    ft_putstr(p);

	return 0;
}

