/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_fight.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** *
 * 
 *		Файлы для включения: ft_ultimate_fight.c, ft_ultimate_fight.h
 * 
 * 		Разрешенные функции: write
 * 
 * ************************************************************************** *
 * 
 * 
 *	  Возобновите симулятор из упражнения 15 и добавьте следующие движения:
 *
 *	  • KICK1; 13 очков; дзюдо чоп ичи
 * 
 *	  • KICK2; 3 очка; дзюдо чоп ни
 * 
 * 	  • KICK3 ; 18 points ;un judo chop san
 * 
 * 	  • KICK4; 9 очков; дзюдо чоп ши
 * 
 * 	  • KICK5; 11 очков; бой дзюдо
 * 
 * 	  • KICK6; 13 очков; дзюдо чоп року
 * 
 * 	  • KICK7; 8 очков; дзюдо чоп шичи
 * 
 * 	  • KICK8; 6 очков; дзюдо чоп хачи
 * 
 * 	  • KICK9; 11 очков; дзюдо чоп ку
 * 
 * 	  • KICK10; 9 очков; юн дзюдо чоп ю
 * 
 * 	  • KICK11; 18 очков; дзюдо чоп хяку
 * 	  
 * 	  • KICK12; 10 очков; бой дзюдо чоп сен
 *
 * 
 *  * ************************************************************************** *
 * 
 * 
 *	  "Хм ... Есть что-то умнее твоей основной идеи. Да да!"
 * 
 * 
 * ************************************************************************** *
 * ************************************************************************** *
 * ************************************************************************** */


#include "ft_ultimate_fight.h"
#include <unistd.h>

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