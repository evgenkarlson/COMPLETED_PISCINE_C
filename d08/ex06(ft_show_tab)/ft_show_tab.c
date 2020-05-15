/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int nb)
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

void	ft_show_tab(struct s_stock_par *par)
{
	int		i;

	i = 0;
	ft_putstr(par->copy);
	ft_putchar('\n');
	ft_putnbr(par->size_param);
	ft_putchar('\n');
	while (par->tab[i] != ((void *)0))
	{
		ft_putstr(par->tab[i++]);
		ft_putchar('\n');
	}
}





/* ************************************************************************** */
/* ***********************************_ИЛИ_********************************** */
/* ************************************************************************** */



#include "ft_stock_par.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int nb)
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

void	ft_show_tab(t_stock_par *par)
{
	int i;
	int y;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		ft_putnbr(par[i].size_param);
		ft_putchar('\n');
		y = 0;
		while (par[i].tab[y] != 0)
		{
			ft_putstr(par[i].tab[y]);
			if (par[i + 1].str != 0 || par[i].tab[y + 1] != 0)
				ft_putchar('\n');
			y++;
		}
		i++;
	}
}





/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


