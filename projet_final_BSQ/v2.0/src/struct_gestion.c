/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 05:44:36 by rdidier           #+#    #+#             */
/*   Updated: 2015/09/24 14:38:02 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_uns			list_length(t_coord **begin)
{
	t_coord		*list;
	t_uns		i;

	list = *begin;
	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

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
