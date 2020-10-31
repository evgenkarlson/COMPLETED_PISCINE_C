/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 19:25:38 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */


#include <unistd.h>
#include "ft_perso.h"

void	ft_putchar(char c)		/* функция печати символа */
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)	/* функция печати строки */
{
	while(*str)
		ft_putchar(*str++);
}

void	ft_putnbr(int nb)		/* Функция печати числа */
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

int		main()	
{
	t_perso		donnie;					/* Создадим экземпляр и поместим туда данные, а потом напечатаем чтобы проверить все ли работает */
	donnie.name = strdup("Donnie");
	donnie.life = 100.0;
	donnie.age = 24;
	donnie.profession = SAVE_AUSTIN_POWERS;
	(void)donnie;						/* Эта строчка была взята из задания. В ней мы пытаемся получить всю структуру данных и привезти ее к типу void */
							
	ft_putstr(donnie.name);
	ft_putchar('\n');
	ft_putnbr(donnie.age);
	ft_putchar('\n');
	ft_putstr(donnie.profession);
	ft_putchar('\n');
	
	return (0);
}



/*										ДРУГОЙ КОД ДЛЯ ТЕСТА структуры из заголовочного файла ft_perso.h 
										Если стало понятно почему там точки, а тут стрелочки то ты молодец.
void	ft_test(t_perso *user)
{
	(*user).name = strdup("user");
	user[0].age = 32;
	user->life = 120.0;
	user->profession = SAVE_AUSTIN_POWERS;
	(void)user->age;
}

int		main()
{
	t_perso		donnie;			
	ft_test((void *)&donnie);

	ft_putstr(donnie.name);
	ft_putchar('\n');
	ft_putnbr(donnie.age);
	ft_putchar('\n');
	ft_putstr(donnie.profession);
	ft_putchar('\n');

	return (0);
}
*/