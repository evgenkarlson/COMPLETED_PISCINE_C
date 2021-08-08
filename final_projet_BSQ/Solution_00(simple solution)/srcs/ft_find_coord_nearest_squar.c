/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_coord_nearest_squar.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:02:07 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/08/08 21:26:10 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

static t_uns	ft_min(t_uns left, t_uns up, t_uns up_lft)
{
	if ((left <= up) && (left <= up_lft))
		return (left);
	else if ((up <= left) && (up <= up_lft))
		return (up);
	else
		return (up_lft);
}

void			ft_find_coord_nearest_squar(t_uns **map_num, \
											t_mapcfg *grid_cfg, \
											t_square *final_result)
{
	int	y;
	int	x;

	y = -1;
	while (++y < grid_cfg->y)
	{
		x = -1;
		while (++x < grid_cfg->x)
		{
			if ((map_num[y][x] == 1) && (y > 0 && x > 0))
			{
				map_num[y][x] += ft_min(map_num[y - 1][x], \
										map_num[y][x - 1], \
										map_num[y - 1][x - 1]);
				if (map_num[y][x] > final_result->size)
				{
					final_result->size = map_num[y][x];
					final_result->y = y + 1 - final_result->size;
					final_result->x = x + 1 - final_result->size;
				}
			}
		}
	}
}
