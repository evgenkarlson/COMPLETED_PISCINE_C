/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_char_arr_to_num.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:02:07 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/08/08 21:17:30 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

static t_uns	**ft_allocate_map_num(t_mapcfg *grid_cfg)
{
	int			y;
	int			x;
	t_uns		**map_num;

	if (!(map_num = (t_uns **)malloc((grid_cfg->y + 1) * sizeof(t_uns *))))
		return (NULL);
	map_num[grid_cfg->y] = NULL;
	y = -1;
	while (++y < grid_cfg->y)
	{
		if (!(map_num[y] = (t_uns *)malloc((grid_cfg->x) * sizeof(t_uns))))
		{
			ft_destroy((void **)map_num);
			return (NULL);
		}
		x = -1;
		while (++x < grid_cfg->x)
			map_num[y][x] = 0;
	}
	return (map_num);
}

t_uns			**ft_conv_char_arr_to_num(t_unc **map_char, t_mapcfg *grid_cfg)
{
	int			y;
	int			x;
	t_uns		**map_num;

	if (!(map_num = ft_allocate_map_num(grid_cfg)))
		return (NULL);
	y = -1;
	while (map_char[++y])
	{
		x = -1;
		while (++x < grid_cfg->x)
		{
			if (map_char[y][x] == grid_cfg->char_empty)
				map_num[y][x] = 1;
			else if (map_char[y][x] != '\n')
				map_num[y][x] = 0;
		}
	}
	return (map_num);
}
