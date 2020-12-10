/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 08:48:11 by cromalde          #+#    #+#             */
/*   Updated: 2020/11/12 19:34:10 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

int		ft_read_fline(int fd, char *arg, char *input)
{
	int		len;

	if ((len = ft_rowlen(arg, fd) - 1) < 4)
		return (-1);
	if (!(input = (char *)malloc(len)))
		return (0);
	read(fd, input, len);
	g_full = input[len - 1];
	g_obst = input[len - 2];
	g_empty = input[len - 3];
	input[len - 3] = '\0';
	g_row = ft_atoi(input);
	free(input);
	if (ft_setok() == 0)
		return (0);
	if ((ft_lsrow(fd, arg)) == -1)
		return (-1);
	return (0);
}

void	ft_stdin(int fd, char *input)
{
	char buffer[1];

	fd = open("./.EleCri", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (read(0, buffer, 1))
	{
		write(fd, buffer, 1);
	}
	close(fd);
	if ((fd = open("./.EleCri", O_RDONLY)) == -1)
		ft_strerror();
	else if (ft_read_fline(fd, "./.EleCri", input) == -1)
		ft_strerror();
	close(fd);
	return ;
}

int		main(int argc, char **argv)
{
	int		i;
	int		fd;
	int		nwl;
	char	*input;

	i = 0;
	nwl = 1;
	input = 0;
	if (argc == 1)
		ft_stdin(0, input);
	else
		while (++i < argc)
		{
			if ((fd = open(argv[i], O_RDONLY)) == -1)
			{
				ft_strerror();
				continue ;
			}
			else if (ft_read_fline(fd, argv[i], input) == -1)
				ft_strerror();
			close(fd);
			if (nwl++ + 1 != argc)
				ft_putchar('\n');
		}
	return (0);
}
