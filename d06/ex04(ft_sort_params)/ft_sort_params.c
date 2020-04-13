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


/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************

• Здесь мы имеем дело с программой, поэтому в вашем файле .c должна быть функция main.
• Создать программу, которая отображает заданные аргументы, отсортированные по порядку ascii.
• Должны отображаться все аргументы, кроме argv [0].
• Все аргументы должны иметь свою собственную строку.

   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] < s2[i])
			return (-1);
		if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}

char    *ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	dest[i + 1] = '\0';
	return (dest);
}

int	main(int argc, char **argv)
{
	int		i;
	char	temp[10000] = {0};

	i = 1;
	while (i < argc - 1)
	{
		if (ft_strcmp(argv[i], argv[i + i]) > 0)
		{
			ft_strcpy(temp, argv[i + 1]);
			ft_strcpy(argv[i + 1], argv[i]);
			ft_strcpy(argv[i], temp);
			i = 1;
		}
		else
			i++;
	}

	return (0);
}



/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */

void	ft_printstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
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

void	ft_swap(char **x, char **y)
{
	char *temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	ft_sort(char *tab[], int size)
{
	char temp;
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
				ft_swap(&tab[j], &tab[j + 1]);
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
	ft_sort(arr, argc - 1);
	i = 0;
	while (i < argc - 1)
	{
		ft_printstr(arr[i]);
		i++;
	}
	return (0);
}




/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */

void	ft_sort_ascii(char **val, int nb)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
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

void	ft_print(char **val, int nb)
{
	int i;
	int y;

	if (nb > 1)
	{
		i = 1;
		while (i < nb)
		{
			y = 0;
			while (val[i][y] != '\0')
			{
				ft_putchar(val[i][y]);
				y++;
			}
			ft_putchar('\n');
			i++;
		}
	}
}

int		main(int argc, char **argv)
{
	ft_sort_ascii(argv, argc);
	ft_print(argv, argc);
	return (0);
}



/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */

static void	ft_putendl(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	ft_putchar('\n');
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
	i = 0;
	while (++i < argc)
		ft_putendl(argv[i]);
	return (0);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

