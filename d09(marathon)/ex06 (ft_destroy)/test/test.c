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


#include <unistd.h>
#include <stdlib.h>
#include "ft_ultimator.h"

void	ft_putstr(char *str)			/* функция печати символа */
{
	while(*str)
		write(1, str++, 1);
}

void	ft_destroy(char ***factory)
{
	int i;
	int j;

	i = 0;
	while (factory[i])
	{
		j = 0;
		while (factory[i][j] != ((void *)0))
		{
			free(factory[i][j]);
			j++;
		}
		free(factory[i]);
		i++;
	}
	free(factory);
}


int		main()							
{	
	char	***ptr;
	int i;
	int j;

	if ((ptr = (char ***)malloc(1)) == ((void *)0))
		return (0);
	i = 0;
	while (i < 1)
	{	
		if ((ptr[i] = (char **)malloc(3)) == ((void *)0))
			return (0);
		j = 0;
		while (j < 3)
		{
			ptr[i][j] = (char *)malloc(5);
			ptr[i][j][0] = (char)'h';
			ptr[i][j][1] = (char)'o';
			ptr[i][j][2] = (char)'l';
			ptr[i][j][3] = (char)'a';
			ptr[i][j][6] = (char)'\0';
			j++;
		}
		i++;
	}


	j = 0;
	while (j < 3)
	{	
		ft_putstr(ptr[0][j]);
		j++;
	}

	
	ft_destroy(ptr);
	return 0;
}