/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 01:10:10 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

void	ft_print_name(int i, int argc, char *name)
{
	if (argc > 4)
	{
		if (i >= 4)
			ft_putstr("\n==> ");
		else
			ft_putstr("==> ");
		ft_putstr(name);
		ft_putstr(" <==\n");
	}
}