/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 10:38:43 by jevan-de       #+#    #+#                */
/*   Updated: 2020/02/13 11:45:57 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "map.h"
#include "helpers.h"

int		main(int argc, char **argv)
{
	char	**maps;
	int		**grid;
	int		**final;
	int		index;
	int		fd;
	int		size;

	index = 1;
	maps = (char**)malloc(sizeof(char*) * (argc - 1));
	while (index < argc)
	{
		fd = open(argv[index], O_RDONLY);
		if (fd == -1)
			write(2, "map error\n", 10);
		else
		{
			*maps = (char*)malloc(sizeof(char) * BUFFSIZE);
			size = read(fd, *maps, BUFFSIZE);
			if (size == BUFFSIZE)
				write(2, "map error\n", 10);
			else
			{
				(*maps)[size] = '\0';
				grid = build_grid(grid, *maps, find_x(*maps), find_y(*maps));
				if (!grid)
					write(2, "map error\n", 10);
				else
				{
					final = find_square(grid, find_x(*maps), find_y(*maps));
					print_map(final, *maps);
				}
			}
		}
		index++;
		maps++;
	}
	return (0);
}
