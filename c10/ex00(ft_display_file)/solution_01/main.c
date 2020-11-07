/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/03 23:28:39 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE	4096

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_display_stdin(int fd)
{
	char	buffer[BUFF_SIZE + 1];
	int		nb_char;

	while ((nb_char = read(fd, buffer, BUFF_SIZE)))
		write(1, buffer, nb_char);
	write(1, "\n", 1);
}


int		main(int argc, char **argv)
{
	int		file;

	if(argc == 2)
	{
		if (ft_strcmp(argv[1], ".") == 0 || ft_strcmp(argv[1], "/") == 0 ||
			ft_strcmp(argv[1], "..") == 0 || ft_strcmp(argv[1], "./") == 0 ||
			ft_strcmp(argv[1], "../") == 0)
		{
			write(1, "Is a directory.\n", 16);
			return (1);
		}
		if ((file = open(argv[1], O_RDONLY)) == -1)
			return (write(2, "OPEN(): An read error occurred. No such file or directory.\n", 59) || 1);
		ft_display_stdin(file);
		if (close(file) == -1)
			return (write(2, "CLOSE(): An file stream close error occurred.\n", 46) || 1);
	}
	else
	{
		if (argc < 2)
			return (write(2, "File name missing.\n", 19) || 1);
		if (argc > 2)
			return (write(2, "Too many arguments.\n", 20) || 1);
	}
	return (0);
}