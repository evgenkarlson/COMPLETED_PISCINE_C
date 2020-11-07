/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 14:30:52 by jaleman           #+#    #+#             */
/*   Updated: 2016/08/29 14:30:53 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

int		main(int argc, char *argv[])
{
	int		i;
	int		file;
	int		size;
	char	*map;
	char	buffer[BUFFER_SIZE + 1];

	i = 0;
	size = 0;
	if (argc == 1)
		ft_stdin(file);
	if (*argv[1] == 'K')
		kwame_is_life();
	while (++i < argc)
	{
		file = open(argv[i], O_RDONLY);
		if (file == -1)
			ERROR_MAP;
		if (file != -1)
		{
			map = read_map(file, argv[i]);
			if (check_valid_map(map) != 1)
				ERROR_MAP;
		}
		close(file);
		ft_putchar('\n');
	}
	return (0);
}
