/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "ft_lib.h"

void	ft_display_file(int argc, char **argv)
{
	int		file;

	if (argc > 1)
	{
		if (ft_strcmp(argv[1], ".") == 0 || ft_strcmp(argv[1], "/") == 0 ||
			ft_strcmp(argv[1], "..") == 0 || ft_strcmp(argv[1], "./") == 0 ||
			ft_strcmp(argv[1], "../") == 0)
		{
			ft_putstr(argv[1]);
			ft_putstr(": Is a directory.\n");
			return ;
		}
		if ((file = open(argv[1], O_RDONLY)) == -1)
		{
			ft_putstr("No such file or directory.\n");
			return ;
		}
		ft_display_stdin(file);
		close(file);
	}
	if (argc > 2)
		ft_putstr("Too many arguments.\n");
	if (argc < 2)
		ft_putstr("File name missing.\n");
}