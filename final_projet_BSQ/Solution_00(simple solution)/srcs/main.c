/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:02:07 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/08/08 21:25:51 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

char	*g_progname;

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		i = 1;
		g_progname = argv[0];
		while (i < argc)
		{
			bsq(argv[i++]);
			if (i < argc)
				ft_putchar('\n');
		}
	}
	else
		ft_stdin();
	return (0);
}
