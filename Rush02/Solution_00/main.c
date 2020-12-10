/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:08:13 by cromalde          #+#    #+#             */
/*   Updated: 2020/11/08 19:20:08 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>

void	ft_print(char *end)
{
	char *begin;
	char *finish;

	begin = ft_cinstr(end);
	finish = ft_strchar(begin, '\n');
	while (begin < finish)
		ft_putchar(*begin++);
	ft_putchar('\n');
}

void	ft_stdin(int fd, char *indict)
{
	char	*buffer;
	char	*end;
	int		i;

	i = 0;
	buffer = 0;
	if (!(indict = (char *)malloc(2000)))
		return ;
	if ((fd = open("numbers.dict", O_RDONLY)) == -1)
	{
		write(1, "Dict Error", 11);
		return ;
	}
	while ((read(fd, &indict[i], 1)))
		i++;
	if (close(fd) == -1)
	{
		write(1, "Close Error", 12);
		return ;
	}
	if (((end = ft_insrc(indict, ft_stread(buffer)))) == 0)
		return ;
	ft_print(end);
}

void	ft_alt_start(char *argv, int fd, char *indict)
{
	char	*end;
	int		i;

	i = 0;
	if (!(indict = (char *)malloc(2000)))
		return ;
	if ((fd = open(&argv[1], O_RDONLY)) == -1)
	{
		write(1, "Dict Error", 11);
		return ;
	}
	while ((read(fd, &indict[i], 1)))
		i++;
	if (close(fd) == -1)
	{
		write(1, "Close Error", 12);
		return ;
	}
	if (((end = ft_strstr(indict, argv))) == 0)
		return ;
	ft_print(end);
}

void	ft_start(char *argv, int fd, char *indict)
{
	char	*end;
	int		i;

	i = 0;
	if (!(indict = (char *)malloc(2000)))
		return ;
	if ((fd = open("numbers.dict", O_RDONLY)) == -1)
	{
		write(1, "Dict Error", 11);
		return ;
	}
	while ((read(fd, &indict[i], 1)))
		i++;
	if (close(fd) == -1)
	{
		write(1, "Close Error", 12);
		return ;
	}
	if (((end = ft_strstr(indict, argv))) == 0)
		return ;
	ft_print(end);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*indict;

	fd = 0;
	indict = 0;
	if (argc > 3)
		write(1, "Too many arguments", 18);
	else if (argc == 2)
	{
		if (ft_valid_input(argv[1]))
			ft_start(argv[1], fd, indict);
		else
			write(1, "Invalid argument", 16);
	}
	else if (argc == 3)
	{
		if (ft_valid_input(argv[2]))
			ft_alt_start(argv[2], fd, indict);
		else
			write(1, "Invalid argument", 16);
	}
	else
		ft_stdin(fd, indict);
	free(indict);
}
