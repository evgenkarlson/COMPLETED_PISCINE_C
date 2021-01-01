/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 17:49:13 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/01/01 16:51:41 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

t_grid		create_struct_grid(void)
{
	t_grid	grid;

	grid.char_empty = 0;
	grid.char_mine = 0;
	grid.char_square = 0;
	grid.x = 0;
	grid.y = 0;
	return (grid);
}
