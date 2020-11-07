/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	write(1, str, i);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int		ft_display_file(char *filename)
{
	int		fd;
	char	buffer;
	int		len;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_putstr("OPEN(): An read error occurred. No such file or directory.\n");
		return (1);
	}
	while ((len = read(fd, &buffer, 1)))
	{
		ft_putchar(buffer);
	}
	if ((close(fd)) == -1)
	{
		ft_putstr("CLOSE(): An file stream close error occurred.\n");
		return (2);
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], ".") == 0 || ft_strcmp(argv[1], "/") == 0 ||
			ft_strcmp(argv[1], "..") == 0 || ft_strcmp(argv[1], "./") == 0 ||
			ft_strcmp(argv[1], "../") == 0)
		{
			ft_putstr(argv[1]);
			ft_putstr(": Is a directory.\n");
			return (1);
		}
		if (ft_display_file(argv[1]) > 0)
			return (1);
	}
	else if (argc != 2)
	{
		if (argc > 2)
			ft_putstr("Too many arguments.\n");
		if (argc < 1)
			ft_putstr("File name missing.\n");
		return (1);
	}
	return (0);
}
