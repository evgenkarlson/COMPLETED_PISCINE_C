/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
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

	Файлы для включения: ft_show_tab.c, ft_stock_par.h
	Разрешенные функции: ft_split_whitespaces, ft_show_tab, malloc

   **************************************************************************   

	• Создать функцию, которая хранит аргументы программы в структуре массива 
	и возвращает адрес первого блока этого массива.

	• Все элементы массива должны быть обработаны, включая av [0].

	• Вот как это должно быть прототипировано:

					   struct s_stock_par *ft_param_to_tab(int ac, char **av);

	• Массив структуры должен быть размещен в своем элементе str и его последний 
	блок должен содержать 0, чтобы указать на конец массива.

	• Структура определяется в файле ft_stock_par.h, как тут:

													typedef struct	s_stock_par
													{
														int size_param;
														char *str;
														char *copy;
														char **tab;
													}				t_stock_par;

	◦ size_param - длина аргумента;
	◦ str - адрес аргумента;
	◦ copy является копией аргумента;
	◦ tab - массив, возвращаемый ft_split_whitespaces.


	• Мы протестируем вашу функцию с помощью наших ft_split_whitespaces и нашего 
	ft_show_tab (следующее упражнение). Примите соответствующие меры, чтобы это работало!


   ************************************************************************** */
/* *******************************_V_1.0_************************************ */
/* ************************************************************************** */


#include "ft_stock_par.h"

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int			i;
	int			j;
	t_stock_par	*ret;

	if ((ret = (t_stock_par *)malloc(sizeof(t_stock_par) * (ac + 1))) == ((void *)0))
		return ((void *)0);
	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
			j++;
		ret[i].size_param = j;
		ret[i].str = av[i];
		if((ret[i].copy = (char *)malloc(sizeof(char) * (ret[i].size_param + 1))) == ((void *)0))
			return ((void *)0);
		j = 0;
		while (j < ret[i].size_param)
		{
			ret[i].copy[j] = av[i][j];
			j++;
		}
		ret[i].copy[j] = '\0';
		ret[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	ret[i].str = 0;
	return (ret);
}


/* ************************************************************************** */
/* *******************************_V_2.0_************************************ */
/* ************************************************************************** */


#include "ft_stock_par.h"

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while(*str++)
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	int				i;
	char			*dst;

	i = 0;
	while (src[i])
		i++;
	if ((dst = (char *)malloc(sizeof(char) * (i + 1))) == ((void *)0))
		return ((void *)0);
	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int				i;
	t_stock_par		*stk;

	if ((stk = (t_stock_par *)malloc(sizeof(t_stock_par) * (ac + 1))) == ((void *)0))
		return ((void *)0);
	i = 0;
	while (i < ac)
	{
		stk[i].size_param = ft_strlen(av[i]);
		stk[i].str = av[i];
		stk[i].copy = ft_strdup(av[i]);
		stk[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	stk[i].str = 0;
	return (stk);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
