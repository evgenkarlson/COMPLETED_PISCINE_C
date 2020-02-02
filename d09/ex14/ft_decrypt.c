/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrypt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 21:27:38 by jaleman           #+#    #+#             */
/*   Updated: 2017/03/30 21:27:39 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_perso.h"

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

char		*ft_get_name(int *i, char *str)
{
	int		j;
	char	*name;

	j = 0;
	name = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	while ((str[*i] >= 'a' && str[*i] <= 'z')
			|| (str[*i] >= 'A' && str[*i] <= 'Z'))
		name[j++] = str[*i++];
	name[j] = '\0';
	return (name);
}

int			ft_get_age(int *i, char *str)
{
	int age;

	age = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
		age = (age * 10) + (str[*i++] - '0');
	return (age);
}

t_perso		**ft_create_struct_tab(char *str, int nbstructs)
{
	int		i;
	int		j;
	t_perso	**tab;

	i = 0;
	j = 0;
	tab = (t_perso**)malloc(sizeof(t_perso**) * (nbstructs + 1));
	while (str[i])
	{
		tab[j]->age = ft_get_age(&i, str);
		i += 1;
		tab[j]->name = ft_get_name(&i, str);
		i += 1;
		j += 1;
	}
	return (tab);
}

t_perso		**ft_decrypt(char *str)
{
	int i;
	int nbstructs;

	i = 0;
	nbstructs = 0;
	while (str[i])
	{
		while (str[i] >= '0' && str[i] <= '9')
			i += 1;
		if (str[i] == '|')
			i += 1;
		while ((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z'))
			i += 1;
		if (str[i] == ';')
			i += 1;
		nbstructs += 1;
	}
	return (ft_create_struct_tab(str, nbstructs));
}
