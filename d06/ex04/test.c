/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/* gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out bde cg agw */
/* ************************************************************************** */


#include <unistd.h>

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int		ft_putchar(char c)
{
	write(1, &c, 1);

	return (0);
}

void	printarg(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		ft_putchar(str[n]);
		n++;
	}
	ft_putchar('\n');
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	swap(char **x, char **y)
{
	char *temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	sort(char *tab[], int size)
{
	int i;
	int j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				swap(&tab[j], &tab[j + 1]);
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	char	*arr[argc - 1];

	i = 1;
	while (i < argc)
	{
		arr[i - 1] = argv[i];
		i++;
	}
	sort(arr, argc - 1);
	i = 0;
	while (i < argc - 1)
	{
		printarg(arr[i]);
		i++;
	}
	return (0);
}