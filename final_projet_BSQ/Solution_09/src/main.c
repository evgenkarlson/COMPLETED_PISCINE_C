/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-thie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 23:47:59 by ple-thie          #+#    #+#             */
/*   Updated: 2018/07/25 23:22:59 by ple-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "tools.h"
#include "main.h"
#include <fcntl.h>
#include <stdlib.h>

void	ft_map_display(int **map, t_map_params *params)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = -1;
	if (!(str = malloc(sizeof(*str) * params->columns)))
		return ;
	while (++i < params->lines)
	{
		k = 0;
		j = -1;
		while (++j < params->columns - 1)
		{
			if (map[i][j] == -1)
				str[k++] = params->fill;
			else if (map[i][j] == 0)
				str[k++] = params->obstacles;
			else
				str[k++] = params->empty;
		}
		str[k++] = '\n';
		str[k] = '\0';
		ft_putstr(str);
	}
}

int		main(int ac, char **av)
{
	int				i;
	int				fd;
	int				**map;
	char			*grid;
	t_map_params	params;

	i = 0;
	while (i < ac || (ac == 1 && i == 0))
	{
		if (ac-- == 1)
			fd = 0;
		else if ((fd = open(av[++i], O_RDONLY)) == -1)
			ft_map_error();
		if (fd != -1)
		{
			if ((grid = ft_read_file(fd, &params))
					&& (map = ft_map_converter(grid, &params)))
				ft_map_display(ft_square_calc(map, params), &params);
			else
				ft_map_error();
		}
	}
	return (0);
}
