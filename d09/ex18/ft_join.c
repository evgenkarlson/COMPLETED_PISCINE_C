/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	tab_size(char **tab)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 1;
	size = 0;
	while (tab && tab[j])
	{
		while (tab && tab[j][i])
			i += 1;
		size += i + 1;
		j += 1;
		i = 0;
	}
	size += j;
	return (size);
}

char		*ft_join(char **tab, char *sep)
{
	int		i;
	int		k;
	int		s;
	int		size;
	char	*str;

	i = 1;
	k = 0;
	s = 0;
	size = ft_size(tab);
	str = (char*)malloc(sizeof(char) * size + 1);
	while (s < (size - 1) && tab[i])
	{
		while (tab && tab[i][k])
			str[s++] = tab[i][k++];
		str[s++] = *sep;
		i += 1;
		k = 0;
	}
	str[s] = '\0';
	return (str);
}




/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */



static int	tab_size(char **tab)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 1;
	size = 0;
	while (tab && tab[j])
	{
		while (tab && tab[j][i])
			i += 1;
		size += i + 1;
		j += 1;
		i = 0;
	}
	size += j;
	return (size);
}

char		*ft_join(char **tab, char *sep)
{
	int		i;
	int		k;
	int		s;
	int		size;
	char	*str;

	i = 1;
	k = 0;
	s = 0;
	size = ft_size(tab);
	str = (char*)malloc(sizeof(char) * size + 1);
	while (s < (size - 1) && tab[i])
	{
		while (tab && tab[i][k])
			str[s++] = tab[i][k++];
		str[s++] = *sep;
		i += 1;
		k = 0;
	}
	str[s] = '\0';
	return (str);
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
