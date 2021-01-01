/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:24:45 by fyusuf-a          #+#    #+#             */
/*   Updated: 2019/08/21 20:08:58 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "solution.h"
#include "utilities.h"

t_bool			find_solution(t_solution *sol, const t_grid *grid)
{
	UINT		i;
	UINT		j;
	t_solution	intent;

	i = 0;
	sol->size = 0;
	intent.size = 1;
	while (i < grid->h - sol->size)
	{
		j = 0;
		while (j < grid->w - sol->size)
		{
			intent.x = j;
			intent.y = i;
			actualize_sol(sol, &intent, grid);
			j++;
		}
		i++;
	}
	return (sol->size ? true : false);
}

static void		actualize_sol(t_solution *sol, t_solution *intent,
					const t_grid *grid)
{
	if (!fits(intent, grid))
		return ;
	sol->x = intent->x;
	sol->y = intent->y;
	sol->size++;
	intent->size++;
	while (fits_succ(intent, grid))
	{
		sol->size++;
		intent->size++;
	}
}

static t_bool	fits(const t_solution *intent, const t_grid *grid)
{
	int i;
	int i_max;
	int j;
	int j_max;

	if (dont_fit_basic(intent, grid))
		return (false);
	i = intent->y;
	i_max = i + intent->size;
	j_max = intent->x + intent->size;
	while (i < i_max)
	{
		j = intent->x;
		while (j < j_max)
		{
			if (grid->map[i][j] == grid->translate[obstacle])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static t_bool	fits_succ(const t_solution *intent, const t_grid *grid)
{
	int i;
	int j;
	int i_max;

	if (dont_fit_basic(intent, grid))
		return (false);
	i = intent->x;
	i_max = i + intent->size;
	j = intent->y + intent->size - 1;
	while (i < i_max)
	{
		if (grid->map[j][i] == grid->translate[obstacle])
			return (false);
		i++;
	}
	i = intent->y;
	i_max = i + intent->size - 1;
	j = intent->x + intent->size - 1;
	while (i < i_max)
	{
		if (grid->map[i][j] == grid->translate[obstacle])
			return (false);
		i++;
	}
	return (true);
}

static t_bool	dont_fit_basic(const t_solution *intent, const t_grid *grid)
{
	return (intent->x + intent->size > grid->w
			|| intent->y + intent->size > grid->h);
}
