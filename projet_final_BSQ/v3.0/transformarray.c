/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboniwel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 11:58:54 by jboniwel          #+#    #+#             */
/*   Updated: 2017/07/26 23:58:28 by lkinzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		transform(char src)
{
	if (src == g_obstacle)
		return (1);
	else
		return (0);
}

void	fill(int **tab, int height, int length, int i, int j)
{
	while (j < length)
	{
		tab[i][j] += tab[i][j - 1];
		j++;
	}
	j = 0;
	i = 1;
	while (i < height)
	{
		tab[i][j] += tab[i - 1][j];
		i++;
	}
	i = 1;
	while (i < height)
	{
		j = 1;
		while (j < length)
		{
			tab[i][j] += tab[i - 1][j] + tab[i][j - 1] - tab[i - 1][j - 1];
			j++;
		}
		i++;
	}
}

void	show(int **tab, int height, int length)
{
	int i;
	int j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < length)
		{
			printf("%d", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	make_it_numbers(int ***tab, char *array, int height, int fillit)
{
	int i;
	int j;
	int k;
	int **arr;

	i = 0;
	k = 0;
	arr = (int**)malloc(sizeof(int*) * height);
	while (array[i] != 0)
	{
		j = 0;
		arr[k] = (int*)malloc(g_length * sizeof(int));
		while (array[i] != '\n')
		{
			arr[k][j] = transform(array[i]);
			i++;
			j++;
		}
		k++;
		i++;
	}
	if (fillit)
		fill(arr, height, g_length, 0, 1);
	*tab = arr;
}

int main()
{
	return (0);
}
