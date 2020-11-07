/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 00:43:53 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

void	ft_cat(int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		g_progname = basename(*argv);
		i = 0;
		while (++i < argc)
		{
			if (argv[i][0] == '-' && argv[i][1] == '\0')
				ft_stdin();
			else
				ft_display_file(argv[i]);
		}
	}
	else if (argc == 1)
		ft_stdin();
}