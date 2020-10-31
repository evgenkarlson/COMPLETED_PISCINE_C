/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 19:24:49 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */

#include "ft_perso.h"					/* Подключаем библиотеку содержащую структуру "t_perso" */
#include "ft_fight.h"					/* Подключаем библиотеку содержащую макросы */

/* ************************************************************************** */
void	ft_putchar(char c)				/* Функция печати символа */
{
	write(1, &c, 1);
}
/* ************************************************************************** */
void	ft_putstr(char *str)			/* Функция печати строки */
{
	while(*str)
		ft_putchar(*str++);
}
/* ************************************************************************** */
void	ft_fight(t_perso *attacker, t_perso *defense, char attack)	/* функция меняет содержимое переменной "life" у
										 * экземпляра структуры "defense" в зависимоти от значения переменной "attack" */
{
	float	strength;

	if (attacker->life > 0 || defense->life > 0)
	{
		if (attack == 'k')
			strength = 15;
		else if (attack == 'h')
			strength = 5;
		else
			strength = 20;
		defense->life -= strength;
		ft_putstr(attacker->name);
		ft_putstr(" does a judo ");
		if (attack == 'k')
			ft_putstr("KICK");
		else if (attack == 'h')
			ft_putstr("HEADBUTT");
		else
		ft_putstr("PUNCH");
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