/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-1____lcm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/01/19 11:48:31 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** **


Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Напишите функцию, которая принимает два unsigned int в качестве параметров и 
возвращает вычисленное НОК(наименьшее общее кратное) этих параметров.

НОК(наименьшее общее кратное) из двух ненулевых целых чисел является наименьшим 
положительным целым числом, делимым на оба целых числа.

НОК можно рассчитать двумя способами:

- Вы можете вычислять все кратные каждого целого числа, пока у вас не будет 
общего кратного, кроме 0

- Вы можете использовать HCF (наивысший общий коэффициент) этих двух целых 
чисел и рассчитать следующим образом:


	LCM(x, y) = | x * y | / HCF(x, y)


| х * у | означает «Абсолютное значение произведения х на у».

Если хотя бы одно целое число равно нулю, LCM равно 0.


Ваша функция должна быть прототипирована следующим образом:

  unsigned int    lcm(unsigned int a, unsigned int b);


** ************************************************************************** **
** ************************************************************************** **

В этом заданиии нас просят написать программу находящую наименьшее общее кратное
двух чисел:

https://zen.yandex.ru/media/haknem_shkola/poleznye-sovety-o-tom-kak-legko-sokratit-slojnye-drobi-i-privesti-ih-k-naimenshemu-obscemu-znamenateliu-5f9d76db1f9f73799244c6b6

https://www.google.com/search?client=ubuntu&hs=BEU&ei=eIgGYIXUI6KsrgS5kreYAw&q=lcm&oq=lcm&gs_lcp=CgZwc3ktYWIQAzIECAAQQzIECAAQQzIECAAQQzICCAAyAggAMgIIADICCAAyBAgAEEMyAggAMggIABDHARCvAToECAAQRzoLCAAQsQMQxwEQowI6AgguOgUILhCxAzoICAAQxwEQowI6BwgAELEDEAo6BAgAEApQy7gCWJfAAmDuxwJoAHADeACAAVWIAfoBkgEBM5gBAKABAaoBB2d3cy13aXrIAQjAAQE&sclient=psy-ab&ved=0ahUKEwiF8If_uqfuAhUilosKHTnJDTMQ4dUDCA0&uact=5


** ************************************************************************** */
/* ************************************************************************** */


unsigned int	ft_pgcd(int nbr1, int nbr2)
{
	if ((nbr1 > 0 && nbr2 > 0))
	{
		while (nbr1 != nbr2)
		{
			if (nbr1 > nbr2)
				nbr1 -= nbr2;
			else
				nbr2 -= nbr1;
		}
	}
	return (nbr1);
}


unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int		gcd;

	gcd = ft_pgcd(a, b);
	return (gcd ? ((a / gcd) * b) : 0);
}


/* ************************************************************************** */
/* ************************************************************************** */


unsigned int	lcm(unsigned int a, unsigned int b)
{
	int		gcd;
	int		tmp_a;
	int		tmp_b;

	gcd = 0;
	tmp_a = a;
	tmp_b = b;
	while (1)
	{
		if (a == 0)
			break;
		b %= a;
		if (b == 0)
			break;
		a %= b;
	}
	gcd = (!b) ? a : b;
	return (gcd ? ((tmp_a / gcd) * tmp_b) : 0);
}
