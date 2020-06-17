/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/05/12 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/* gcc -Wall -Werror -Wextra main.c ft_fight.c && chmod +x ./a.out && ./a.out */
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
	if (attacker->life <= 0 || defense->life <= 0)
		return ;
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

int		main(void)
{
	t_perso		donnie_matrix;			/* Создаем экземпляр структуры (персонаж "Donnie Matrix") */
	t_perso		frau_farbissina;		/* Создаем экземпляр структуры (персонаж "Frau Farbissina") */

	donnie_matrix = (t_perso) {.name = "Donnie Matrix", .life = 100.0};		/* Инициализируем структуру заполняя ее данными */
	frau_farbissina = (t_perso) {.name = "Frau Farbissina", .life = 100.0};	/* Инициализируем структуру заполняя ее данными */

	/* Далее вызываем функцию "ft_fight" столько раз сколько нам нужно и отправляем ей в аргументы экземпляры и макросы немного 
	 * изменяя их чтобы создать иллюзию схватки */

	ft_fight(&donnie_matrix, &frau_farbissina, KICK);
	ft_fight(&frau_farbissina, &donnie_matrix, PUNCH);
	ft_fight(&donnie_matrix, &frau_farbissina, KICK1);
	ft_fight(&frau_farbissina, &donnie_matrix, KICK2);
	ft_fight(&donnie_matrix, &frau_farbissina, KICK3);
	ft_fight(&frau_farbissina, &donnie_matrix, KICK4);
	ft_fight(&donnie_matrix, &frau_farbissina, KICK5);
	ft_fight(&frau_farbissina, &donnie_matrix, KICK6);
	ft_fight(&donnie_matrix, &frau_farbissina, KICK7);
	ft_fight(&frau_farbissina, &donnie_matrix, KICK8);
	ft_fight(&donnie_matrix, &frau_farbissina, KICK9);
	ft_fight(&frau_farbissina, &donnie_matrix, KICK10);
	ft_fight(&donnie_matrix, &frau_farbissina, KICK11);
	ft_fight(&donnie_matrix, &frau_farbissina, HEADBUTT);


    return (0);							/* Возвращаем ноль и завершаем функцию */
}