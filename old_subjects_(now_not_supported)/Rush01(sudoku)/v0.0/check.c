/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 13:28:00 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/19 15:01:45 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_line(char **tab, char nb, int y)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (tab[y][i] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	check_column(char **tab, char nb, int x)
{
	int	i;

	i = 1;
	while (i <= 9)
	{
		if (tab[i][x] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	check_block(char **tab, int y, int x, char nb)
{
	int i;
	int j;

	i = -1;
	if (y <= 3)
		y = 1;
	else if (y <= 6)
		y = 4;
	else if (y <= 9)
		y = 7;
	x = x - (x % 3);
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			if (tab[y][x] == nb)
				return (0);
			x++;
		}
		x = x - 3;
		y++;
	}
	return (1);
}

int	check_grille(char **tab, int n)
{
	int i;
	int j;

	i = 1;
	if (n == 10)
	{
		while (i <= 9)
		{
			j = 0;
			while (tab[i][j])
			{
				if ((tab[i][j] < '1' || tab[i][j] > '9') && tab[i][j] != '.')
					return (0);
				j++;
			}
			if (j != 9)
				return (0);
		i++;
		}
		return (1);
	}
	else
		return (0);
}
