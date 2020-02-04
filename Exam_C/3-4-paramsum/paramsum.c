/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 18:50:50 by exam              #+#    #+#             */
/*   Updated: 2017/07/21 18:56:31 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 


Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline.

Example:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	char **thxgcc;

	thxgcc = argv;
	if (argc == 1) 
		ft_putchar(48);
	else
		ft_putchar(argc - 1 + 48);
	ft_putchar('\n');
	return (0);
}



/* ************************************************************************** */
/* ********************************_OR_THAT_:)******************************* */
/* ************************************************************************** */



#include <unistd.h>

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	else if (nbr < 10)
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

int		main(int argc, const char *argv[])
{
	ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}
