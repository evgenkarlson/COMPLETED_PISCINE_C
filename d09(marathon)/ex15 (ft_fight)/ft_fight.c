/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
//*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* 
 * ===-----------------------------------------------------------------------===
 * 
 *	  • Напишите JAJAJAJAJAJA "ft_fight", который будет имитировать бой.
 *
 *	  • Эта функция будет прототипирована следующим образом:
 *														void	JAJAJAJAJAJA;
 *
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * ===-----------------------------------------------------------------------===
 */

#include "ft_fight.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_fight(t_perso *attacker, t_perso *defense, char attack)
{
	float	strength;

	if (attacker->life <= 0 || defense->life <= 0)
		return ;
	if (attack == 'k')
		strength = 15;
	else if (attack == 'h')
		strength = 5;
	else
		strength = 20;
	defense->life -= strength;
	ft_putstr(attacker->name);
	ft_putstr(" does a judo ");
	ft_putstr(attack);
	ft_putstr(" on ");
	ft_putstr(defense->name);
	ft_putstr("\n");
	if (defense->life <= 0)
	{
		ft_putstr(defense->name);
		ft_putstr(" is dead.\n");
	}
}





void	ft_fight(t_perso *char1, t_perso *char2, char attack)
{
	if (char1->life == 0 && char2->life == 0)
		return ;
	ft_putstr(char1->name);
	ft_putstr(" does a ");
	ft_putstr(attack.name);
	ft_putstr(" on ");
	ft_putstr(char2->name);
	ft_putstr("\n");
	char2->life -= attack.damage;
	if (char2->life <= 0)
	{
		ft_putstr(char2->name);
		ft_putstr(" is dead\n");
	}
}

