/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <jaleman@student.42.us.org>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 06:26:48 by exam              #+#    #+#             */
/*   Updated: 2017/03/27 06:26:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 

Assignment name  : options
Expected files   : *.c *.h
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes an undefined number of arguments which could be 
considered as options and writes on standard output a representation of those
options as groups of bytes followed by a newline.
Напишите программу, которая принимает неопределенное количество аргументов, 
которые могут рассматриваться как параметры, и записывает на стандартный вывод 
представление этих параметров в виде групп байтов, за которыми следует новая строка.

An option is an argument that begins by a '-' and have multiple characters 
which could be : abcdefghijklmnopqrstuvwxyz
Опция - это аргумент, который начинается с символа «-» и может содержать несколько 
символов: abcdefghijklmnopqrstuvwxyz

All options are stocked in a single int and each options represents a bit of that
int, and should be stocked like this : 
Все параметры хранятся в одном int, и каждый параметр представляет часть этого int 
и должен храниться следующим образом:

00000000 00000000 00000000 00000000
******zy xwvutsrq ponmlkji hgfedcba

Launch the program without arguments or with the '-h' flag activated must print
an usage on the standard output, as shown in the following examples.
Запуск программы без аргументов или с активированным флагом '-h' должен вывести 
использование в стандартном выводе, как показано в следующих примерах.

A wrong option must print "Invalid Option" followd by a newline.
Неправильная опция должна вывести «Invalid Option», за которой следует новая строка.

Examples :
$>./options
options: abcdefghijklmnopqrstuvwxyz
$>./options -abc -ijk
00000000 00000000 00000111 00000111
$>./options -z
00000010 00000000 00000000 00000000
$>./options -abc -hijk
options: abcdefghijklmnopqrstuvwxyz
$>./options -%
Invalid Option



   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */



#include <unistd.h>

int main(int ac, char **av)
{
	int i = 1;
	int  t[32] = {0}; 
	int j ;

	if(ac == 1)
	{
		write(1,"options: abcdefghijklmnopqrstuvwxyz\n",36);
		return 0;
	}
	i = 1;
	while (i < ac)
	{
		j = 1;
		if(av[i][0] == '-')
		{
			while(av[i][j] && av[i][j] >= 'a'  && av[i][j] <= 'z')
			{
				if(av[i][j] == 'h')
				{
					write(1,"options: abcdefghijklmnopqrstuvwxyz\n",36);
					return 0;
				}

				t['z' - av[i][j] + 6] = 1;
				j++;
			}

			if (av[i][j])
			{
				write(1,"Invalid Option\n",15);
				return 0;
			}
			j++;
		}
		i++;
	}
	i = 0;
		while (i < 32)
		{
		t[i] = '0' + t[i];
		write(1,&t[i++],1);
			if(i == 32)
				write(1,"\n",1);
			else if(i % 8 == 0)
				write(1," ",1);

		}

	return 0;
}