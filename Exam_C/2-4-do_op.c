/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <evgenkarlson@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by exam              #+#    #+#             */
/*   Created: 2020/02/14 12:33:14 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 


Assignment name  : do_op
Expected files   : *.c, *.h
Allowed functions: atoi, printf, write
--------------------------------------------------------------------------------

Write a program that takes three strings:
Напишите программу, которая принимает три строки:

- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- Первый и третий являются представлениями целых чисел со знаком base-10, которые помещаются в int.

- The second one is an arithmetic operator chosen from: + - * / %
- Второй - арифметический оператор, выбранный из: + - * /%


The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.
Программа должна отображать результат запрошенной арифметической операции,
за которым следует новая строка. Если количество параметров не равно 3,
программа просто отображает новую строку.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.
Вы можете предположить, что строка не содержит ошибок или посторонних символов.
Отрицательные числа на входе или выходе будут иметь один и только один ведущий '-'.
Результат операции вписывается в int.

Examples:
Примеры:


$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char *argv[])
{
	if (argc == 4)
	{
		if (argv[2][0] == '+')
			printf("%d", (atoi(argv[1]) + atoi(argv[3])));
		if (argv[2][0] == '-')
			printf("%d", (atoi(argv[1]) - atoi(argv[3])));
		if (argv[2][0] == '*')
			printf("%d", (atoi(argv[1]) * atoi(argv[3])));
		if (argv[2][0] == '/')
			printf("%d", (atoi(argv[1]) / atoi(argv[3])));
		if (argv[2][0] == '%')
			printf("%d", (atoi(argv[1]) % atoi(argv[3])));
	}
	printf("\n");
	return (0);
}
