/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 19:49:10 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_disp_file(int fd)
{
	char	buffer;

	while (read(fd, &buffer, 1) != 0)
		write(1, &buffer, 1);
}

int		main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		if (argc > 2)
			write(2, "Too many arguments.\n", 20);
		if (argc < 2)
			write(2, "File name missing.\n", 19);
		return (1);
	}
	else
	{
		if (ft_strcmp(argv[1], ".") == 0 || ft_strcmp(argv[1], "/") == 0 ||
			ft_strcmp(argv[1], "..") == 0 || ft_strcmp(argv[1], "./") == 0 ||
			ft_strcmp(argv[1], "../") == 0)
		{
			write(1, "Is a directory.\n", 16);
			return (1);
		}
		if ((fd = open(argv[1], O_RDONLY)) == -1)
		{
			write(1, "OPEN(): An read error occurred. No such file or directory.\n", 59);
			return (1);
		}
		ft_disp_file(fd);
		if ((close(fd)) == -1)
		{
			write(1, "CLOSE(): An file stream close error occurred.\n", 46);
			return (1);
		}
	}
	return (0);
}
