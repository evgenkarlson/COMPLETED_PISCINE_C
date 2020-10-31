/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 19:23:22 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */

#include "ft_ultimate_fight.h"

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