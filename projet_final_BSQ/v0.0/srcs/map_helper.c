/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 13:10:57 by jaleman           #+#    #+#             */
/*   Updated: 2016/08/31 13:10:59 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"
#include <stdio.h>

char	*read_map(int file, char *argv)
{
	int		i;
	int		r;
	char	*str_map;
	char	buffer[BUFFER_SIZE + 1];

	i = 0;
	while ((r = read(file, buffer, BUFFER_SIZE)))
	{
		buffer[r] = '\0';
		str_map = buffer;
	}
	return (str_map);
}

int		check_valid_map(char *str_map)
{
	int		i;
	int		nb;
	char	line;
	char	obstacle;
	char	fill;

	i = 0;
	nb = ft_atoi(str_map);
	while (str_map[i] >= '0' && str_map[i] <= '9')
		i += 1;
	if (nb < 0)
		return (-1);
	line = str_map[i++];
	obstacle = str_map[i++];
	fill = str_map[i++];
	while (str_map[i] != '\0')
	{
		if (str_map[i] == line || str_map[i] == obstacle || str_map[i] == '\n')
			i += 1;
		else
			return (-1);
	}
	return (1);
}
