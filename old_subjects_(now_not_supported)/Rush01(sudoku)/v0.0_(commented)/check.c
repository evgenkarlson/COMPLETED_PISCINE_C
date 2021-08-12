/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 13:28:00 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/08/12 12:28:30 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_block(char **tab, int y, int x, char nb)
{
	int	i;
	int	j;

	y -= (y % 3);
	x -= (x % 3);
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			if (tab[y][x++] == nb)
				return (0);
		}
		x = x - 3;
		y++;
	}
	return (1);
}

int	check_line(char **tab, char nb, int y)
{
	int	i;

	i = -1;
	while (++i < 9)
	{
		if (tab[y][i] == nb)
			return (0);
	}
	return (1);
}

int	check_column(char **tab, char nb, int x)
{
	int	i;

	i = -1;
	while (++i < 9)
	{
		if (tab[i][x] == nb)
			return (0);
	}
	return (1);
}

int	check_grille(char **tab, int n)
{
	int	i;
	int	j;

	if (n != 9)
		return (0);
	i = -1;
	while (++i < 9)
	{
		j = -1;
		while (tab[i][++j])
		{
			if ((tab[i][j] < '1' || tab[i][j] > '9') && tab[i][j] != '.')
				return (0);
		}
		if (j != 9)
			return (0);
	}
	return (1);
}
