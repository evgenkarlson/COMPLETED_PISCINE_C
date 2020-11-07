/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 23:01:21 by lkinzel           #+#    #+#             */
/*   Updated: 2017/07/26 23:03:25 by lkinzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	insert(t_ptr *head, char c)
{
	while (*head)
		head = &(*head)->next;
	*head = malloc(sizeof(**head));
	(*head)->val = c;
	(*head)->next = NULL;
}

void	fill_str(t_ptr head, char *str)
{
	int i;

	i = 0;
	while (head)
	{
		str[i] = head->val;
		head = head->next;
		i++;
	}
	str[i] = '\0';
}

void	freelist(t_ptr *head)
{
	t_ptr tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

int		is_valid(int **arr, int startingpos[2], int size)
{
	size--;
	if ((startingpos[0] + size >= g_height) ||
			(startingpos[1] + size >= g_length))
		return (0);
	if ((arr[startingpos[0] + size][startingpos[1] + size]
				- arr[startingpos[0] + size][startingpos[1] - 1]
				- arr[startingpos[0] - 1][startingpos[1] + size]
				+ arr[startingpos[0] - 1][startingpos[1] - 1]) > 0)
		return (0);
	else
		return (1);
}

int		brute_force_valid(int **arr, int startingpos[2], int size)
{
	int row;
	int col;

	row = startingpos[0];
	col = startingpos[1];
	if (size == 1)
	{
		if (arr[row][col] == 0)
			return (1);
		else
			return (0);
	}
	while (row < startingpos[0] + size)
	{
		col = startingpos[1];
		while (col < startingpos[1] + size)
		{
			if (arr[row][col] != 0)
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}
