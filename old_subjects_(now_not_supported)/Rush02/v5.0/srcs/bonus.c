/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 02:41:22 by flklein           #+#    #+#             */
/*   Updated: 2018/09/16 03:26:58 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle2.h"

int		ft_strlen_nl(char *str)
{
	int		len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

int		is_square(char *str, int x, int y)
{
	int		i;
	int		l;

	l = 0;
	i = 0;
	while (str[i])
	{
		if (ft_strlen_nl(str + i) != x)
			return (0);
		i += x + 1;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			l++;
		i++;
	}
	return (l == y && x == y);
}

int		is_rectangle(char *str, int x, int y)
{
	int		i;
	int		l;

	l = 0;
	i = 0;
	while (str[i])
	{
		if (ft_strlen_nl(str + i) != x)
			return (0);
		i += x + 1;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			l++;
		i++;
	}
	return (l == y);
}
