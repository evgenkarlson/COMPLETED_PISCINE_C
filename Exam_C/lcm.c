/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 20:28:09 by jaleman           #+#    #+#             */
/*   Updated: 2017/04/15 20:28:09 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function who takes two unsigned int as parameters and returns the 
computed LCM of those parameters.
Напишите функцию, которая принимает два unsigned int в качестве параметров и возвращает вычисленный LCM этих параметров.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.
LCM (наименьшее общее кратное) из двух ненулевых целых чисел является наименьшим положительным целым числом, делимым на оба целых числа.

A LCM can be calculated in two ways:
LCM можно рассчитать двумя способами:

- You can calculate every multiples of each integers until you have a common
multiple other than 0
- Вы можете вычислять все кратные каждого целого числа, пока у вас не будет общего кратного, кроме 0

- You can use the HCF (Highest Common Factor) of these two integers and 
calculate as follows:
- Вы можете использовать HCF (наивысший общий коэффициент) этих двух целых чисел и рассчитать следующим образом:


	LCM(x, y) = | x * y | / HCF(x, y)


  | x * y | means "Absolute value of the product of x by y"
  | х * у | означает «Абсолютное значение произведения х на у»

If at least one integer is null, LCM is equal to 0.
Если хотя бы одно целое число равно нулю, LCM равно 0.

Your function must be prototyped as follows:
Ваша функция должна быть прототипирована следующим образом:

  unsigned int    lcm(unsigned int a, unsigned int b);


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


unsigned int	lcm(unsigned int a, unsigned int b)
{
	int		gcd;
	int		old_a;
	int		old_b;

	gcd = 0;
	old_a = a;
	old_b = b;
	while (1)
	{
		if (a == 0)
			break ;
		b %= a;
		if (b == 0)
			break ;
		a %= b;
	}
	gcd = (!b) ? a : b;
	return (gcd ? (old_a / gcd * old_b) : 0);
}
