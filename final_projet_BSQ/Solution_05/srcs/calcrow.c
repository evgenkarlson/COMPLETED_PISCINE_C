/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcrow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:10:38 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/13 13:37:45 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

int		ft_fullboard(int len, int fd)
{
	char	buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (read(fd, &buffer, 1))
	{
		if ((buffer != '\n') && i < g_row)
		{
			if (ft_charsafe(buffer, &j, len, &i) == -1)
				return (-1);
			j++;
		}
		else if (ft_checklen(&j, len, &i) == -1)
			return (-1);
	}
	if (i != g_row)
		return (-1);
	close(fd);
	ft_findsquare(len);
	return (1);
}

int		ft_initboard(int len, char *file)
{
	int		fd;
	int		i;
	char	buffer[1];

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_strerror();
		return (0);
	}
	while (read(fd, buffer, 1) && ((*buffer != '\n')))
		;
	if (!(g_board = (int **)malloc((g_row) * sizeof(int*))))
		return (0);
	i = 0;
	while (i < g_row)
	{
		if (!(g_board[i] = (int *)malloc((len) * sizeof(int))))
			return (0);
		i++;
	}
	if (ft_fullboard(len, fd) == -1)
		return (-1);
	return (1);
}

int		ft_lsrow(int fd, char *file)
{
	int		i;
	int		x;
	int		len;
	char	buffer[1];

	i = 0;
	x = 0;
	len = 0;
	while (read(fd, buffer, 1) && ((*buffer != '\n') || i == 0))
	{
		if (x == 5)
		{
			len++;
		}
		if (*buffer == '\n')
		{
			i++;
			x = 5;
		}
	}
	close(fd);
	if ((len == 0) || ((ft_initboard(len, file)) == -1))
		return (-1);
	return (1);
}

int		ft_rowlen(char *str, int fd)
{
	int		i;
	char	buffer;

	i = 0;
	if (fd != 0)
		if ((fd = open(str, O_RDONLY)) == -1)
			return (0);
	while (read(fd, &buffer, 1))
	{
		i++;
		if (buffer == '\n')
			break ;
	}
	close(fd);
	return (i);
}
