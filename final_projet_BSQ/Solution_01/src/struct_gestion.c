/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_gestion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 05:44:36 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/03/09 20:44:46 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

t_square		*square_init(void)
{
	t_square	*square;
	t_coord		*start;

	start = (t_coord*)malloc(sizeof(t_coord));
	square = (t_square*)malloc(sizeof(t_square));
	start->x = 0;
	start->y = 0;
	start->next = 0;
	square->length = 0;
	square->start = start;
	return (square);
}

t_coord			*create_mine(t_coord *xy)
{
	t_coord *mine;

	mine = (t_coord*)malloc(sizeof(t_coord));
	if (mine)
	{
		mine->x = xy->x - 1;
		mine->y = xy->y - 1;
		mine->next = 0;
	}
	return (mine);
}

void			push_back(t_coord **begin, t_coord *xy)
{
	t_coord *mine;
	t_coord *tmp;

	if (*begin == 0)
	{
		*begin = create_mine(xy);
		xy->next = *begin;
	}
	else
	{
		tmp = xy->next;
		mine = create_mine(xy);
		while (tmp->next != 0)
		{
			tmp = tmp->next;
		}
		xy->next = mine;
		tmp->next = mine;
	}
}
