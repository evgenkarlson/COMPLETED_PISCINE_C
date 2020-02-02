/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 10:37:58 by jaleman           #+#    #+#             */
/*   Updated: 2016/08/25 10:37:59 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "ft_lib.h"

#define NONE	{ft_putstr("No such file or directory.\n"); return ;}
#define DIR		{ft_putstr(argv[1]);ft_putstr(": Is a directory.\n");return;}

void	ft_display_file(int argc, char **argv)
{
	int	file;

	if (argc == 2)
	{
		if (ft_strcmp(argv[1], ".") == 0 || ft_strcmp(argv[1], "/") == 0 ||
			ft_strcmp(argv[1], "..") == 0 || ft_strcmp(argv[1], "./") == 0 ||
			ft_strcmp(argv[1], "../") == 0)
			DIR;
		file = open(argv[1], O_RDONLY);
		if (file == -1)
			NONE;
		ft_display_stdin(file);
		close(file);
	}
	if (argc > 2)
		ft_putstr("Too many arguments.\n");
	if (argc < 2)
		ft_putstr("File name missing.\n");
}
