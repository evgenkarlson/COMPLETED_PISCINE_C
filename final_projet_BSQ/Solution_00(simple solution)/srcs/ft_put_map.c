/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:58:26 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/04/09 15:05:29 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

void		ft_put_map(t_unc **map_char)
{
	int	i;
	int j;

	i = -1;
	while (map_char[++i])
	{
		j = -1;
		while (map_char[i][++j])
			ft_putchar((char)map_char[i][j]);
	}
}
