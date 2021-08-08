/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:02:07 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/08/08 21:25:49 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

void	bsq(char *file_map)
{
	t_unc		**map_char;
	t_uns		**map_num;
	t_mapcfg	grid_cfg = {0};
	t_square	final_result = {0};

	if ((ft_cfg_and_check(file_map, &grid_cfg) && \
		(map_char = ft_save_fmap_to_arr(file_map, &grid_cfg)) && \
		(map_num = ft_conv_char_arr_to_num(map_char, &grid_cfg))))
	{
		ft_find_coord_nearest_squar(map_num, &grid_cfg, &final_result);
		ft_paint_over_the_squar(map_char, &grid_cfg, &final_result);
		ft_put_map(map_char);
		ft_destroy((void **)map_char);
		ft_destroy((void **)map_num);
	}
	else
	{
		ft_putstr("Error while working with map file: ");
		ft_putstr(file_map);
	}
}
