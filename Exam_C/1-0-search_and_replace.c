/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <jaleman@student.42.us.org>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:40:32 by exam              #+#    #+#             */
/*   Updated: 2016/11/14 18:40:33 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


Assignment name  : search_and_replace
Expected files   : search_and_replace.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program called search_and_replace that takes 3 arguments, the first
arguments is a string in which to replace a letter (2nd argument) by
another one (3rd argument).
Напишите программу с именем search_and_replace, которая принимает 3 аргумента.
Первый аргумент - это строка, в которой нужно заменить букву которая будет 2-м 
аргументом на букву которая будет в 3-м аргументе.

If the number of arguments is not 3, just display a newline.
Если количество аргументов не равно 3, просто отобразите новую строку.

If the second argument is not contained in the first one (the string)
then the program simply rewrites the string followed by a newline.
Если второй аргумент не содержится в первом (строке), тогда программа
просто переписывает строку, за которой следует новая строка.

Examples:
Примеры:

$>./search_and_replace "Papache est un sabre" "a" "o"
Popoche est un sobre
$>./search_and_replace "zaz" "art" "zul" | cat -e
$
$>./search_and_replace "zaz" "r" "u" | cat -e
zaz$
$>./search_and_replace "jacob" "a" "b" "c" "e" | cat -e
$
$>./search_and_replace "ZoZ eT Dovid oiME le METol." "o" "a" | cat -e
ZaZ eT David aiME le METal.$
$>./search_and_replace "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e" | cat -e
eNcOre Un ExEmPle Pas Facile a Ecrire $


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>

int		main(int argc, char *argv[])			/* здесь принимаем количество строк в массиве и сам массив со строками */
{
	int		i;									/* для начала обьявим переменную для счетчика */

	if (argc == 4)								/* Проверяем есть ли там кроме имени программы в аргументах еще нужные нам аргументы */
	{
		if (!argv[2][1] && !argv[3][1])			/* Проверяем содержат ли третий и четвертый аргумент только по одной букве согласно условию */
		{
			while (argv[1][i])					/* Запускаем цикл. который пройдется по строке печатая её символы пока не дойдет до конца */
			{
				if (argv[1][i] == argv[2][0])	/* Если перед нами символ который мы хоти заменить */
					write(1, &argv[3][0], 1);	/* то печатаем его замену */
				else							/* если это просто символ */
					write(1, &argv[1][i], 1);	/* по просто печатаем его */
				i++;							/* Увеличиваем счетчик и переходим к след ячейке массива */
			}
		}
	}
	write(1, "\n", 1);							/* Печатаем символ перехода на новую строку */
	return (0);									/* Завершаем программу */
}
