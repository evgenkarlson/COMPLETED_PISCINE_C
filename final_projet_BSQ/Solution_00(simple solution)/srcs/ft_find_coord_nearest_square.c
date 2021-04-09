/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_coord_nearest_square.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:02:07 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/04/09 15:05:04 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

void		ft_find_coord_nearest_square(t_uns **map_num, t_mapcfg *grid_config, t_square *final_result)
{
	int	i;
	int j;

	i = -1;
	while (++i < grid_config->y)
	{
		j = -1;
		while (++j < grid_config->x)
		{
			if ((map_num[i][j] == 1) && (i > 0 && j > 0))
			{
				map_num[i][j] += ft_min(map_num[i - 1][j], map_num[i][j - 1], map_num[i - 1][j - 1]);
				if (map_num[i][j] > final_result->size)
				{
					final_result->size = map_num[i][j];
					final_result->y = i + 1 - final_result->size;
					final_result->x = j + 1 - final_result->size;
				}
			}
		}
	}
}
