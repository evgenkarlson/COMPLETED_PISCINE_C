/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cfg_first_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:59:40 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/04/09 15:05:26 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

t_bool		ft_cfg_first_line(char *file_map, t_mapcfg *grid_config)
{
	t_unc	temp;
	t_unc	buffer;
	int		fd;
	
	if ((fd = open(file_map, O_RDONLY)) > 0)
	{
		while ( (read(fd, &buffer, 1) > 0) && (buffer != '\n'))
		{
			temp = grid_config->char_empty;
			if (!((temp >= '0' && temp <= '9') || temp == 0))
				return (0);
			grid_config->char_empty = grid_config->char_mine;
			grid_config->char_mine = grid_config->char_square;
			grid_config->char_square = buffer;
			if (temp)
				grid_config->y = (grid_config->y * 10) + (temp - '0');
		}
		temp = 0;
		while  (read(fd, &buffer, 1) > 0)
		{
			if (!((buffer == grid_config->char_square) || \
				(buffer == grid_config->char_empty) || \
				(buffer == grid_config->char_mine) || \
				(buffer == '\n')))
				return (0);
			if (buffer == '\n')
			{
				if (grid_config->x && grid_config->x != temp)
				{
					return (0);
				}
				grid_config->x = temp;
				temp = -1;
			}
			temp++;
		}
		if (close(fd) == -1)
		{
			ft_putstr("File closing error: ");
			ft_putstr(file_map);
			ft_putchar('\n');
		}
	}
	return (grid_config->y && grid_config->x && grid_config->char_square && \
			grid_config->char_empty && grid_config->char_mine);
}
