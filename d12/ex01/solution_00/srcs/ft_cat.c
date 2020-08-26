/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

void	ft_display_file(int file, char *argv)
{
	int		r;
	char	buffer[BUF_SIZE + 1];

	while ((r = read(file, buffer, BUF_SIZE)))
	{
		if (r == -1)
		{
			ft_display_custom_error(errno, argv);
			break;
		}
		else
		{
			buffer[r] = '\0';
			ft_putstr(buffer);
		}
	}
}

int		ft_cat(int argc, char **argv)
{
	int	i;
	int	file;

	g_progname = *argv;
	i = 0;
	while (++i < argc)
	{
		if (argc < 2 || argv[i][0] == '-')
			ft_display_file(1, argv[0]);
		if ((file = open(argv[i], O_RDONLY)) == -1)
			ft_display_custom_error(errno, argv[i]);
		if (file != -1)
			ft_display_file(file, argv[i]);
		close(file);
	}
	return (0);
}
