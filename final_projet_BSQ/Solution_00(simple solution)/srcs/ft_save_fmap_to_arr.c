/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_fmap_to_arr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:02:07 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/08/08 21:25:57 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

static void		ft_copy_file_to_array(int fd, t_mapcfg *grid_cfg, t_unc	**map)
{
	size_t	i;
	size_t	j;
	t_unc	buffer;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while ((++j <= (grid_cfg->x)) && (read(fd, &buffer, 1) > 0))
		{
			map[i][j] = buffer;
			if (buffer == '\n')
				break ;
		}
	}
}

static t_unc	**ft_allocate_map_char(t_mapcfg *grid_cfg)
{
	size_t	i;
	size_t	j;
	t_unc	**map;

	if (!(map = (t_unc **)malloc((grid_cfg->y + 1) * sizeof(t_unc *))))
		return (NULL);
	map[grid_cfg->y] = NULL;
	i = -1;
	while (++i < grid_cfg->y)
	{
		if (!(map[i] = (t_unc *)malloc((grid_cfg->x + 2) * sizeof(t_unc))))
		{
			ft_destroy((void **)map);
			return (NULL);
		}
		j = -1;
		while (++j < grid_cfg->x)
			map[i][j] = '\0';
		map[i][j] = '\0';
	}
	return (map);
}

t_unc			**ft_save_fmap_to_arr(char *file_map, t_mapcfg *grid_cfg)
{
	int		fd;
	t_unc	buffer;
	t_unc	**map;

	map = NULL;
	if (((fd = open(file_map, O_RDONLY)) >= 0))
	{
		while (read(fd, &buffer, 1) > 0)
		{
			if (buffer == '\n')
				break ;
		}
		if ((map = ft_allocate_map_char(grid_cfg)))
			ft_copy_file_to_array(fd, grid_cfg, map);
		if ((close(fd)) == -1)
		{
			ft_putstr("File closing error: ");
			ft_putstr(file_map);
			ft_putchar('\n');
		}
	}
	return (map);
}
