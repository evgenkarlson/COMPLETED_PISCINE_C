/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 01:18:03 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

void	ft_tail(int argc, char **argv)
{
	int		fd;
	int		i;

	if (argc > 1)
	{
		g_progname = basename(*argv);
		i = 3;
		while (i < argc)
		{
			if ((fd = open(argv[i], O_RDONLY)) == -1)
				ft_display_custom_error(errno, argv[i]);
			else
			{
				ft_display_file(i, fd, argc, argv);
				if (close(fd) == -1)
					ft_display_custom_error(errno, argv[i]);
			}
			i++;
		}
	}
	else if (argc == 1)
		ft_stdin();
}