/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <RTFM@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** **

Assignment name  : options
Expected files   : *.c *.h
Allowed functions: write
--------------------------------------------------------------------------------

Напишите программу, которая принимает неопределенное количество аргументов, 
которые могут рассматриваться как параметры, и записывает на стандартный вывод 
представление этих параметров в виде групп байтов, за которыми следует новая 
строка.

Опция - это аргумент, который начинается с символа «-» и может содержать 
несколько символов: abcdefghijklmnopqrstuvwxyz

Все параметры хранятся в одном 'int', и каждый параметр представляет часть 
этого 'int' и должен храниться следующим образом:



00000000 00000000 00000000 00000000
******zy xwvutsrq ponmlkji hgfedcba



Запуск программы без аргументов или с активированным флагом '-h' должен вывести 
использование в стандартном выводе, как показано в следующих примерах.

Неправильная опция должна вывести «Invalid Option», за которой следует новая 
строка.

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



** ************************************************************************** */
/* ************************************************************************** */



#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(*(str + i))
		i++;
	write(1, str, i);
}

void	ft_options(int ac, char **av)
{
	int	temp_alph[32] = {0};
	int i;
	int j;

	i = 0;
	while (i < ac && (av[i][0] == '-'))
	{
		j = 1;
		while(av[i][j])
		{
			if (av[i][j] == 'h')
			{
				ft_putstr("options: abcdefghijklmnopqrstuvwxyz\n");
				return ;
			}
			else if (av[i][j] && ((av[i][j] < 'a') || (av[i][j] > 'z')))
			{
				ft_putstr("Invalid Option\n");
				return ;
			}
			else if ((av[i][j] >= 'a') && (av[i][j] <= 'z'))
				temp_alph[('z' - av[i][j]) + (32 - 26)] = 1;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 32)
	{
		ft_putchar(temp_alph[i++] + '0');
		if ((i % 8) == 0)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}


int 	main(int ac, char **argv)
{
	if(ac == 1)
		ft_putstr("options: abcdefghijklmnopqrstuvwxyz\n");
	else
		ft_options(ac - 1, (argv + 1));
	return 0;
}


/* ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(*(str + i))
		i++;
	write(1, str, i);
}

int		ft_options(int ac, char **av)
{
	int  temp_alph[32] = {0};
	int i;
	int j ;


	i = 0;
	while (i < ac)
	{
		j = 1;
		if(av[i][0] == '-')
		{
			while(av[i][j] && (av[i][j] >= 'a') && (av[i][j] <= 'z'))
			{
				if(av[i][j] == 'h')
				{
					ft_putstr("options: abcdefghijklmnopqrstuvwxyz\n");
					return (1);
				}
				temp_alph['z' - av[i][j] + 6] = 1;
				j++;
			}
			if (av[i][j] && (av[i][j] <= 'a') && (av[i][j] >= 'z'))
			{
				ft_putstr("Invalid Option\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 32)
	{
		ft_putchar(temp_alph[i] + 0);
		i++;
		if(i == 32)
			ft_putchar('\n');
		else if((i % 8) == 0)
			ft_putchar(' ');
	}
	return (0);
}

int 	main(int ac, char **argv)
{
	if(ac == 1)
		ft_putstr("options: abcdefghijklmnopqrstuvwxyz\n");
	else
		ft_options(ac - 1, (argv + 1));
	return (0);
}