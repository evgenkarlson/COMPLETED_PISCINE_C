/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 11:59:52 by lkinzel           #+#    #+#             */
/*   Updated: 2017/07/14 16:31:53 by lkinzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ultimate_fight.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*getattac(int n)
{
	const char *a[14] = { "punch", "kick", "chop ichi", "chop ni",
		"chop san", "chop shi", "chop go", "chop roku", "chop shichi",
		"chop hachi", "chop ku", "chop ju", "chop hyaku", "headbutt" };

	return (a[n]);
}

int		getpoints(int n)
{
	const int a[14] = {15, 5, 13, 3, 18, 9, 11, 13, 8, 6, 11, 9, 18, 20};

	return (a[n]);
}

void	ft_fight(t_perso *attacker, t_perso *defense, int n)
{
	int		points;

	points = getpoints(n);
	if (attacker->life <= 0 || defense->life <= 0)
		return ;
	defense->life -= points;
	ft_putstr(attacker->name);
	ft_putstr(" does a judo ");
	ft_putstr(getattac(n));
	ft_putstr(" on ");
	ft_putstr(defense->name);
	ft_putstr("\n");
	if (defense->life <= 0)
	{
		ft_putstr(defense->name);
		ft_putstr(" is dead.\n");
	}
}
