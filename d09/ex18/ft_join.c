/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 21:27:38 by jaleman           #+#    #+#             */
/*   Updated: 2017/03/30 21:27:39 by jaleman          ###   ########.fr       */
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
