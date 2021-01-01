/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <cmutti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 21:49:52 by cmutti            #+#    #+#             */
/*   Updated: 2015/09/24 17:31:01 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void		ft_get_record(t_instr *info, char *str, t_record *record)
{
	int		position[2];
	int		max;

	position[1] = 0;
	while (position[1] + record->max < info->height)
	{
		position[0] = 0;
		while (position[0] + record->max < info->width)
		{
			max = ft_check_case(str, info, position, record->max);
			if (max > record->max)
			{
				record->max = max;
				record->x = position[0];
				record->y = position[1];
			}
			else if (max < 0)
			{
				if (position[0] + -max < info->width)
					position[0] = position[0] + -max;
			}
			position[0]++;
		}
		position[1]++;
	}
}

int			ft_check_case(char *str, t_instr *info, int position[2], int size)
{
	int		i;
	int		temp;

	i = size + 1;
	while (1)
	{
		if (position[0] + i > info->width)
			return (i - 1);
		else if (position[1] + i - 1 >= info->height)
			return (i - 1);
		temp = ft_check_square(str, position, info, i);
		if (temp > 0)
		{
			i++;
			while (ft_bigger_sqr(str, position, info, i))
				i++;
			return (i - 1);
		}
		else
			return (temp);
	}
}

int			ft_check_square(char *str, int position[2], t_instr *info, int size)
{
	int i;
	int j;
	int start;

	start = info->length + position[0] + (position[1]) * (info->width + 1);
	i = size - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < size)
		{
			if (str[start + i + j * (info->width + 1)] == info->obst)
				return (-i);
			else if (str[start + i + j * (info->width + 1)] == '\n')
				return (0);
			j++;
		}
		i--;
	}
	return (1);
}

void		ft_fill_board(t_record *record, char *str, t_instr *info)
{
	int		x;
	int		y;
	int		position;

	y = 0;
	position = info->length + record->x + (record->y) * (info->width + 1);
	while (y < record->max)
	{
		x = 0;
		while (x < record->max)
		{
			str[position + x + y * (info->width + 1)] = info->full;
			x++;
		}
		y++;
	}
}

t_record	*ft_new_record(void)
{
	t_record	*new;

	new = (t_record *)malloc(sizeof(t_record));
	if (new)
	{
		new->x = 0;
		new->y = 0;
		new->max = 0;
	}
	return (new);
}
