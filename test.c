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
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */


/* ************************************************************************** */
void		ft_putchar(char c)	/* Функция печати символа */
{
	write(1, &c, 1);
}
/* ************************************************************************** */
void		ft_putstr(char *str)/* Функция печати строки */
{
	while(*str)
		ft_putchar(*str++);
}
/* ************************************************************************** */
void		ft_putnbr(int nb)	/* Функция печати числа */
{
	int	temp;
	int	size;

	size = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb == -2147483648)
	{	
		ft_putchar('2');
		nb = 147483648;
	}
	temp = nb;
	while ((temp /= 10) > 0)
		size *= 10;
	temp = nb;
	while (size)
	{
		ft_putchar((char)((temp / size)) + 48);
		temp %= size;
		size /= 10;
	}
}
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
// #include "ft_ultimate_fight.h"
#ifndef FT_ULTIMATE_FIGHT_H
# define FT_ULTIMATE_FIGHT_H
# define PUNCH 0
# define KICK 1
# define KICK1 2
# define KICK2 3
# define KICK3 4
# define KICK4 5
# define KICK5 6
# define KICK6 7
# define KICK7 8
# define KICK8 9
# define KICK9 10
# define KICK10 11
# define KICK11 12
# define HEADBUTT 13
//  # include "ft_perso.h"
	#ifndef __FT_PERSO_H
	# define __FT_PERSO_H
	# include <unistd.h>

	typedef struct	s_perso {
		char	*name;
		float	life;
		int		age;
		char	*profession;
	}				t_perso;

	void	ft_putchar(char c);
	void	ft_putstr(char *str);

	#endif




void	ft_fight(t_perso *attacker, t_perso *defense, int n);

#endif


void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
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
	ft_putstr(getattac(n));/*  */
	ft_putstr(" on ");
	ft_putstr(defense->name);
	ft_putstr("\n");
	if (defense->life <= 0)
	{
		ft_putstr(defense->name);
		ft_putstr(" is dead.\n");
	}
}

int 		main(void)
{	int arr[] = {1, 1, 2, 4, 3, 4, 2, 3, 4};/* Создадим массив символов с одним числом, у которого нет пары */
	
	ft_putnbr(ft_unmatch(arr, 9));	/* Отправим этот массив и его длинну в функцию 'ft_unmatch' для поиска элемента,
									 * у которого нет пары. И распечатаем результат, который вернет функция 'ft_unmatch' */
	ft_putchar('\n');
    return (0);						/* Возвращаем 0 и завершаем программу */
}