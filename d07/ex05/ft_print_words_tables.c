/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

/* ************************************************************************** */

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_print_words_tables(char **tab)
{
	while (*tab != ((void *)0))
	{
		ft_putstr(*tab);
		ft_putchar('\n');
		tab++;
	}
}

/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */

void	ft_putchar(char c);

/* ************************************************************************** */

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_print_words_tables(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != ((void *)0))
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */

void	ft_putchar(char c);

/* ************************************************************************** */

void	ft_print_words_tables(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i] != ((void *)0))
	{
		j = 0;
		while (tab[i][j])
			ft_putchar(tab[i][j++]);
		ft_putchar('\n');
		i++;
	}
}

/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */

void	ft_putchar(char c);

/* ************************************************************************** */

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_print_words_tables(char **tab)
{
	int	i;
	int l;

	i = 0;
	l = 0;
	while (tab[l] != ((void *)0))
		l++;
	while (i < l)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

