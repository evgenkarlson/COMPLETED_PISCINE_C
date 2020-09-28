/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 19:25:53 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */


#include <unistd.h>

void	ft_putchar(char c)		/* функция печати символа */
{
	write(1, &c, 1);
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

/* Функция будет обменивать точки, на которые указывают указатели, полученые в параметрах.
**	• Эта функция поместит: 	 'a' в 'c';		'c' в 'd';		'd' в 'b';	 и 'b' поместит в 'a' */
void	ft_scrambler(int ***a, int *b, int *******c, int ****d)
{
	int tmp;

	tmp = *******c;		/* backup c  */
	*******c = ***a;	/* 'a' в 'c' */
	***a = *b;			/* 'b' в 'a' */
	*b = ****d;			/* 'd' в 'b' */
	****d = tmp;		/* 'c' в 'd' */
}


/* Для того чтобы протестировать функцию "ft_scrambler" мы создадим целую кучу указателей и поместим 
в них адреса переменных которые хранят числа, а после запуска функции "ft_scrambler" распечатаем содержимое 
переменных и посмотрим как функция "ft_scrambler" поменяла местами содержимое переменных */
int		main()							
{	int	num[] = {1, 2, 3, 4};
	int	***a;
	int	**aa;
	int	*aaa;
	int	*b;
	int	*******c;
	int	******cc;
	int	*****ccc;
	int	****cccc;
	int	***ccccc;
	int	**cccccc;
	int	*ccccccc;
	int	****d;
	int	***dd;
	int	**ddd;
	int	*dddd;

	aaa = &num[0];
	aa = &aaa;
	a = &aa;
	b = &num[1];
	ccccccc = &num[2];
	cccccc = &ccccccc;
	ccccc = &cccccc;
	cccc = &ccccc;
	ccc = &cccc;
	cc = &ccc;
	c = &cc;
	dddd = &num[3];
	ddd = &dddd;
	dd = &ddd;
	d = &dd;
	
	ft_scrambler(a, b, c, d);

	ft_putnbr(num[0]);
	ft_putchar(' ');
	ft_putnbr(num[1]);
	ft_putchar(' ');
	ft_putnbr(num[2]);
	ft_putchar(' ');
	ft_putnbr(num[3]);
	ft_putchar('\n');
	return (0);
}