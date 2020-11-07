/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/10 21:26:54 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **
**  
**  
**  - Здесь мы имеем дело с программой, поэтому в вашем файле '.c' должна быть 
**  функция 'main'.
**
**  - Создайте программу, которая отображает заданные аргументы, отсортированные
**  по порядку ascii.
**
**  - Она должна отображать все аргументы, кроме эargv[0]'.
**
**  - Один аргумент на строку.
**
**
** ************************************************************************** **
**
**  Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую
**
** ************************************************************************** */
/* ************************************************************************** */


#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	ft_print_arr(char **arr)
{
	while (*arr)
	{
		ft_putstr(*arr++);
		ft_putchar('\n');
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_swap(char **x, char **y)
{
	char *temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	ft_sort_ascii(char *tab[], int size)
{
	char temp;
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int		i;

	if (argc > 1)
	{
		ft_sort_ascii(argv + 1, argc - 1);
		ft_print_arr(argv + 1);
	}
	return (0);
}

/* ************************************************************************** */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	ft_print_arr(char **arr)
{
	while (*arr)
	{
		ft_putstr(*arr++);
		ft_putchar('\n');
	}
}

void	ft_sort_ascii(char **val, int nb)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < (nb - 1))
	{
		j = 0;
		while (val[i][j] == val[i + 1][j])
			j++;
		if (val[i][j] > val[i + 1][j])
		{
			tmp = val[i];
			val[i] = val[i + 1];
			val[i + 1] = tmp;
			i = 0;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_sort_ascii(argv, argc);
		ft_print_arr(argv + 1);
	}
	return (0);
}

/* ************************************************************************** */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	ft_print_arr(char **arr)
{
	while (*arr)
	{
		ft_putstr(*arr++);
		ft_putchar('\n');
	}
}

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1 += 1;
		s2 += 1;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int			main(int argc, char *argv[])
{
	int		find;
	int		i;
	char	*tmp;

	find = 1;
	while (find)
	{
		find = 0;
		i = 0;
		while (++i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				tmp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = tmp;
				find = 1;
			}
		}
	}
	ft_print_arr(argv + 1);
	return (0);
}

/* ************************************************************************** */
/* ************************************************************************** */