/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 01:14:51 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/03/09 23:47:11 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

t_coord		*display_line(t_coord *xy, t_coord *mine, t_square *square,
				t_grid *grid)
{
	t_coord *tmp;

	while (xy->x < grid->x - 1)
	{
		if (mine && mine->x == xy->x && mine->y == xy->y)
		{
			write(1, &grid->char_mine, 1);
			if (mine->next)
			{
				tmp = mine;
				mine = mine->next;
				free(tmp);
			}
		}
		else if (square->start->x <= xy->x &&
				square->length + square->start->x > xy->x &&
				square->start->y <= xy->y &&
				square->length + square->start->y > xy->y)
			write(1, &grid->char_square, 1);
		else
			write(1, &grid->char_empty, 1);
		xy->x++;
	}
	return (mine);
}

void		display(t_square *square, t_grid *grid, t_coord **begin)
{
	t_coord xy;
	t_coord *mine;

	mine = *begin;
	xy.y = 0;
	xy.x = 0;
	while (xy.y < grid->y)
	{
		xy.x = 0;
		mine = display_line(&xy, mine, square, grid);
		write(1, "\n", 1);
		xy.y++;
	}
}
