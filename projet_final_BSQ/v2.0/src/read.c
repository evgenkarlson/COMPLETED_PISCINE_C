/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 15:22:24 by adespond          #+#    #+#             */
/*   Updated: 2015/09/24 18:57:08 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_uns		prepare_read(int *fd)
{
	char	buffer[0];
	t_grid	grid;
	t_coord	xy;

	xy.x = 0;
	xy.y = 1;
	grid = create_struct_grid();
	if (ft_read(fd, buffer, &grid, &xy) == 1)
		return (1);
	return (0);
}

t_uns		first_line(char *buffer, t_grid *grid)
{
	char swap;

	swap = grid->char_empty;
	if (!((swap >= 48 && swap <= 57) || swap == 0))
		return (1);
	grid->char_empty = grid->char_mine;
	grid->char_mine = grid->char_square;
	grid->char_square = buffer[0];
	if (swap != 0)
		grid->y = (grid->y * 10) + (swap - '0');
	return (0);
}

t_uns		ft_read(int *fd, char *buffer, t_grid *grid, t_coord *xy)
{
	char		first;
	t_coord		**begin;
	t_coord		*tmp;

	first = 1;
	tmp = 0;
	begin = &tmp;
	while (read(*fd, buffer, 1))
	{
		if (buffer[0] == '\n' && first == 1)
			first = 0;
		else if (first == 1)
		{
			if (first_line(buffer, grid) == 1)
				return (1);
		}
		else
		{
			if (ft_read_char(xy, buffer, grid, begin) == 1)
				return (1);
		}
	}
	return (ft_after_read(xy, grid, begin));
}

t_uns		ft_read_char(t_coord *xy, char *buffer, t_grid *grid,
							t_coord **begin)
{
	xy->x++;
	if (buffer[0] == grid->char_mine)
		push_back(begin, xy);
	else if (buffer[0] == '\n')
	{
		if (grid->x == 0)
			grid->x = xy->x;
		if (grid->x != xy->x)
			return (1);
		xy->x = 0;
		xy->y++;
	}
	else if (buffer[0] != grid->char_empty)
		return (1);
	return (0);
}

t_uns		ft_after_read(t_coord *xy, t_grid *grid, t_coord **begin)
{
	t_square	*square;
	t_coord		*copy;

	copy = *begin;
	if (grid->char_empty == grid->char_mine ||
		grid->char_empty == grid->char_square ||
		grid->char_mine == grid->char_square)
		return (1);
	if (xy->y - 1 != grid->y)
		return (1);
	grid->x = grid->x - 1;
	printf("FINI, A TOI ROBIN\n");
	square = algo_bsq(&copy, grid);
	grid->x = grid->x + 1;
	display(square, grid, begin);
	printf("\n%d %d %d", square->start->x, square->start->y, square->length);
	return (0);
}
