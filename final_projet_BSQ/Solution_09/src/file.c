/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-thie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 00:01:45 by ple-thie          #+#    #+#             */
/*   Updated: 2018/07/25 22:57:23 by ple-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "tools.h"
#include "map.h"
#define BUFF_SIZE 8192

char	*ft_read_until(int fd, char c)
{
	char	*buff;
	char	*tmp;
	char	*input;
	int		len;

	if (!(buff = malloc(sizeof(*buff))))
		return (0);
	if (!(input = malloc(sizeof(*input))))
		return (0);
	input[0] = '\0';
	len = 0;
	while (read(fd, buff, 1) > 0 && *buff != c)
	{
		len++;
		tmp = input;
		if (!(input = malloc(sizeof(*input) * (++len + 1))))
			return (0);
		input[0] = '\0';
		ft_strcat(input, tmp);
		ft_strncat(input, buff, 1);
		free(tmp);
	}
	input[len] = '\0';
	return (input);
}

int		ft_complete_map(t_map_params *map, char *params)
{
	int		i;
	int		len;
	char	*lines;

	len = 0;
	while (params[len] != '\0')
		len++;
	if (!(lines = (char*)malloc(sizeof(char) * (len - 3 + 1))))
		return (0);
	i = 0;
	while (params[i + 3] != '\0')
	{
		lines[i] = params[i];
		i++;
	}
	lines[i] = '\0';
	map->lines = ft_atoi(lines);
	map->empty = params[i++];
	map->obstacles = params[i++];
	map->fill = params[i];
	return (1);
}

char	*ft_read_file(int fd, t_map_params *map)
{
	int		i;
	char	*tmp;
	char	*str;

	ft_complete_map(map, ft_read_until(fd, '\n'));
	tmp = ft_read_until(fd, '\n');
	map->columns = ft_strlen(tmp) + 1;
	if (map->lines <= 0)
		return (0);
	if (!(str = (char*)malloc(sizeof(*str) * (map->lines * map->columns))))
		return (0);
	str[0] = '\0';
	ft_strcat(str, tmp);
	str[map->columns - 1] = '\n';
	str += map->columns;
	if ((i = read(fd, str, (map->lines - 1) * map->columns)) < 0)
		return (0);
	if (i != (map->lines - 1) * map->columns)
		return (0);
	str -= map->columns;
	if (read(fd, tmp, 1) > 0 || str[map->lines * map->columns - 1] != '\n')
		return (0);
	str[map->lines * map->columns - 1] = '\0';
	return (str);
}
