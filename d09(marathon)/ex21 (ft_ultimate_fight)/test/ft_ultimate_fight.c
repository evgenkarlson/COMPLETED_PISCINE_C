/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_fight.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 19:22:27 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */


#include "ft_ultimate_fight.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_fight(t_perso *attacker, t_perso *defense, int n)
{
	const char	*attack[14] = { "punch", "kick", "chop ichi", "chop ni",
		"chop san", "chop shi", "chop go", "chop roku", "chop shichi",
		"chop hachi", "chop ku", "chop ju", "chop hyaku", "headbutt" };
	const int	points[14] = {15, 5, 13, 3, 18, 9, 11, 13, 8, 6, 11, 9, 18, 20};

	if (n > 14)
		n %= 14;
	if (attacker->life > 0 || defense->life > 0)
	{
		defense->life -= points[n];
		ft_putstr(attacker->name);
		ft_putstr(" does a judo ");
		ft_putstr((char *)attack[n]);
		ft_putstr(" on ");
		ft_putstr(defense->name);
		ft_putstr("\n");
		if (defense->life <= 0)
		{
			ft_putstr(defense->name);
			ft_putstr(" is dead.\n");
		}
	}
}