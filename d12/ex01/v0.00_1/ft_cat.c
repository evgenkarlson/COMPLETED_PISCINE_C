/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 22:51:41 by jaleman           #+#    #+#             */
/*   Updated: 2016/08/25 22:51:42 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_lib.h"

void	ft_set_program_name(char *argv0)
{
	char *slash;

	slash = 0;
	while (*argv0)
	{
		if (*argv0 == '/')
			slash = argv0;
		argv0++;
	}
	if (slash)
		g_progname = slash + 1;
	else
		g_progname = argv0;
}

void	ft_display_cat(int file, char *argv_x)
{
	int		r;
	char	buffer[BUF_SIZE + 1];

	while ((r = read(file, buffer, BUF_SIZE)))
	{
		if (r == -1)
		{
			ft_display_custom_error(errno, argv_x);
			return ;
		}
		buffer[r] = '\0';
		ft_putstr(buffer);
	}
}

int		main(int argc, char **argv)
{
	int	i;
	int	file;

	i = 0;
	ft_set_program_name(argv[0]);
	while (++i < argc)
	{
		if (argc < 2 || argv[i][0] == '-')
			ft_display_cat(1, argv[0]);
		if ((file = open(argv[i], O_RDONLY)) == -1)
			ft_display_custom_error(errno, argv[i]);
		if (file != -1)
			ft_display_cat(file, argv[i]);
		close(file);
	}
	return (0);
}
