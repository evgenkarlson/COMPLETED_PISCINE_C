/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cfg_and_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:59:40 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/08/08 21:26:17 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

static int	ft_get_x_cfg_and_check_file(int fd, t_mapcfg *grid_cfg)
{
	t_unc	tmp;
	t_unc	buf;

	tmp = 0;
	while (read(fd, &buf, 1) > 0)
	{
		if ((buf != '\n') && \
			(buf != grid_cfg->char_square) && \
			(buf != grid_cfg->char_mine) && \
			(buf != grid_cfg->char_empty))
			return (0);
		if (buf == '\n')
		{
			if (grid_cfg->x && (grid_cfg->x != tmp))
				return (0);
			grid_cfg->x = tmp;
			tmp = -1;
		}
		tmp++;
	}
	return (grid_cfg->x);
}

static int	ft_get_y_and_basic_cfg(int fd, t_mapcfg *grid_cfg)
{
	t_unc	tmp;
	t_unc	buf;

	while ((read(fd, &buf, 1) > 0) && (buf != '\n'))
	{
		tmp = grid_cfg->char_empty;
		if (!((tmp >= '0' && tmp <= '9') || !tmp))
			return (0);
		grid_cfg->char_empty = grid_cfg->char_mine;
		grid_cfg->char_mine = grid_cfg->char_square;
		grid_cfg->char_square = buf;
		if ((tmp))
			grid_cfg->y = (grid_cfg->y * 10) + (tmp - '0');
	}
	return (grid_cfg->y && grid_cfg->char_square && \
			grid_cfg->char_empty && grid_cfg->char_mine);
}

t_bool		ft_cfg_and_check(char *file_map, t_mapcfg *grid_cfg)
{
	t_unc	buf;
	int		fd;

	if ((fd = open(file_map, O_RDONLY)) > 0)
	{
		if ((read(fd, &buf, 0) == 0) && ft_get_y_and_basic_cfg(fd, grid_cfg))
				ft_get_x_cfg_and_check_file(fd, grid_cfg);
		if (close(fd) == -1)
		{
			ft_putstr("File closing error: ");
			ft_putstr(file_map);
			ft_putchar('\n');
		}
	}
	return (grid_cfg->y && grid_cfg->x && grid_cfg->char_square && \
			grid_cfg->char_empty && grid_cfg->char_mine);
}
