/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

static char			*ft_strdup(char *src)
{
	int				i;
	char			*dst;

	i = 0;
	while (src[i])
		i += 1;
	if (!(dst = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int				i;
	int				j;
	t_stock_par		*stk;

	if (!(stk = (t_stock_par*)malloc(sizeof(t_stock_par) * (ac + 1))))
		return (NULL);
	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
			j++;
		stk[i]->size_param = j;
		stk[i]->str = av[i];
		stk[i]->copy = ft_strdup(av[i]);
		stk[i]->tab = ft_split_whitespaces(av[i]);
		i++;
	}
	stk[i]->str = 0;
	return (stk);
}


/* ************************************************************************** */
/* ***********************************_ИЛИ_********************************** */
/* ************************************************************************** */


#include "ft_stock_par.h"

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int			i;
	int			y;
	t_stock_par *ret;

	i = 0;
	ret = (t_stock_par *)malloc(sizeof(t_stock_par) * (ac + 1));
	while (i < ac)
	{
		ret[i].size_param = ft_strlen(av[i]);
		ret[i].str = av[i];
		ret[i].copy = (char *)malloc(sizeof(char) * (ret[i].size_param + 1));
		y = 0;
		while (y < ret[i].size_param)
		{
			ret[i].copy[y] = av[i][y];
			y++;
		}
		ret[i].copy[y] = '\0';
		ret[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	ret[i].str = 0;
	return (ret);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	struct s_stock_par *a;
	a = ft_param_to_tab(argc, argv);
	ft_show_tab(a);
	return (0);
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
