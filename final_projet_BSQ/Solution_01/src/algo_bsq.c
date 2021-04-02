/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 09:42:11 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/03/10 01:49:30 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

void				adjust_list_mine(t_uns *y, t_coord **list)
{
	while (((*list) && (*list)->y < *y))
		(*list) = (*list)->next;
}

short				check_bomb(t_uns *x, t_uns *y, t_uns length, t_coord **list)
{
	t_coord		*mine;
	short		result;

	result = -1;
	mine = *list;
	while (mine && mine->y < (*y + length ))
	{
		if ((mine->x >= *x && mine->x < (*x + length))
		&& (mine->y >= *y ) && (mine->y < (*y + length)))
		{
			result = (mine->x);
		}
		mine = mine->next;
	}
	return (result);
}

t_square		*algo_bsq(t_coord **list, t_grid *grid)
{
	t_uns			currentx;
	t_uns			currenty;
	t_square		*max;
	t_square		*temp;
	short			opti;

	temp = square_init();
	max = square_init();
	currenty = 0;
	while (currenty < (grid->y - max->length))
	{
		currentx = 0;
		while (currentx < (grid->x - max->length))
		{
			adjust_list_mine(&currenty, list);
			temp->start->x = currentx;
			temp->start->y = currenty;
			temp->length = max->length + 1;
			opti = check_bomb(&currentx, &currenty, temp->length, list);
			while (temp->length <= (grid->x - currentx)
					&& temp->length <= (grid->y - currenty)
					&& (opti == -1))		
			{
				max->start->x = temp->start->x;
				max->start->y = temp->start->y;
				max->length = temp->length;
				temp->length++;
				opti = check_bomb(&currentx, &currenty, temp->length, list);
			}
			if (opti != -1 && opti > currentx)
				currentx = opti;
			currentx++;
		}
		currenty++;
	}
	free(temp->start);
	free(temp);
	return (max);
}
