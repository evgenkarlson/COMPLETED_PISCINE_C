/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

void	ft_tail(int argc, char **argv)
{
	int		fd;
	int		i;

	g_progname = argv[0];
	i = 3;
	while (i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) == -1)
			ft_display_custom_error(errno, argv[i]);
		else
		{
			ft_disp_file(i, fd, argc, argv);
			if (close(fd) == -1)
				ft_display_custom_error(errno, argv[i]);
		}
		i++;
	}
}