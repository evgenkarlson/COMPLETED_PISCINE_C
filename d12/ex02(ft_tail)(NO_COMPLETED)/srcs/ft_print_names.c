/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_names.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

void	ft_print_names(int i, int argc, char **argv)
{
	int	j;

	j = 0;
	if (argc > 4)
	{
		if (i > 3)
			ft_putstr("\n==> ");
		else
			ft_putstr("==> ");
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		ft_putstr(" <==\n");
	}
}