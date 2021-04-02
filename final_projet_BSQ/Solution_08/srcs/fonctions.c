/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 13:19:53 by pcrosnie          #+#    #+#             */
/*   Updated: 2021/03/10 00:24:57 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_bsq.h"

void	ft_putchar(char c)
{
	write(2, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	else
		ft_putchar(nb + '0');
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
		i++;
	write(1, str, i);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

int		ft_atoi(char *str)
{
	int nb;
	int i;

	nb = 0;
	i = 0;
	while (*(str + i) <= 57 && *(str + i) >= 48)
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = src[i];
}

void	ft_put_result(char *str, int start)
{
	int		i;

	i = start;
	while (*(str + i))
		i++;
	write(1, &str[start], i - start);
}
