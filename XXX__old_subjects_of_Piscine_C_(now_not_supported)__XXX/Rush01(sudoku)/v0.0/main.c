/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 11:25:09 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/19 15:02:52 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		main(int argc, char **argv)
{
	if (check_grille(argv, argc))
	{
		if (sudoku(argv, 9))
			display(argv);
		else
		{
			ft_putstr("Error");
			ft_putchar('\n');
		}
	}
	else
	{
		ft_putstr("Error");
		ft_putchar('\n');
	}
	return (0);
}
