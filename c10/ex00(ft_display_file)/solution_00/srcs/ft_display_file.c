/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/03 23:26:16 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

void	ft_display_file(int argc, char **argv)
{
	int		fd;
	char	buffer;
	int		r;

	if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else if (argc < 2)
		ft_putstr("File name missing.\n");
	else if (argc == 2)
	{
		if (ft_strcmp(argv[1], ".") == 0 || ft_strcmp(argv[1], "/") == 0 ||
			ft_strcmp(argv[1], "..") == 0 || ft_strcmp(argv[1], "./") == 0 ||
			ft_strcmp(argv[1], "../") == 0)
		{
			ft_putstr(argv[1]);
			ft_putstr(": Is a directory.\n");
		}
		else if ((fd = open(argv[1], O_RDONLY)) == -1)
		{
			ft_putstr("OPEN(): An file open error occurred. No such file or directory.\n");
		}
		else
		{
			while ((r = read(fd, &buffer, 1)))
			{
				if (r == -1)
				{
					ft_putstr("READ(): A file read error has occurred. Check file permissions.\n");
					break;
				}
				else
				{
					ft_putchar(buffer);
				}
			}
			if (close(fd) == -1)
				ft_putstr("CLOSE(): An file stream close error occurred.\n");
			else
				ft_putchar('\n');
		}
	}
}