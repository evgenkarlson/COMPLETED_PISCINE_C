/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_fmap_to_arr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:02:07 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/04/09 15:05:22 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

t_unc		**ft_save_fmap_to_arr(char *file_map, t_mapcfg *grid_config)
{
	int		fd;
	int		i;
	int		j;
	t_unc	buffer;
	t_unc	**map_char;
	
	map_char = ((void *)0);
	if (((fd = open(file_map, O_DIRECTORY)) < 0) && \
		((fd = open(file_map, O_RDONLY)) >= 0))
	{
		while (read(fd, &buffer, 1) > 0)
		{
			if (buffer == '\n')
				break;
		}
		if ((map_char = (t_unc **)malloc((grid_config->y + 1) * sizeof(t_unc *))) == (void *)0)
			return ((void *)0);
		map_char[grid_config->y] = ((void *)0);
		i = -1;
		while (++i < grid_config->y)
		{
			if ((map_char[i] = (t_unc *)malloc((grid_config->x + 2) * sizeof(t_unc))) == (void *)0)
				return ((void *)0);
			j = -1;
			while (++j < grid_config->x)
				map_char[i][j] = '\0';
			map_char[i][grid_config->x + 1] = '\0';
		}
		i = -1;
		while (map_char[++i])
		{
			j = -1;
			while ((++j < (grid_config->x + 1)) && (read(fd, &buffer, 1) > 0))
			{
				map_char[i][j] = buffer;
				if(buffer == '\n')
					break;
			}
		}
		if ((close(fd)) == -1)
		{
			ft_putstr("File closing error: ");
			ft_putstr(file_map);
			ft_putchar('\n');
		}
	}
	return (map_char);
}
