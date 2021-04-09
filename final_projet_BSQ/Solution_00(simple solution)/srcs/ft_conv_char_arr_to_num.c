/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_char_arr_to_num.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:02:07 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/04/09 15:05:19 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

t_uns		**ft_conv_char_arr_to_num(t_unc **map_char, t_mapcfg *grid_config)
{
	int			i;
	int			j;
	t_uns		**map_num;
	
	if ((map_num = (t_uns **)malloc((grid_config->y + 1) * sizeof(t_uns *))) == (void *)0)
		return ((void *)0);
	map_num[grid_config->y] = ((void *)0);
	i = 0;
	while (i < grid_config->y)
	{
		if ((map_num[i] = (t_uns *)malloc((grid_config->x) * sizeof(t_uns))) == (void *)0)
			return ((void *)0);
		j = -1;
		while (++j < grid_config->x)
			map_num[i][j] = 0;
		i++;
	}
	i = -1;
	while (map_char[++i])
	{
		j = -1;
		while (++j < grid_config->x)
		{
			if (map_char[i][j] == grid_config->char_empty)
				map_num[i][j] = 1;
			else if (map_char[i][j] != '\n')
				map_num[i][j] = 0;
		}
	}
	return (map_num);
}
