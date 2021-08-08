/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:58:26 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/08/08 21:26:03 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

void		ft_put_map(t_unc **map_char)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (map_char[++y])
	{
		x = -1;
		while (map_char[y][++x])
			ft_putchar((char)map_char[y][x]);
	}
}
