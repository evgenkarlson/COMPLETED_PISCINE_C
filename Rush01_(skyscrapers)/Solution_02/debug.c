/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 14:11:16 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/10 14:11:18 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_utils.h"
#include "constraint.h"

void	print_line(char *prefix, int length, char *suffix)
{
	int	index;

	str_write(prefix);
	index = 0;
	while (index++ < length)
		str_write("--");
	str_write(suffix);
}

void	print_line_of_value(char *prefix, int *array, int size, char *suffix)
{
	int	index;

	str_write(prefix);
	index = 0;
	while (index < size)
	{
		str_write_char((char)(array[index] + '0'));
		str_write(" ");
		index++;
	}
	str_write(suffix);
}

void	dump_grid(int **grid, int size, t_constr cnstr[4])
{
	int	index;
	int	jndex;

	print_line_of_value("    ", cnstr[UP].v, size, "");
	print_line("\n   -", size, "\n");
	index = 0;
	while (index < size)
	{
		str_write_char((char)(cnstr[LEFT].v[index] + '0'));
		str_write(" | ");
		jndex = 0;
		while (jndex < size)
		{
			str_write_char((char)(grid[index][jndex] + '0'));
			str_write(" ");
			jndex++;
		}
		str_write("| ");
		str_write_char((char)(cnstr[RIGHT].v[index] + '0'));
		str_write("\n");
		index++;
	}
	print_line("   -", size, "");
	print_line_of_value("\n    ", cnstr[DOWN].v, size, "\n");
}
