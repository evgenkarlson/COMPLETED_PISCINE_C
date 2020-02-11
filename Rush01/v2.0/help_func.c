/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmet <jdesmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/12 21:29:49 by jdesmet           #+#    #+#             */
/*   Updated: 2014/07/13 11:57:28 by jpucelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		jp_putchar(char c)
{
	write(1, &c, 1);
}

int			jp_parse_sudoku_table(int pos[9][9], char **argv)
{
	int		ix;
	int		iy;

	iy = 0;
	while (iy < 9)
	{
		ix = 0;
		while (ix < 9)
		{
			if (argv[iy][ix] >= '0' && argv[iy][ix] <= '9')
				pos[iy][ix] = argv[iy][ix] - '0';
			else if (argv[iy][ix] == '.')
				pos[iy][ix] = 0;
			else
				return (0);
			ix++;
		}
		if (argv[iy][ix])
			return (0);
		iy++;
	}
	return (1);
}

void		jp_print_sudoku(int pos[9][9])
{
	int		i;
	int		j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			jp_putchar(pos[i][j] + 48);
			if (j != 8)
				jp_putchar(' ');
			j++;
		}
		jp_putchar('\n');
		i++;
	}
}

void		jp_set_pos(int *pos, int *orig, int i, int check)
{
	*pos = i;
	if (check == 0)
		*orig = i;
}
