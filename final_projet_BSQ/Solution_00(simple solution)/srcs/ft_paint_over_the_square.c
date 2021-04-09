/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint_over_the_square.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:02:07 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/04/09 15:05:02 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

void	ft_paint_over_the_square(t_unc **map_char, t_mapcfg *grid_config, t_square *final_result)
{
	int	i;
	int j;

	i = final_result->y - 1;
	while (++i < (final_result->y + final_result->size))
	{
		j = final_result->x - 1;  
		while (++j < (final_result->x + final_result->size))
		{
			if (map_char[i][j] == grid_config->char_empty)
				map_char[i][j] = grid_config->char_square;
		}
	}
}
