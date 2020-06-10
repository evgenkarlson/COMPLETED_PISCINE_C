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
/*  gcc -Wall -Werror -Wextra main.fr.c ft_fight.c && chmod +x ./a.out && ./a.out  */
/* ************************************************************************** */

#include "ft_perso.h"					/* Подключаем библиотеку содержащую структуру "t_perso" */
#include "ft_fight.h"					/* Подключаем библиотеку содержащую макросы */


int main(void)
{
	t_perso		donnie_matrix;			/* Создаем экземпляр структуры (персонаж "Donnie Matrix") */
	t_perso		frau_farbissina;		/* Создаем экземпляр структуры (персонаж "Frau Farbissina") */

	donnie_matrix = (t_perso) {.name = "Donnie Matrix", .life = 100.0};		/* Инициализируем структуру заполняя ее данными */
	frau_farbissina = (t_perso) {.name = "Frau Farbissina", .life = 20.0};	/* Инициализируем структуру заполняя ее данными */

	ft_fight(&donnie_matrix, &frau_farbissina, KICK);		/* Вызываем функцию "ft_fight" и отправляем ей в аргументы эти экземпляры и макрос */
	ft_fight(&frau_farbissina, &donnie_matrix, PUNCH);		/* Вызываем функцию "ft_fight" и отправляем ей в аргументы эти экземпляры и макрос */
	ft_fight(&donnie_matrix, &frau_farbissina, HEADBUTT);	/* Вызываем функцию "ft_fight" и отправляем ей в аргументы эти экземпляры и макрос */
    return (0);							/* Возвращаем ноль и завершаем функцию */
}