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
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while(*str)
		write(1, str++, 1);
}

char	rotate_maj(char c)
{
	c = c - 'A';
	c = ((c + 42) % 26);
	c = c + 'A';
	return (c);
}

char	rotate_min(char c)
{
	c = c - 'a';
	c = ((c + 42) % 26);
	c = c + 'a';
	return (c);
}

char	rotate(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (rotate_maj(c));
	else if (c >= 'a' && c <= 'z')
		return (rotate_min(c));
	else
		return (c);
}

char	*ft_rot42(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = rotate(str[i]);
		i++;
	}
	return (str);
}


int	main()
{					  /*  iurqijyud   mvutv  */
	char	tab[][10] = {"zzz","wfedf"};
	ft_putstr(ft_rot42(tab[0]));
	ft_putchar('\n');
	return 0;
}