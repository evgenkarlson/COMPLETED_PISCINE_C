/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 20:07:07 by exam              #+#    #+#             */
/*   Updated: 2017/07/21 20:57:22 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 


Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <stdlib.h>
#define ABS(nbr) ( nbr > 0 ? nbr : -nbr )
int		calcdigs(unsigned int nbr)
{
	int i = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	char *str;
	if (nbr == 0)
		return ("0");

	unsigned int nb;
	int o  = 0;
	if (nbr < 0)
		o = 1;
	
	if (nbr == -2147483648)
		nb = 2147483648;
	else
		nb = ABS(nbr);
	str = (char*)malloc(sizeof(char) * calcdigs(nb) + 1 + o);
	
	if (o)
		str[0] = '-';
	int i = calcdigs(nb) - 1;
	str[i + o] = '\0';
	while (i >= 0)
	{
		str[i + o] = ABS(nb % 10) + 48;
		nb /= 10;
		i--;
	}
	return (str);
}




/* ************************************************************************** */
/* ********************************_OR_THAT_:)******************************* */
/* ************************************************************************** */



#include <stdlib.h>

char    *ft_itoa(int nbr)
{
	int		len;
	long	n;
	char	*str;

	if (nbr == -2147483648)
		return ("-2147483648");
	len = 0;
	n_tmp = nbr;
	while (n_tmp)
	{
		n_tmp /= 10
		len += 1;
	}
	if (nbr < 0)
	{
		len += 1;
		nbr *= -1;
	}
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] ='\0';
	while (nbr)
	{
		str[len] = (n % 10) + '0';
		nbr /= 10;
	}
	return (str);
}