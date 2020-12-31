/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretty_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:21:28 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/11 15:21:29 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_utils.h"

void	print_grid(int **grid, int size)
{
	int	index;
	int	jndex;

	index = 0;
	while (index < size)
	{
		jndex = 0;
		while (jndex < size)
		{
			str_write_char((char)(grid[index][jndex] + '0'));
			if (jndex != size - 1)
				str_write(" ");
			jndex++;
		}
		if (index != size - 1)
			str_write("\n");
		index++;
	}
}
