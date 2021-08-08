/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint_over_the_squar.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:02:07 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/08/08 21:26:07 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

void	ft_paint_over_the_squar(t_unc **map_char, t_mapcfg *grid_config, \
								t_square *final_result)
{
	int	y;
	int	x;

	y = final_result->y - 1;
	while (++y < (final_result->y + final_result->size))
	{
		x = final_result->x - 1;
		while (++x < (final_result->x + final_result->size))
		{
			if (map_char[y][x] == grid_config->char_empty)
				map_char[y][x] = grid_config->char_square;
		}
	}
}
